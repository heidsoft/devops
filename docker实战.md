#vagrant使用
```
vagrant up
vagrant run
gradle clean build
gradle bootRun
```

#Boot2Docker 用户密码
    默认的用户名和密码是：docker/tcuser 。摆脱cmd / 平台的困扰。

#配置docker 镜像仓库代理
	boot2docker ssh
	sudo su
	echo "EXTRA_ARGS=\"--registry-mirror=http://b22d3f91.m.daocloud.io\"" >> /var/lib/boot2docker/profile && exit
	exit
	boot2docker restart
#marathon
	marathon --master zk://127.0.0.1:2181,127.0.0.1:2181/mesos --zk zk://127.0.0.1:2181,127.0.0.1:2181/marathon
	
##启动mesos
```
systemctl stop 	 firewalld 
zookeeper-server start
systemctl start  mesos-master.service
systemctl start  mesos-slave.service
systemctl start  marathon.service
```

##通过marathon rest api创建app
```
[root@docker1 l2cloud]# curl -X POST http://192.168.16.59:8080/v2/apps -d basic-3.json -H "Content-type: application/json"
{"message":"Unrecognized token 'basic': was expecting ('true', 'false' or 'null')"}[root@docker1 l2cloud]# 
[root@docker1 l2cloud]# curl -X POST http://192.168.16.59:8080/v2/apps -d @basic-3.json -H "Content-type: application/json"
{"id":"/basic-3","cmd":"python3 -m http.server 8080","args":null,"user":null,"env":{},"instances":1,"cpus":0.5,"mem":32.0,"disk":0.0,"executor":"","constraints":[],"uris":[],"storeUrls":[],"ports":[0],"requirePorts":false,"backoffFactor":1.15,"container":{"type":"DOCKER","volumes":[],"docker":{"image":"python:3","network":"BRIDGE","portMappings":[{"containerPort":8080,"hostPort":0,"servicePort":0,"protocol":"tcp"}],"privileged":false,"parameters":[],"forcePullImage":false}},"healthChecks":[],"dependencies":[],"upgradeStrategy":{"minimumHealthCapacity":1.0,"maximumOverCapacity":1.0},"labels":{},"version":"2015-06-25T06:54:31.871Z","deployments":[{"id":"9125fc93-e76f-4e8c-92f6-159d3131646a"}],"tasks":[],"tasksStaged":0,"tasksRunning":0,"tasksHealthy":0,"tasksUnhealthy":0,"backoffSeconds":1,"maxLaunchDelaySeconds":3600}
[root@docker1 l2cloud]# 
```

##mesos管理docker
###mesos管理访问
	http://192.168.16.59:5050/#/
###文档参考
	http://mesosphere.github.io/marathon/docs/native-docker.html
	http://mesos.apache.org/documentation/latest/docker-containerizer/
###配置containerizers 
	这个参数很重要
	echo 'docker,mesos' > /etc/mesos-slave/containerizers
###配置executor_registration_timeout
	echo '5mins' > /etc/mesos-slave/executor_registration_timeout
###重启mesos-slave

###mesos配置dcoker 
####mesos-slave
	mesos-slave --containerizers=docker,mesos  --master=zk://127.0.0.1:2181,127.0.0.1:2181/mesos
###定义docker容器中的应用
	{
	  "id": "basic-5",
	  "cmd": "python3 -m http.server 8080",
	  "cpus": 0.5,
	  "mem": 32.0,
	  "container": {
		"type": "DOCKER",
		"docker": {
		  "network": "HOST",
		  "image": "43cdb7736341"
		},
		"volumes": [
		  {
			"containerPath": "/etc/a",
			"hostPath": "/var/data/a",
			"mode": "RO"
		  },
		  {
			"containerPath": "/etc/b",
			"hostPath": "/var/data/b",
			"mode": "RW"
		  }
		]
	  }
	}

##Kubernetes安装
###参考链接	
	http://blog.liuts.com/post/247/
	http://raftconsensus.github.io/
	https://github.com/ha/doozerd
	https://copr.fedoraproject.org/coprs/maxamillion/epel7-kubernetes/
	https://github.com/GoogleCloudPlatform/kubernetes/tree/master/www
