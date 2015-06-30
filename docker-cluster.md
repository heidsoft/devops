#docker主流集群
```
---------------------------------------------------------------
项目名称	描述	语言	部署难度	开发难度	
fleet	调度器和集群管理工具
				
marathon	调度器和集群管理工具
				
Swarm	调度器和集群管理工具
				
mesos	宿主机抽象服务，用于为调度器联合宿主机资源
				
kubernetes	一个管理容器组的工具，具有先进的调度能力
				
compose	一个用于创建容器组的容器编排工具
----------------------------------------------------------------

fleet: 调度器和集群管理工具
marathon:调度器和集群管理工具
Swarm:调度器和集群管理工具
	
mesos:宿主机抽象服务，用于为调度器联合宿主机资源
	Mesos适用于任何的框架和应用
kubernetes:一个管理容器组的工具，具有先进的调度能力
	Kubernetes主要针对容器集群
	
compose:一个用于创建容器组的容器编排工具
```

##启动swarm调度器
```
docker pull swarm
docker run --rm swarm create
docker -H tcp://0.0.0.0:2375 -d
docker run -d swarm join --addr=172.31.40.100:2375 token://6856663cdefdec325839a4b7e1de38e8
docker -H tcp://0.0.0.0:2375 info

TLS
安全传输层协议（TLS）用于在两个通信应用程序之间提供保密性和数据完整性,
该协议由两层组成:TLS 记录协议（TLS Record）和 TLS 握手协议（TLS Handshake）.

返回集群ID是:306b334010485b30e77f27d28f316918
```

##启动node
```
docker -H tcp://0.0.0.0:2375 -d   
 -d use daemon mode start
 -H 表示daemon socket(s) to connect to 
 socket INADDR_ANY 监听0.0.0.0地址 socket只绑定端口让路由表决定传到哪个ip
 其中INADDR_ANY就是指定地址为0.0.0.0的地址,这个地址事实上表示不确定地址,或“所有地址”、“任意地址”。
```

##将node加入
```
docker run -d swarm join --addr=192.168.16.59:2375 token://306b334010485b30e77f27d28f316918
289a280681c23c2d84da04458ad3cc431a0d2b9eeca10b24f9a845b37b417567
```
