#Libvirt

##下载
	git clone git://libvirt.org/libvirt.git  
	or
	ftp://libvirt.org/libvirt/
##安装
 	 $ gunzip -c libvirt-x.x.x.tar.gz | tar xvf -
     $ cd libvirt-x.x.x
     $ ./configure

##开发
###对象模型
####hypervisor连接
	virConnectPrt
####Guest Domains
	domain代表一个运行的虚拟机或是一个用来创建虚拟机的配置
	virDomainPtr
######唯一标识符号
	ID:
	name:
	UUID:
####虚拟网络
	virNetworkPtr
######唯一标识符号
	name:
	UUID:
####存储池
	virStoragePoolPtr
######唯一标识符号
	name:
	UUID:
####存储卷
######唯一标识符号
	key:
	path:
####主机设备
###驱动模型
	Xen: xen:///
	QEMU: qemu:///session
	UML: uml:///session
	OpenVZ: openvz:///system
	LXC: lxc:///
###远程管理
	libvirt-qpid项目提供了一个agent  为QPid消息服务
	libvirt-CIM项目提供了CIM agent
	libvirt 对象模型遵循DMTF 虚拟化schema
#####基本使用
#####数据传输
	tls  协议:端口16514
	tcp
	unix 
	ssh
	ext
#####认证
	sasi
	polkit
	x509
###连接
	virConnectPtr virConnectOpen(const char *name);//打开链接
	virConnectPtr virConnectOpenReadOnly(const char *name); //
	virConnectPtr virConnectOpenAuth(const char* name, virConnectAuthPtr auth, int flag);

##参考资料
- http://libvirt.org/downloads.html
- http://www.ibm.com/developerworks/linux/library/os-python-kvm-scripting1/index.html?ca=dat
- https://help.ubuntu.com/10.04/serverguide/libvirt.html
- http://www.ibm.com/developerworks/library/l-libvirt/
- http://cloud.dzone.com/news/libvirt-for-fog
- http://www.cppblog.com/LIULIANG/archive/2012/05/22/175822.html
- http://fr2.rpmfind.net/linux/RPM/centos/updates/6.5/x86_64/Packages/libvirt-devel-0.10.2-29.el6.1.i686.html
- http://docs.fedoraproject.org/en-US/Fedora_Draft_Documentation/0.1/html-single/Virtualization_Deployment_and_Administration_Guide/index.html
- http://www.virtualopensystems.com/
- ftp://ftpeng.cisco.com/openstack/cisco/pkgs/libvirt/docs/java.html.in
- http://www.informit.com/articles/article.aspx?p=1867761&seqNum=3
- http://libvirt.org/java.html
- http://www.dedoimedo.com/computers/kvm-storage.html