###安装etcd
	curl -L  https://github.com/coreos/etcd/releases/download/v2.0.12/etcd-v2.0.12-linux-amd64.tar.gz -o etcd-v2.0.12-linux-amd64.tar.gz
	tar xzvf etcd-v2.0.12-linux-amd64.tar.gz
	cd etcd-v2.0.12-linux-amd64
	./etcd
	mkdir /data/etcd  
	./etcd -name etcdserver -data-dir /data/etcd -peer-bind-addr 0.0.0.0:7001 -bind-addr 0.0.0.0:4001
	./etcd -name etcdserver -peer-addr 192.168.5.12:7001 -addr 192.168.5.12:4001 -data-dir /data/etcd -peer-bind-addr 0.0.0.0:7001 -bind-addr 0.0.0.0:4001 &
###测试etcd
	curl -L http://127.0.0.1:4001/v2/keys/mykey -XPUT -d value="this is awesome"
###参考链接
	https://github.com/coreos/etcd/releases
###下载maxamillion-epel7-kubernetes-epel-7.repo
	curl	https://copr.fedoraproject.org/coprs/maxamillion/epel7-kubernetes/repo/epel-7/maxamillion-epel7-kubernetes-epel-7.repo -o /etc/yum.repos.d/maxamillion-epel7-kubernetes-epel-7.repo

