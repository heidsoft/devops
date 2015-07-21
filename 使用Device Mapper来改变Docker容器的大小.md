#使用 Device Mapper来改变Docker容器的大小
```
如果在 CentOS 、 REHL 、 Fedor 或者其他默认没有 AUFS 支持的 Linux 发行版上使用 Docker ，你可能需要用到 Device Mapper 的存储插件。将这个插件设置为默认，它会把你所有的容器存储到一个 100G 的简短文件中，并且限制每个容器最大为 10GB 。这篇文章将展示如何突破这个限制，并且把容器的存储移动到一个指定的分区或者 LVM 卷中。

它的工作原理

要真正理解我们要做的事情，首先来了解 Device Mapper 插件的工作原理。

它是基于 Device Mapper 的“精简目标”的特性。它实际上是目标块设备的快照，之所以被称为“精简”是因为它允许精简配置。精简配置意味着你有一个（希望很大）可用存储块的池，接着你可以从那个池中创建任意大小的块设备（虚拟磁盘，如有需要）；在你实际读写后，这些存储块将会被标记为已使用（或者从池中拿走）。

这意味着你是可以超额使用这个池，比如在一个 100GB 的池里面创建几千个 10GB 的卷，甚至可能是一个 100TB 的卷在一个 1GB 的池里面。只要你的实际读写的块的容量不大于池的大小，你怎么做都 OK 。

除此之外，精简目标的方式是可以做快照的。这表明无论何时，你都可以创建一个存在的卷的浅拷贝。在用户看来，就像你有两个一样的卷，它们可以独立地各自修改。即使你做了一个完整的拷贝，除了在时间上它是瞬间发生的（即使是很大的卷），它们不会两次重复使用存储。额外的存储只有当其中任何一卷有变化的时候才会发生，然后精简目标会从池里面分配一个存储快。

从本质上来看，“精简目标”实际上使用了两个存储设备：一个（大）的是存储块池自己，还有一个小的存储了一些元数据。这些元数据中包括了卷、快照、以及每个卷的块或者快照同存储池中块的映射信息。

当 Docker 使用 Device Mapper 存储插件的时候，它会在 /var/lib/docker/devicemapper/devicemapper/data 和/var/lib/docker/devicemapper/devicemapper/metadata 下创建两个文件（如果它们不存在）来存储对应的存储池和相关的元数据。这非常方便，你不需要做任何安装部署的工作（你不需要额外的分区来存储 Docker 容器，或者建立 LVM 或其他类似的东西）。然而它也有两个缺点：

－ 存储池会有一个默认 100GB 的容量
－ 它将会被稀疏文件所支持。从磁盘的使用效率的观点来看，这还不错的（就像在精简池中的卷，它一开始是小的，只有当实际需要写的时候才会使用磁盘的存储块）。但是从性能的角度来看就不那么好了，因为 VFS 增加了一些额外的负担，特别是"第一次写的时候"。
在了解如何调整容器的大小之前，我们来试试看如何给池增加更多空间。

我们需要一个更大的池

警告 : 下面的操作会删除你所有的容器和镜像，确保你已经把之前的数据做了备份！

记住上面说过的，当数据和元类信息文件不存在的时候 Docker 会创建它们，所以解决方案非常简单：在启动它们之前，在 Docker 里创建这些文件！

停止 Docker 守护进程，因为我们将要重新设置我们的存储插件，如果我们在运行的时候移除文件，那么糟糕的事情就将发生。

擦去 /var/lib/docker 。 警告：正如前面提到的，这个操作会把你所有的容器和镜像都删除掉。

创建存储目录： mkdir -p /var/lib/docker/devicemapper/devicemapper

创建你的池： dd if=/dev/zero of=/var/lib/docker/devicemapper/devicemapper/data bs=1G count=0 seek=250 ，创建一个 250G 的稀疏文件。如果你指定 bs=1G count=250（不使用 seek 选项），那么它会创建一个普通文件（而不是一个稀疏文件）。

重启 Docker 守护进程。提示：在默认情况下，如果你有 AUFS 的支持， Docker 会使用它；所以如果你要强制使用 Device Mapper 的插件，需要在启动 Docker 的命令中增加 -s devicemapper 的选项。

使用 docker info 来检查 Data Space Total 的值是否正确。

我们需要一个更快的池

警告 ：下面的操作也会删除你所有的容器和镜像。确保把你重要的镜像保存在 registry 中，保存你容器里面的重要数据。

要获得一个更快速的池，最简单的办法就是使用一个真实的设备而不是一个基于文件的循环设备。过程几乎一样。假设你有一个完全空的硬盘， /dev/sdb，你想把它完全用于容器的存储，你可以这样做：

停止 Docker 守护进程
移除 /var/lib/docker （似曾相识，对么？）
创建一个存储目录： mkdir -p /var/lib/docker/devicemapper/devicemapper
在目录下创建一个数据软链接，指向设备： ln -s /dev/sdb /var/lib/docker/devicemapper/devicemapper/data
重启 Docker
使用 docker info 来检查 Data Space Total 的值是否正确
使用 RAID 和 LVM

如果你希望合并多块相似的磁盘，可以使用 RADID10 软件，这个会通过链接到 /dev/md 而实现。另外一个非常好的选择是把你的磁盘（或者RAID磁盘阵列）放到 LVM 的物理卷中，并且创建两个逻辑卷：一个是数据，一个是元数据。对于元数据池的最佳的大小我没有什么特别的建议，不过占数据池的 1% 看起来不错。

就像前面一样，停止 Docker ，移除它的数据目录，然后创建一个指向 /dev/mapper 设备的符号链接，然后重启 Docker 。

如果你需要更多关于 LVM 的知识，请看这里 LVM howto 。

扩容容器

默认来说，如果你使用 Device Mapper 的存储插件，所有的镜像和容器是从一个初始 10G 的文件系统中创建的。让我们来看看如何从一个更大的文件系统中创建一个容器。

首先，我们用 Ubuntu 的镜像来创建我们的容器。我们不需要在这个容器里运行任何东西，只需要这个文件（或者关联的文件系统）存在。为了演示，我们会在这个容器里运行 df ，来看一下根文件系统的大小。

$ docker run -d ubuntu df -h / 
4ab0bdde0a0dd663d35993e401055ee0a66c63892ba960680b3386938bda3603 
由于需要修改 Device Mapper 管理中的一些卷的信息，我们现在用 root 的身份来运行一些命令。所有以＃开头的命令都必须以 root 身份来执行。只要能访问 Docker 的 Socket 服务，你也可以用普通用户的身份来执行其他的命令（以$开头）。

让我们看一下 /dev/mapper ，那里应该有一个对应容器文件系统的符号链接，以 docker-X:Y-Z- 开头：

# ls -l /dev/mapper/docker-*-4ab0bdde0a0dd663d35993e401055ee0a66c63892ba960680b3386938bda3603 
lrwxrwxrwx 1 root root 7 Jan 31 21:04 /dev/mapper/docker-0:37-1471009-4ab0bdde0a0dd663d35993e401055ee0a66c63892ba960680b3386938bda3603 -> ../dm-8 
注意记住那个全名，我们未来会用到。

首先让我们来看一下当前卷的信息表：

# dmsetup table docker-0:37-1471009-4ab0bdde0a0dd663d35993e401055ee0a66c63892ba960680b3386938bda3603 
0 20971520 thin 254:0 7 
第二个数字是设备的大小，表示有多少个 512－bytes 的扇区. 这个值略高于 10GB 的大小。

我们来计算一下一个 42GB 的卷需要多少扇区，

$ echo $((42*1024*1024*1024/512)) 
88080384 
精简快照目标的一个神奇的特点是它不会限制卷的大小。当你创建它的时候，一个精简的卷使用0个块，当你开始往块里面写入的时候，它们会从共用的块池中进行分配。你可以写0个块，或者是10亿个块，这个和精简快照目标没关系。文件系统的大小只和 Device Mapper 表有关系。

觉得困惑？不要担心。我们只是需要装载一个新的表，这个完全和之前的是一样的，但是有更多的扇区。仅此而已。

旧表是 0 20971520 thin 254:0 7 。我们会改变第二个数字，要非常小心保持其他的值不变。你的卷可能不是 7 ，所以要使用正确的值!

这样操作：

# echo 0 88080384 thin 254:0 7 | dmsetup load docker-0:37-1471009-4ab0bdde0a0dd663d35993e401055ee0a66c63892ba960680b3386938bda3603 
现在如果我们再次检查表的信息，步骤和前面一样。首先使用下面的命令激活新表:

# dmsetup resume docker-0:37-1471009-4ab0bdde0a0dd663d35993e401055ee0a66c63892ba960680b3386938bda3603 
执行完命令后，再次检查一下表的信息，发现它会使用新的扇区数量。

我们已经调整了块设备的大小，但是我们仍然需要调整文件系统的大小，我们使用 resize2fs 来操作:

# resize2fs /dev/mapper/docker-0:37-1471009-4ab0bdde0a0dd663d35993e401055ee0a66c63892ba960680b3386938bda3603 
resize2fs 1.42.5 (29-Jul-2012) 
Filesystem at /dev/mapper/docker-0:37-1471009-4ab0bdde0a0dd663d35993e401055ee0a66c63892ba960680b3386938bda3603 is mounted on /var/lib/docker/devicemapper/mnt/4ab0bdde0a0dd663d35993e401055ee0a66c63892ba960680b3386938bda3603; on-line resizing required 
old_desc_blocks = 1, new_desc_blocks = 3 
The filesystem on /dev/mapper/docker-0:37-1471009-4ab0bdde0a0dd663d35993e401055ee0a66c63892ba960680b3386938bda3603 is now 11010048 blocks long 
作为一个可选步骤，我们会重启容器，检查一下我们的确有了正确大小的空闲空间:

$ docker start 4ab0bdde0a0dd663d35993e401055ee0a66c63892ba960680b3386938bda3603 
$ docker logs 4ab0bdde0a0dd663d35993e401055ee0a66c63892ba960680b3386938bda3603 
df: Warning: cannot read table of mounted file systems: No such file or directory 
Filesystem Size Used Avail Use% Mounted on 
- 9.8G 164M 9.1G 2% / 
df: Warning: cannot read table of mounted file systems: No such file or directory 
Filesystem Size Used Avail Use% Mounted on 
- 42G 172M 40G 1% / 
想把整个过程自动化起来？当然没问题。

CID=$(docker run -d ubuntu df -h /) 
DEV=$(basename $(echo /dev/mapper/docker-*-$CID)) 
dmsetup table $DEV | sed "s/0 [0-9]* thin/0 $((42*1024*1024*1024/512)) thin/" | dmsetup load $DEV 
dmsetup resume $DEV 
resize2fs /dev/mapper/$DEV 
docker start $CID 
docker logs $CID 
扩容镜像

不幸的是，当前版本的 Docker 不能让我们很方便地扩容镜像。你可以把镜像对应的块设备进行扩容，然后从它来创建一个容器，但是新的容器不会有正确的大小。

同样，如果你提交了一个很大的容器，最后生成的镜像也不会很大（这是由 Docker 为镜像准备文件系统的方法造成的）。

这意味着如果一个容器真的超过了 10GB ，在不使用一些其他的小技巧的情况下，你没法正确的把它提交为一个镜像。

总结

Docker 将来肯定会提供一些更好的方法来扩容容器，所需的代码变动是很小的。管理一个精简的池和对应的元信息比较复杂（因为这个需要很多不同的操作流程，以及一个潜在的数据迁移。鉴于移除了所有的东西来构件新的池，也就没有在本文提及），但是我们今天提到的一些解决方案相信已经对你有所帮助。

老样子，如果你有问题或者评论，马上在 IRC 上 ping 我（ jpetazzo on Freenode ），或是通过 Twitter (@jpetazzo) 和我联系。

原文出自:http://www.cnblogs.com/feisky/p/4106004.html
```