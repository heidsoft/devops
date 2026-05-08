一、Operation and maintenance problems

1、在cloudstack中如何手动设置虚拟机的IP，而不用系统路由分配.
How to manually set the virtual machine's IP in cloudstack , not use  vrout
6228481770663625918 陈玉燕 800 b32n
2、在cloudstack 中如何实现对虚拟机的克隆？
How to clone a virtual machine in the cloudstack?

3、如在cloudstack 中实现第三方硬件设备的集成，比如负载均衡或交换机等
How to integrat the third-party hardware devices  in cloudstack, such as load balancing or switches.

4.cloudstack对制作模板时，windows PV操作系统的模板无法识别为何种版本的操作系统类型，如：windows 2003等
In cloudstack, make a template for windows PV operating system can not be identified as to what version of the operating system types, such as: windows 2003.etc.

5.cloudstack 如果要实现虚拟机的hostname，支持中文命名，大概方式是？
cloudstack If you want to achieve the hostname of the virtual machine to support the Chinese name, probably way?

6.cloudstack 4.2  在使用kvm做hpervisor时，对虚拟机快照功能不支持，那么cloudstack 后续版本会支持？
cloudstack 4.2 when using kvm do hpervisor, virtual machine snapshot feature is not supported, then cloudstack subsequent versions will support?

7.cloudstack对虚拟机名字修改不支持，目前仅支持初次安装虚拟机更改hostname.
cloudstack name for the virtual machine does not support the modification, currently only supports the initial installation of the virtual machine to change hostname

8.cloudstack+kvm的高可用，开源版无法支持,如果要自己实现，大概思路是？能解释下cloudstack 实现高可用的原理？
cloudstack + kvm highly available, open source version can not support. if I want to achieve, probably thinking is? Cloudstack achieve high availability can explain the principle?

9.Cloudstack的高级网络中虚拟路由器如何在生产环境大流量中使用.
Cloudstack senior network virtual router how to use in a production environment in a large flow?

10.Cloudstack stored using
   clvm方案在较大的磁盘卷（20-50G）中，会造成磁盘堵塞，从而触发clvm集群重启物理机，造成物理主机无法处于正常工作状态。
clvm program in the larger disk volume (20-50G), the disk will cause congestion, thereby triggering a cluster restart clvm physical machine, causing physical host can not be in normal working condition.
   
   Ceph在cloudstack的使用中是否稳定可行，具体配置该如何做？.
   Ceph in cloudstack whether the use of stable and feasible, the specific configuration of what to do?

11.Cloudstack管理端的高可用使用经验，官方提供的mysql主从方案是否靠谱?
Cloudstack end high availability management experience, mysql official from the main program is reliable?

二、Development issues
1、cloudstack mvn 在使用第三方包时，应该如何配置，比如vmware
In cloudstack mvn when using a third-party package, how to configure, such as vmware

2、cloudstack 中，如果要自己实现相关命令，需要做哪些配置动作，需要继承哪些类，实现哪些接口呢？
In cloudstack, if you want to achieve the relevant commands yourself, what needs to be done to configure the action, which classes need to inherit, which interfaces to achieve it?

3、cloudstack 中，如果要自己生成系统虚拟机文件，应该如何配置？
In cloudstack, if you want to generate a virtual machine file system yourself, how to configure?

4、cloudstack 中，网络服务提供商，具体有什么作用，现实意义大？它是不是接入物理设备的接口？
In cloudstack, the network service providers, specifically what role, significance big? It is not a physical device access interface?

5、cloudstack 中，域一般怎么使用，只是用于多用户？
In cloudstack in general how to use the domain, but only multi-user?

6、cloudstack 中，目前监控功能的集成好实现？比如像OpenStack 中就集成Niagos
cloudstack, the current monitoring capabilities to achieve better integration? For example, in respect of the integration Niagos like OpenStack

7、cloudstack 中，高级网络和基础网络的区别在哪里？高级网络的拓扑架构是怎样的。
In cloudstack, the difference between the advanced network and infrastructure networks where? Advanced network topologies is like.

8、cloudstack 中，生产网络虚拟机的流量如何控制？
In cloudstack, the flow of the production network virtual machine how to control?

9、cloudstack 中的多租户是如何做到的呢？
In cloudstack in multi-tenant is how to do it?

10、cloudstack 中，模板架构有什么讲究？比如数据库操作目前采用DButils,为什么不用Hibernate呢？
In cloudstack, the template structure what about? For example, database operations currently used DButils, why not Hibernate it?

11、cloudstack 4.3 大概什么时候发布？未来cloudstack 的发展方向如何？
What about when cloudstack 4.3 release? How cloudstack's future direction?

12、cloudstack 目前生态圈发展的如何？有哪些可集成的产品？
How cloudstack currently developing ecosystem? Which can be integrated product?

13、OpenStack 和 CloudStack 两大平台，你觉得将来谁将更胜一筹？
OpenStack and CloudStack two platforms, do you think the future who will be even better?