```
	[root@localhost ~]# curl https://copr.fedoraproject.org/coprs/maxamillion/epel7-kubernetes/repo/epel-7/maxamillion-epel7-kubernetes-epel-7.repo -o /etc/yum.repos.d/maxamillion-epel7-kubernetes-epel-7.repo
	  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
									 Dload  Upload   Total   Spent    Left  Speed
	100   330  100   330    0     0      9      0  0:00:36  0:00:34  0:00:02    66
	[root@localhost ~]# cd /etc/yum.repos.d/
	[root@localhost yum.repos.d]# ls
	CentOS-Base.repo  CentOS-Debuginfo.repo  CentOS-Sources.repo  maxamillion-epel7-kubernetes-epel-7.repo
	CentOS-CR.repo    CentOS-fasttrack.repo  CentOS-Vault.repo
	[root@localhost yum.repos.d]# cat maxamillion-epel7-kubernetes-epel-7.repo 
	[maxamillion-epel7-kubernetes]
	name=Copr repo for epel7-kubernetes owned by maxamillion
	baseurl=http://copr-be.cloud.fedoraproject.org/results/maxamillion/epel7-kubernetes/epel-7-$basearch/
	skip_if_unavailable=True
	gpgcheck=1
	gpgkey=http://copr-be.cloud.fedoraproject.org/results/maxamillion/epel7-kubernetes/pubkey.gpg
	enabled=1
	[root@localhost yum.repos.d]# yum -y install kubernetes
	Loaded plugins: fastestmirror, langpacks
	base                                                                                              | 3.6 kB  00:00:00     
	extras                                                                                            | 3.4 kB  00:00:00     
	maxamillion-epel7-kubernetes                                                                      | 3.0 kB  00:00:00     
	updates                                                                                           | 3.4 kB  00:00:00     
	(1/5): extras/7/x86_64/primary_db                                                                 |  62 kB  00:00:01     
	(2/5): maxamillion-epel7-kubernetes/x86_64/primary_db                                             |  21 kB  00:00:02     
	(3/5): base/7/x86_64/group_gz                                                                     | 154 kB  00:00:02     
	(4/5): updates/7/x86_64/primary_db                                                                | 2.5 MB  00:00:05     
	(5/5): base/7/x86_64/primary_db                                                                   | 5.1 MB  00:00:15     
	Determining fastest mirrors
	 * base: ftp.sjtu.edu.cn
	 * extras: mirrors.skyshe.cn
	 * updates: ftp.stu.edu.tw
	Resolving Dependencies
	--> Running transaction check
	---> Package kubernetes.x86_64 0:0.17.1-4.el7 will be installed
	--> Processing Dependency: kubernetes-node = 0.17.1-4.el7 for package: kubernetes-0.17.1-4.el7.x86_64
	--> Processing Dependency: kubernetes-master = 0.17.1-4.el7 for package: kubernetes-0.17.1-4.el7.x86_64
	--> Running transaction check
	---> Package kubernetes-master.x86_64 0:0.17.1-4.el7 will be installed
	---> Package kubernetes-node.x86_64 0:0.17.1-4.el7 will be installed
	--> Processing Dependency: docker for package: kubernetes-node-0.17.1-4.el7.x86_64
	--> Running transaction check
	---> Package docker.x86_64 0:1.6.2-14.el7.centos will be installed
	--> Processing Dependency: docker-selinux >= 1.6.2-14.el7.centos for package: docker-1.6.2-14.el7.centos.x86_64
	--> Running transaction check
	---> Package docker-selinux.x86_64 0:1.6.2-14.el7.centos will be installed
	--> Processing Dependency: policycoreutils-python for package: docker-selinux-1.6.2-14.el7.centos.x86_64
	--> Running transaction check
	---> Package policycoreutils-python.x86_64 0:2.2.5-15.el7 will be installed
	--> Processing Dependency: libsemanage-python >= 2.1.10-1 for package: policycoreutils-python-2.2.5-15.el7.x86_64
	--> Processing Dependency: audit-libs-python >= 2.1.3-4 for package: policycoreutils-python-2.2.5-15.el7.x86_64
	--> Processing Dependency: python-IPy for package: policycoreutils-python-2.2.5-15.el7.x86_64
	--> Processing Dependency: libqpol.so.1(VERS_1.4)(64bit) for package: policycoreutils-python-2.2.5-15.el7.x86_64
	--> Processing Dependency: libqpol.so.1(VERS_1.2)(64bit) for package: policycoreutils-python-2.2.5-15.el7.x86_64
	--> Processing Dependency: libapol.so.4(VERS_4.0)(64bit) for package: policycoreutils-python-2.2.5-15.el7.x86_64
	--> Processing Dependency: checkpolicy for package: policycoreutils-python-2.2.5-15.el7.x86_64
	--> Processing Dependency: libqpol.so.1()(64bit) for package: policycoreutils-python-2.2.5-15.el7.x86_64
	--> Processing Dependency: libapol.so.4()(64bit) for package: policycoreutils-python-2.2.5-15.el7.x86_64
	--> Running transaction check
	---> Package audit-libs-python.x86_64 0:2.4.1-5.el7 will be installed
	---> Package checkpolicy.x86_64 0:2.1.12-6.el7 will be installed
	---> Package libsemanage-python.x86_64 0:2.1.10-16.el7 will be installed
	---> Package python-IPy.noarch 0:0.75-6.el7 will be installed
	---> Package setools-libs.x86_64 0:3.3.7-46.el7 will be installed
	--> Finished Dependency Resolution

	Dependencies Resolved

	=========================================================================================================================
	 Package                              Arch                 Version                            Repository            Size
	=========================================================================================================================
	Installing:
	 kubernetes                           x86_64               0.17.1-4.el7                       extras                19 k
	Installing for dependencies:
	 audit-libs-python                    x86_64               2.4.1-5.el7                        base                  69 k
	 checkpolicy                          x86_64               2.1.12-6.el7                       base                 247 k
	 docker                               x86_64               1.6.2-14.el7.centos                extras               7.6 M
	 docker-selinux                       x86_64               1.6.2-14.el7.centos                extras                55 k
	 kubernetes-master                    x86_64               0.17.1-4.el7                       extras                14 M
	 kubernetes-node                      x86_64               0.17.1-4.el7                       extras                11 M
	 libsemanage-python                   x86_64               2.1.10-16.el7                      base                  94 k
	 policycoreutils-python               x86_64               2.2.5-15.el7                       base                 434 k
	 python-IPy                           noarch               0.75-6.el7                         base                  32 k
	 setools-libs                         x86_64               3.3.7-46.el7                       base                 485 k

	Transaction Summary
	=========================================================================================================================
	Install  1 Package (+10 Dependent packages)

	Total download size: 35 M
	Installed size: 168 M
	Downloading packages:
	warning: /var/cache/yum/x86_64/7/base/packages/audit-libs-python-2.4.1-5.el7.x86_64.rpm: Header V3 RSA/SHA256 Signature, key ID f4a80eb5: NOKEY
	Public key for audit-libs-python-2.4.1-5.el7.x86_64.rpm is not installed
	(1/11): audit-libs-python-2.4.1-5.el7.x86_64.rpm                                                  |  69 kB  00:00:00     
	Public key for docker-selinux-1.6.2-14.el7.centos.x86_64.rpm is not installed          ]  0.0 B/s | 459 kB  --:--:-- ETA 
	(2/11): docker-selinux-1.6.2-14.el7.centos.x86_64.rpm                                             |  55 kB  00:00:00     
	(3/11): kubernetes-0.17.1-4.el7.x86_64.rpm                                                        |  19 kB  00:00:00     
	(4/11): libsemanage-python-2.1.10-16.el7.x86_64.rpm                                               |  94 kB  00:00:01     
	(5/11): policycoreutils-python-2.2.5-15.el7.x86_64.rpm                                            | 434 kB  00:00:02     
	(6/11): python-IPy-0.75-6.el7.noarch.rpm                                                          |  32 kB  00:00:00     
	(7/11): setools-libs-3.3.7-46.el7.x86_64.rpm                                                      | 485 kB  00:00:02     
	(8/11): checkpolicy-2.1.12-6.el7.x86_64.rpm                                                       | 247 kB  00:00:08     
	(9/11): kubernetes-master-0.17.1-4.el7.x86_64.rpm                                                 |  14 MB  00:01:11     
	(10/11): kubernetes-node-0.17.1-4.el7.x86_64.rpm                                                  |  11 MB  00:01:18     
	(11/11): docker-1.6.2-14.el7.centos.x86_64.rpm                                                    | 7.6 MB  00:01:23     
	-------------------------------------------------------------------------------------------------------------------------
	Total                                                                                    425 kB/s |  35 MB  00:01:23     
	Retrieving key from file:///etc/pki/rpm-gpg/RPM-GPG-KEY-CentOS-7
	Importing GPG key 0xF4A80EB5:
	 Userid     : "CentOS-7 Key (CentOS 7 Official Signing Key) <security@centos.org>"
	 Fingerprint: 6341 ab27 53d7 8a78 a7c2 7bb1 24c6 a8a7 f4a8 0eb5
	 Package    : centos-release-7-1.1503.el7.centos.2.8.x86_64 (@anaconda)
	 From       : /etc/pki/rpm-gpg/RPM-GPG-KEY-CentOS-7
	Running transaction check
	Running transaction test
	Transaction test succeeded
	Running transaction
	  Installing : audit-libs-python-2.4.1-5.el7.x86_64                                                                 1/11 
	  Installing : setools-libs-3.3.7-46.el7.x86_64                                                                     2/11 
	  Installing : checkpolicy-2.1.12-6.el7.x86_64                                                                      3/11 
	  Installing : kubernetes-master-0.17.1-4.el7.x86_64                                                                4/11 
	  Installing : libsemanage-python-2.1.10-16.el7.x86_64                                                              5/11 
	  Installing : python-IPy-0.75-6.el7.noarch                                                                         6/11 
	  Installing : policycoreutils-python-2.2.5-15.el7.x86_64                                                           7/11 
	  Installing : docker-selinux-1.6.2-14.el7.centos.x86_64                                                            8/11 
	  Installing : docker-1.6.2-14.el7.centos.x86_64                                                                    9/11 
	  Installing : kubernetes-node-0.17.1-4.el7.x86_64                                                                 10/11 
	  Installing : kubernetes-0.17.1-4.el7.x86_64                                                                      11/11 
	  Verifying  : kubernetes-0.17.1-4.el7.x86_64                                                                       1/11 
	  Verifying  : python-IPy-0.75-6.el7.noarch                                                                         2/11 
	  Verifying  : libsemanage-python-2.1.10-16.el7.x86_64                                                              3/11 
	  Verifying  : docker-selinux-1.6.2-14.el7.centos.x86_64                                                            4/11 
	  Verifying  : kubernetes-master-0.17.1-4.el7.x86_64                                                                5/11 
	  Verifying  : checkpolicy-2.1.12-6.el7.x86_64                                                                      6/11 
	  Verifying  : kubernetes-node-0.17.1-4.el7.x86_64                                                                  7/11 
	  Verifying  : setools-libs-3.3.7-46.el7.x86_64                                                                     8/11 
	  Verifying  : docker-1.6.2-14.el7.centos.x86_64                                                                    9/11 
	  Verifying  : policycoreutils-python-2.2.5-15.el7.x86_64                                                          10/11 
	  Verifying  : audit-libs-python-2.4.1-5.el7.x86_64                                                                11/11 

	Installed:
	  kubernetes.x86_64 0:0.17.1-4.el7                                                                                       

	Dependency Installed:
	  audit-libs-python.x86_64 0:2.4.1-5.el7                    checkpolicy.x86_64 0:2.1.12-6.el7                           
	  docker.x86_64 0:1.6.2-14.el7.centos                       docker-selinux.x86_64 0:1.6.2-14.el7.centos                 
	  kubernetes-master.x86_64 0:0.17.1-4.el7                   kubernetes-node.x86_64 0:0.17.1-4.el7                       
	  libsemanage-python.x86_64 0:2.1.10-16.el7                 policycoreutils-python.x86_64 0:2.2.5-15.el7                
	  python-IPy.noarch 0:0.75-6.el7                            setools-libs.x86_64 0:3.3.7-46.el7                          

	Complete!
	[root@localhost yum.repos.d]# 
```

