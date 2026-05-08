#CloudStack研究#

##系统虚拟机密码
	 system虚拟机密码是:6m1ll10n

##挂载iso分析##
    http://192.168.150.16:8080/client/api?command=detachIso&virtualmachineid=f3a41b61-b974-4862-91d3-b08bd90fadf5&response=json&sessionkey=zcuUSQsElfxVqrIkZVHuLQysrbk%3D&_=1379821531308   
    http://192.168.150.16:8080/client/api?command=listNetworks&id=d2c86456-a53a-488e-ad66-24fd2dc18038&response=json&sessionkey=zcuUSQsElfxVqrIkZVHuLQysrbk%3D&_=1379821534488  
    http://192.168.150.16:8080/client/api?command=listOsTypes&response=json&sessionkey=zcuUSQsElfxVqrIkZVHuLQysrbk%3D&_=1379821534706  
    http://192.168.150.16:8080/client/api?command=listTags&response=json&sessionkey=zcuUSQsElfxVqrIkZVHuLQysrbk%3D&resourceId=f3a41b61-b974-4862-91d3-b08bd90fadf5&resourceType=UserVm&listAll=true&_=1379821534738  
    http://192.168.150.16:8080/client/api?command=listVirtualMachines&id=f3a41b61-b974-4862-91d3-b08bd90fadf5&response=json&sessionkey=zcuUSQsElfxVqrIkZVHuLQysrbk%3D&_=1379821534651  
    http://192.168.150.16:8080/client/api?command=listZones&id=47afc991-cf8b-4804-9929-cbff1b39639c&response=json&sessionkey=zcuUSQsElfxVqrIkZVHuLQysrbk%3D&_=1379821534451  
    http://192.168.150.16:8080/client/api?command=queryAsyncJobResult&jobId=a36b20b2-fd29-4c58-8046-0fd652707761&response=json&sessionkey=zcuUSQsElfxVqrIkZVHuLQysrbk%3D&_=1379821534390  
    http://192.168.150.16:8900/client/api?command=queryAsyncJobResult&jobId=a36b20b2-fd29-4c58-8046-0fd652707761&response=json  

##CloudStack4.3API开发指南##

##CloudStack 概念
	什么是 CloudStack
	CloudStack? 是一个软件平台，可将计算资源集中在一起以构建公共、私有和混合基础设施即服务(IaaS)云。
	CloudStack? 负责管理组成云基础架构的网络、存储和计算节点。
	使用 CloudStack? 可以部署、管理和配置云计算环境。
	
	CloudStack? 通过扩展商用硬件上运行的每个虚拟机映像的范围，
	提供了一个实时可用的云基础架构软件堆栈用于以服务方式交付虚拟数据中心，
	即交付构建、部署和管理多层次和多租户云应用程序必需的所有组件。
	开源版本和 Premium 版本都已可用，且提供的功能几乎完全相同。
	
	添加一个区域
	什么是区域?
	区域是 CloudStack? 部署中最大的组织单位。
	虽然允许一个数据中心中存在多个区域，但是一个区域通常与一个数据中心相对应。
	将基础架构编组到区域中的好处是可以提供物理隔离和冗余。
	例如，每个区域都可以拥有各自的电源供应和网络上行方案，
	并且各区域可以在地理位置上相隔很远(虽然并非必须相隔很远)。
	
	区域中的dns1：这些服务器是供此区域中的来宾vm使用的dns服务器，将通过
	您稍后要添加的公共网络进行访问，此区域的公共ip地址必须路由到在此处指定
	的dns服务器。
	
	
	
	添加一个提供点
	什么是提供点?
	一个提供点通常代表一个机架。
	同一提供点中的主机位于同一子网中。
	
	提供点是 CloudStack? 部署中的第二大组织单位。
	提供点包含在区域中。每个区域中可以包含一个或多个提供点；
	在基本安装中，您的区域中将仅包含一个提供点。
	
	ip 范围：此为cloudstack用于管理辅助存储vm和控制台代理vm的专用网络
	中的ip范围，这些ip地址来自与计算服务器相同的子网
	
	添加来宾网络
	ip 范围：能够分配给此区域中的来宾的ip地址范围，如果使用一个NIC，这些
	ip应位于提供点cidr相同的cidr中
	
	
	添加一个群集
	什么是群集?
	群集提供了一种编组主机的方法。
	群集中的所有主机都具有相同的硬件，
	运行相同的虚拟机管理程序，
	位于同一子网中，并访问相同的共享存储。
	可以实时将虚拟机实例(VM)从一台主机迁移到同一群集内的其他主机，
	而无需中断向用户提供服务。
	群集是 CloudStack? 部署中的第三大组织单位。
	群集包含在提供点中，提供点包含在区域中。
	
	CloudStack? 允许云部署中存在多个群集，但对于基本安装，我们只需要一个群集。
	
	
	添加一个主机
	什么是主机?
	主机是指一台计算机。
	主机提供运行来宾虚拟机的计算资源。
	每台主机上都安装有虚拟机管理程序软件，
	用于管理来宾 VM (裸机主机除外，
	将在“高级安装指南”中讨论这一特殊案例)。
	例如，启用了 KVM 的 Linux 服务器、
	Citrix XenServer 服务器和 ESXi 服务器都可用作主机。
	在基本安装中，我们将使用一台运行 XenServer 的主机。
	
	主机是 CloudStack? 部署中最小的组织单位。主机包含在群集中，群集包含在提供点中，提供点包含在区域中。
	
	
	添加一个主存储
	什么是主存储?
	CloudStack? 云基础架构使用以下两种类型的存储: 主存储和辅助存储。
	这两种类型的存储可以是 iSCSI 或 NFS 服务器，也可以是本地磁盘。
	
	主存储与群集相关联，用于存储该群集中的主机上正在运行的所有 VM 对应的每个来宾 VM 的磁盘卷。
	主存储服务器通常位于靠近主机的位置。

##Cloudstack的iptables配置
	1.1 手动执行如下命令：
	iptables -I INPUT -m state --state NEW -p tcp --dport 80 -j ACCEPT
	iptables -I INPUT -m state --state NEW -p tcp --dport 8080 -j ACCEPT
	iptables -I INPUT -m state --state NEW -p tcp --dport 8096 -j ACCEPT
	iptables -I INPUT -m state --state NEW -p tcp --dport 8250 -j ACCEPT
	1.2 在/etc/sysconfig/iptables中的COMMIT前，添加如下内容：
	-I INPUT -m state --state NEW -p tcp --dport 80 -j ACCEPT
	-I INPUT -m state --state NEW -p tcp --dport 8080 -j ACCEPT
	-I INPUT -m state --state NEW -p tcp --dport 8096 -j ACCEPT
	-I INPUT -m state --state NEW -p tcp --dport 8250 -j ACCEPT

