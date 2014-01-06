#CloudStack学习与研究#

* system虚拟机密码是:6m1ll10n
* 
##cloudstack社区活动会议总结##
1、cloudstack 版本发布情况
resource tags
2、4.2支持ipv6
3、数据卷通常只用于扩大

4.2
vmsync improvement
storage subsystem2.0  (很容易支持第三方存储扩张)
cpu & ram overcommit 和动态扩张
vm 快照
hyper-v 支持
syslog enhancement,

安全组 in adv zone
vm disk IO throttling

弹性扩张
xenMotion

4.3
LXC
PVLAN
VXLAN



模板下载不下来
console问题

系统虚拟机
占用用户的物理资源
精简高效
对最终用户透明
高可用性
无状态
可线性扩张


CPVM (web vnc console 后端) (默认50个seesion)
每一个zone至少一个
网络配置
public 
control
management
自动扩展

ssvm
实现二级存储相关功能
每个zone至少一个
网络配置
public
control
management
storage


vr
实现网络相关功能
DHCP/DNS/防火墙
端口转发NAT
负载均衡
VPN
VPC
每个网络至少一个
网络配置
public adv
control
guest

ssvm 中有java进程 启动后会与mgnt通信


系统虚拟机模板
debian linux7.0  64bit
只装的工具,sshd,apache,iptables,ipsec,haproxy 
SSH 通过3922访问
预装jre

所有的系统虚拟机使用同一个模板
不同hypervisor 不同的模板


如何制作标准系统虚拟机
virtulbox veewee 
下载debian7.0
根据预定义的参数安装
更新debian
copy各类cs的shell脚本系统内
后续工作，建账户，chkconfig等
转换为其他格式
ova,qcow2等

如何为虚拟机虚拟机打patch
单独升级某个工具，软件
模板作为卷挂载到vm
mount,chroot
升级所需的软件
卸载卷，创建为模板
替换系统虚拟机模板
更新数据库，删除template_spoof_ref表中的systemVm
删除所有虚拟机虚拟机

系统虚拟机初始化
CPVM/SSVM/VR创建时使用相同的模板
启动后管子systemVm.iso 或者patchdisk(KVM)
通过boot cmdline 向vm传入参数,e.g
type=secstorage
vm启动时检测参数，根据类型的不同
从systemvm.iso拷贝不同的文件
配置对应的网络
启动相应的服务

system vm 初始化
authorized_key,mgmt server 访问 systemVm 的ssh key
cloud_script.tgz 各类shell脚本，主要是vr使用
systemvm.zip包括cpvm和ssvm的agent jar
cpvm 和ssvm的agent java进程启动后，会连接mgmnt server 8250,创建成功后,agent state up

CPVM work flow
1、用户发起请求道mgmt server,查看web console
mgmt server选择合适的cpvm 返回public ip
用户访问CPVM
CPVM 向mgmt server发请求进行验证
验证通过后，CPVM访问VM所在的hypervisor对应的端口,获取console信息
经过CPVM转换为浏览器能渲染的格式

SSVM 工作流
1、用户上传模板请求到mgmt server
2、mgmt srv 选择合适的ssvm,发送命备份快照
3、ssvm 通过外网nic下载执行的模板
4、ssvm调用esxi vc api 导出虚拟机快照卷为ovf
5、ssvm通过storeage network mount 上二级存储，写入快照


VM 工作流
1、用户发起快照请求道mgmt server ，例如添加端口转发
2、mgmt srv 选择合适的vr,通过control network 发送命令，

CPVM 证书问题，realhost ip 

job/build

ssvm 和cpvm 根据负载情况自动scale up
consoleproxy.capactiy.standy  待机session数量


quick cloud
cpvm ssvm作为单独运行的程序，可以在其他机器上，例如mgmt -sr