####Kubernetes命令使用
###所有服务
```
   kube-apiserver.service
   kube-controller-manager.service
   kube-scheduler.service
   kubelet.service
   kube-proxy.service
```  
###启动master服务
```
在启动api-server前先启动etcd，且确保etcd的防火墙关闭，时其http能访问
systemctl daemon-reload
systemctl stop 	 firewalld 
systemctl start kube-apiserver.service kube-controller-manager.service kube-scheduler.service
systemctl enable kube-apiserver.service kube-controller-manager.service kube-scheduler.service

```
###启动控制节点服务
```
systemctl daemon-reload
systemctl stop 	 firewalld 
systemctl enable docker.service kubelet.service kube-proxy.service
systemctl start docker.service kubelet.service kube-proxy.service
systemctl stop docker.service kubelet.service kube-proxy.service
```
   
###kubectl
```
[root@localhost yum.repos.d]# /usr/bin/kubectl version
Client Version: version.Info{Major:"0", Minor:"17+", GitVersion:"v0.17.1-748-g01fcb58673001e", GitCommit:"01fcb58673001e56c69e128ab57e0c3f701aeea5", GitTreeState:"clean"}
Couldn't read version from server: Get http://localhost:8080/version: dial tcp 127.0.0.1:8080: connection refused
[root@localhost yum.repos.d]# 

[root@localhost yum.repos.d]# /usr/bin/kubectl --help
kubectl controls the Kubernetes cluster manager.

Find more information at https://github.com/GoogleCloudPlatform/kubernetes.

Usage: 
  kubectl [flags]
  kubectl [command]

Available Commands: 
  get            Display one or many resources
  describe       Show details of a specific resource
  create         Create a resource by filename or stdin
  update         Update a resource by filename or stdin.
  delete         Delete a resource by filename, stdin, resource and ID, or by resources and label selector.
  namespace      SUPERCEDED: Set and view the current Kubernetes namespace
  log            Print the logs for a container in a pod.
  rolling-update Perform a rolling update of the given ReplicationController.
  resize         Set a new size for a Replication Controller.
  exec           Execute a command in a container.
  port-forward   Forward one or more local ports to a pod.
  proxy          Run a proxy to the Kubernetes API server
  run-container  Run a particular image on the cluster.
  stop           Gracefully shut down a resource by id or filename.
  expose         Take a replicated application and expose it as Kubernetes Service
  label          Update the labels on a resource
  config         config modifies kubeconfig files
  cluster-info   Display cluster info
  api-versions   Print available API versions.
  version        Print the client and server version information.
  help           Help about any command

Flags:
      --alsologtostderr=false: log to standard error as well as files
      --api-version="": The API version to use when talking to the server
      --certificate-authority="": Path to a cert. file for the certificate authority.
      --client-certificate="": Path to a client key file for TLS.
      --client-key="": Path to a client key file for TLS.
      --cluster="": The name of the kubeconfig cluster to use
      --context="": The name of the kubeconfig context to use
  -h, --help=false: help for kubectl
      --insecure-skip-tls-verify=false: If true, the server's certificate will not be checked for validity. This will make your HTTPS connections insecure.
      --kubeconfig="": Path to the kubeconfig file to use for CLI requests.
      --log_backtrace_at=:0: when logging hits line file:N, emit a stack trace
      --log_dir=: If non-empty, write log files in this directory
      --log_flush_frequency=5s: Maximum number of seconds between log flushes
      --logtostderr=true: log to standard error instead of files
      --match-server-version=false: Require server version to match client version
      --namespace="": If present, the namespace scope for this CLI request.
      --password="": Password for basic authentication to the API server.
  -s, --server="": The address and port of the Kubernetes API server
      --stderrthreshold=2: logs at or above this threshold go to stderr
      --token="": Bearer token for authentication to the API server.
      --user="": The name of the kubeconfig user to use
      --username="": Username for basic authentication to the API server.
      --v=0: log level for V logs
      --validate=false: If true, use a schema to validate the input before sending it
      --vmodule=: comma-separated list of pattern=N settings for file-filtered logging


Use "kubectl help [command]" for more information about a command.
```

