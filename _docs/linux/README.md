# _docs/linux

> Linux 系统与虚拟化：libvirt / vagrant / 内核

---

## 📄 笔记文件

| 文件 | 说明 |
|------|------|
| `vagrant使用.md` | **⭐ 原创** vagrant 常用命令速查（box/init/up/halt/reload/destroy/package/provision） |
| `内核启动过程.md` | Linux 内核启动流程：start_kernel() → trap_init() → init_IRQ() → rest_init() |
| `内核编译.md` | 内核编译步骤：make config / make menuconfig / make defconfig / make oldconfig |
| `ubuntu-rabbitmq-install/install.md` | Ubuntu 安装 RabbitMQ 步骤 |
| `libvirt/libvirt.md` | libvirt 下载/安装/对象模型（hypervisor连接/guest domains） |

---

## Vagrant 常用命令速查

| 命令 | 说明 |
|------|------|
| `vagrant box list` | 查看已安装 box |
| `vagrant init` | 初始化新环境 |
| `vagrant up` | 启动虚拟机 |
| `vagrant halt` | 关机 |
| `vagrant reload` | 重启 |
| `vagrant destroy` | 销毁 |
| `vagrant package` | 打包为 box |
| `vagrant provision` |  provisioning |
| `vagrant connect` | 连接远程共享环境 |

**box 下载地址：** http://www.vagrantbox.es/

---

*最后更新：2026-05-09*