###查看service清单
```
[root@k8smaster kubernetes]# kubectl get pods 
POD       IP        CONTAINER(S)   IMAGE(S)   HOST      LABELS    STATUS    CREATED   MESSAGE
[root@k8smaster kubernetes]# kubectl get services
NAME            LABELS                                    SELECTOR   IP(S)        PORT(S)
kubernetes      component=apiserver,provider=kubernetes   <none>     10.254.0.2   443/TCP
kubernetes-ro   component=apiserver,provider=kubernetes   <none>     10.254.0.1   80/TCP
[root@k8smaster kubernetes]# 
```
###查看pods清单

```
[root@k8smaster kubernetes]# kubectl get pods
POD       IP        CONTAINER(S)   IMAGE(S)   HOST      LABELS    STATUS    CREATED   MESSAGE
[root@k8smaster kubernetes]# 
```

###查看replicationControllers清单
```
[root@k8smaster kubernetes]# kubectl get replicationControllers
CONTROLLER   CONTAINER(S)   IMAGE(S)   SELECTOR   REPLICAS
[root@k8smaster kubernetes]# 
```
###查看kubernetes版本
```
[root@k8smaster kubernetes]# curl -s -L http://192.168.5.16:8080/api/v1beta1/version
{
  "kind": "Status",
  "creationTimestamp": null,
  "apiVersion": "v1beta1",
  "status": "Failure",
  "message": "the server could not find the requested resource",
  "reason": "NotFound",
  "details": {},
  "code": 404
}[root@k8smaster kubernetes]# 
```

###查看pods清单
```
[root@k8smaster kubernetes]# curl -s -L http://192.168.5.16:8080/api/v1beta1/pods
{
  "kind": "PodList",
  "creationTimestamp": null,
  "selfLink": "/api/v1beta1/pods?namespace=",
  "resourceVersion": 16,
  "apiVersion": "v1beta1",
  "items": []
}
```
###查看replicationControllers清单
```
[root@k8smaster kubernetes]# curl -s -L http://192.168.5.16:8080/api/v1beta1/replicationControllers
{
  "kind": "ReplicationControllerList",
  "creationTimestamp": null,
  "selfLink": "/api/v1beta1/replicationControllers?namespace=",
  "resourceVersion": 18,
  "apiVersion": "v1beta1",
  "items": []
}
```

###Kubernetes配置Master主机
###
```
	go get -u github.com/jteeuwen/go-bindata/...
```

###查查看minion主机
```
[root@k8smaster kubernetes]# curl -s -L http://192.168.5.16:8080/api/v1beta1/minions
{
  "kind": "MinionList",
  "creationTimestamp": null,
  "selfLink": "/api/v1beta1/minions",
  "resourceVersion": 18,
  "apiVersion": "v1beta1",
  "items": []
}
```

###查看service清单
```
[root@k8smaster kubernetes]# curl -s -L http://192.168.5.16:8080/api/v1beta1/services
{
  "kind": "ServiceList",
  "creationTimestamp": null,
  "selfLink": "/api/v1beta1/services?namespace=",
  "resourceVersion": 18,
  "apiVersion": "v1beta1",
  "items": [
    {
      "id": "kubernetes",
      "creationTimestamp": null,
      "selfLink": "/api/v1beta1/services/kubernetes?namespace=default",
      "resourceVersion": 6,
      "namespace": "default",
      "port": 443,
      "protocol": "TCP",
      "containerPort": 443,
      "labels": {
        "component": "apiserver",
        "provider": "kubernetes"
      },
      "selector": null,
      "type": "ClusterIP",
      "portalIP": "10.254.0.2",
      "sessionAffinity": "None",
      "ports": [
        {
          "name": "",
          "protocol": "TCP",
          "port": 443,
          "containerPort": 443,
          "nodePort": 0
        }
      ],
      "loadBalancerStatus": {}
    },
    {
      "id": "kubernetes-ro",
      "creationTimestamp": null,
      "selfLink": "/api/v1beta1/services/kubernetes-ro?namespace=default",
      "resourceVersion": 8,
      "namespace": "default",
      "port": 80,
      "protocol": "TCP",
      "containerPort": 80,
      "labels": {
        "component": "apiserver",
        "provider": "kubernetes"
      },
      "selector": null,
      "type": "ClusterIP",
      "portalIP": "10.254.0.1",
      "sessionAffinity": "None",
      "ports": [
        {
          "name": "",
          "protocol": "TCP",
          "port": 80,
          "containerPort": 80,
          "nodePort": 0
        }
      ],
      "loadBalancerStatus": {}
    }
  ]
}

[root@localhost ~]# cd /etc/kubernetes/
[root@localhost kubernetes]# ls
apiserver  config  controller-manager  kubelet  proxy  scheduler
[root@localhost kubernetes]# ls -al
total 36
drwxr-xr-x.  2 root root  102 Jun 25 11:29 .
drwxr-xr-x. 99 root root 8192 Jun 25 11:27 ..
-rw-r--r--.  1 root root  727 Jun 23 21:32 apiserver
-rw-r--r--.  1 root root  655 Jun 23 21:32 config
-rw-r--r--.  1 root root  265 Jun 23 21:32 controller-manager
-rw-r--r--.  1 root root  466 Jun 23 21:32 kubelet
-rw-r--r--.  1 root root  103 Jun 23 21:32 proxy
-rw-r--r--.  1 root root  111 Jun 23 21:32 scheduler
[root@localhost kubernetes]# 
[root@localhost kubernetes]# vim config
###
# kubernetes system config
#
# The following values are used to configure various aspects of all
# kubernetes services, including
#
#   kube-apiserver.service
#   kube-controller-manager.service
#   kube-scheduler.service
#   kubelet.service
#   kube-proxy.service
# logging to stderr means we get it in the systemd journal
KUBE_LOGTOSTDERR="--logtostderr=true"

# journal message level, 0 is debug
KUBE_LOG_LEVEL="--v=0"

# Should this cluster be allowed to run privileged docker containers
KUBE_ALLOW_PRIV="--allow_privileged=false"

# How the controller-manager, scheduler, and proxy find the apiserver
KUBE_MASTER="--master=http://127.0.0.1:8080"
~                                               
```

###创建pod
```
[root@k8smaster opt]# kubectl create -f apache-pod.json
pods/fedoraapache
[root@k8smaster opt]# kubectl get pod
POD            IP        CONTAINER(S)   IMAGE(S)        HOST           LABELS              STATUS    CREATED     MESSAGE
fedoraapache                                            <unassigned>   name=fedoraapache   Pending   9 seconds   
                         fedoraapache   fedora/apache                                                            
[root@k8smaster opt]# 
```

##配置UI参数
```
[root@k8smaster config]# pwd
/opt/kubernetes-master/www/master/shared/config
[root@k8smaster config]# cat development.example.json 
{
  "k8sApiServer": "http://localhost:8080/api/v1beta3",
  "k8sDataServer": "",
  "k8sDataPollMinIntervalSec": 10,
  "k8sDataPollMaxIntervalSec": 120,
  "k8sDataPollErrorThreshold": 5,
  "cAdvisorProxy": "",
  "cAdvisorPort": "4194"
}
[root@k8smaster config]# 
```

##CloudStack与Docker
```
[root@dockerDemo ~]# docker pull docker.io/jdeathe/centos-ssh
Trying to pull repository docker.io/jdeathe/centos-ssh ...
b071db8f6e23: Error pulling image (latest) from docker.io/jdeathe/centos-ssh, Driver devicemapper failed to create image rootfs f1b10cd842498c23d206ee0cbeaa9de8d2ae09ff3c7af2723a9e337a6965d639: Error running DeviceCreate (createSnapDevice) dm_task_run failed reate (createSnapDevice) dm_task_run failed 
FATA[0188] Error pulling image (latest) from docker.io/jdeathe/centos-ssh, Driver devicemapper failed to create image rootfs f1b10cd842498c23d206ee0cbeaa9de8d2ae09ff3c7af2723a9e337a6965d639: Error running DeviceCreate (createSnapDevice) dm_task_run failed 
[root@dockerDemo ~]# 
```
##Docker存储
###docker使用逻辑卷做默认存储
```
docker 默认会创建逻辑卷/dev/centos/docker-pool,如果默认的逻辑太小，将导致docker pull image时无法下载
以下是默认逻辑卷太小出现的状态：
Jun 29 17:29:35 localhost lvm[526]: Thin centos-docker--pool is now 100% full.
Jun 29 17:29:35 localhost lvm[526]: Insufficient free space: 2 extents needed, but only 1 available
Jun 29 17:29:35 localhost lvm[526]: Failed to extend thin centos-docker--pool.
Jun 29 17:29:45 localhost lvm[526]: Thin centos-docker--pool is now 100% full.
Jun 29 17:29:45 localhost lvm[526]: Insufficient free space: 2 extents needed, but only 1 available
Jun 29 17:29:45 localhost lvm[526]: Failed to extend thin centos-docker--pool.
Jun 29 09:28:22 localhost chronyd[602]: Selected source 202.112.10.36
Jun 29 09:28:22 localhost chronyd[602]: System clock wrong by -28886.107288 seconds, adjustment started
Jun 29 09:28:22 localhost chronyd[602]: System clock was stepped by -28886.107 seconds

成功下载docker镜像出现的状态
Jun 30 01:11:29 localhost docker: time="2015-06-30T01:11:29-04:00" level=info msg="GET /v1.18/images/search?term=python"
Jun 30 01:11:29 localhost docker: time="2015-06-30T01:11:29-04:00" level=info msg="+job search(python)"
Jun 30 01:11:29 localhost docker: time="2015-06-30T01:11:29-04:00" level=info msg="+job resolve_repository(python)"
Jun 30 01:11:29 localhost docker: time="2015-06-30T01:11:29-04:00" level=info msg="-job resolve_repository(python) = OK (0)"
Jun 30 01:11:31 localhost docker: time="2015-06-30T01:11:31-04:00" level=info msg="-job search(python) = OK (0)"
Jun 30 01:11:38 localhost chronyd[637]: Selected source 202.118.1.130
Jun 30 01:11:59 localhost docker: time="2015-06-30T01:11:59-04:00" level=info msg="POST /v1.18/images/create?fromImage=docker.io%2Fwebhippie%2Fpython%3Alatest"
Jun 30 01:11:59 localhost docker: time="2015-06-30T01:11:59-04:00" level=info msg="+job pull(docker.io/webhippie/python, latest)"
Jun 30 01:11:59 localhost docker: time="2015-06-30T01:11:59-04:00" level=info msg="+job resolve_repository(docker.io/webhippie/python)"
Jun 30 01:11:59 localhost docker: time="2015-06-30T01:11:59-04:00" level=info msg="-job resolve_repository(docker.io/webhippie/python) = OK (0)"
Jun 30 01:12:09 localhost kernel: XFS (dm-5): Mounting V4 Filesystem
Jun 30 01:12:09 localhost kernel: XFS (dm-5): Ending clean mount
Jun 30 01:12:17 localhost kernel: XFS (dm-5): Mounting V4 Filesystem
Jun 30 01:12:18 localhost kernel: XFS (dm-5): Ending clean mount
Jun 30 01:12:25 localhost kernel: XFS (dm-5): Mounting V4 Filesystem
Jun 30 01:12:25 localhost kernel: XFS (dm-5): Ending clean mount
Jun 30 01:12:37 localhost kernel: XFS (dm-5): Mounting V4 Filesystem
Jun 30 01:12:38 localhost kernel: XFS (dm-5): Ending clean mount
Jun 30 01:13:18 localhost kernel: XFS (dm-5): Mounting V4 Filesystem
Jun 30 01:13:19 localhost kernel: XFS (dm-5): Ending clean mount
Jun 30 01:13:24 localhost kernel: XFS (dm-5): Mounting V4 Filesystem
Jun 30 01:13:24 localhost kernel: XFS (dm-5): Ending clean mount
Jun 30 01:13:31 localhost kernel: XFS (dm-5): Mounting V4 Filesystem
Jun 30 01:13:31 localhost kernel: XFS (dm-5): Ending clean mount
Jun 30 01:15:47 localhost kernel: XFS (dm-5): Mounting V4 Filesystem
Jun 30 01:15:48 localhost kernel: XFS (dm-5): Ending clean mount
Jun 30 01:15:53 localhost kernel: XFS (dm-5): Mounting V4 Filesystem
Jun 30 01:15:54 localhost kernel: XFS (dm-5): Ending clean mount
Jun 30 01:16:01 localhost kernel: XFS (dm-5): Mounting V4 Filesystem
Jun 30 01:16:02 localhost kernel: XFS (dm-5): Ending clean mount
Jun 30 01:16:02 localhost docker: time="2015-06-30T01:16:02-04:00" level=info msg="+job log(pull, docker.io/webhippie/python:latest, )"
Jun 30 01:16:02 localhost docker: time="2015-06-30T01:16:02-04:00" level=info msg="-job log(pull, docker.io/webhippie/python:latest, ) = OK (0)"
Jun 30 01:16:02 localhost docker: time="2015-06-30T01:16:02-04:00" level=info msg="-job pull(docker.io/webhippie/python, latest) = OK (0)"
```