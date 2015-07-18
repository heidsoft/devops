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
##扩展Docker默认存储的逻辑卷大小
```
前提是centos 卷组拥有容量，可用vgdisplay显示
lvresize -L 5G centos /dev/centos/docker-pool
```
##挂在新逻辑卷到opt
```
cloudstack kvm的虚拟机默认使用virtio作为磁盘驱动，新加的磁盘标记是:/dev/vd[a-z]
格式化磁盘:fdisk /dev/vda ，先选择p,然后选择n,在选择p,然后默认，然后选择分区t,然后选择8e<表示lvm>,然后选择w
将新分区的磁盘，做成物理卷:pvcreate /dev/vda1
扫描一下当前系统的，卷组：vgdisplay
将新创建的物理卷，放到卷组中:vgextend centos /dev/vda1
然后可以创建新的逻辑卷，或者扩充已有的逻辑卷容量：
lvcreate -L 5G centos
mount /dev/mapper/centos-lvol1 /opt
```
##Docker搭建Registry  
```
	若果使用http需要docker启动参数加入:--insecure-registry=10.1.1.166:5000 
	将 /opt/data/registry设置为存储私有仓库的目录，扩大opt的空间：
	lvcreate -L 5G centos
	mkfs.ext4 /dev/centos/lvol1 
	mount /dev/centos/lvol1 /opt/
	mkdir -p  /opt/data/registry
	
	docker run -d -p 5000:5000 -v /opt/data/registry:/tmp/registry docker.io/registry 
	docker run -d -p 5000:5000 docker.io/registry 
	docker pull busybox
	docker push 10.1.1.166:5000/busybox
```

##私有仓库镜像的查询
```
curl http://10.1.1.166:5000/v1/search
```
##上传镜像到私有仓库
```
docker pull 10.1.1.166:5000/busybox 
```

##保存Docker的镜像
```
[root@dockerRegistry ~]# docker save 10.1.1.166:5000/busybox > ./busybox.tar.gz
[root@dockerRegistry ~]# ls
anaconda-ks.cfg  busybox.tar.gz
[root@dockerRegistry ~]# 
```

##导出Docker的容器
```
docker tag docker.io/dockerui/dockerui  10.1.1.166:5000/dockerui
先从公共仓库拉取一个Image
[root@dockerRegistry opt]# docker pull docker.io/dockerui/dockerui         
[root@dockerRegistry opt]# docker images
保存拉取到本地镜像为文件
[root@dockerRegistry opt]# docker save docker.io/dockerui/dockerui > dockerui.tar.gz
删除掉本地的images列表中
[root@dockerRegistry opt]# docker rmi docker.io/dockerui/dockerui
导入本地镜像
[root@dockerRegistry opt]# docker load < ./dockerui.tar.gz  
注意进行tag标记时，镜像的仓库位置必须正确如：10.1.1.166:5000/[镜像名称]
[root@dockerRegistry opt]# docker tag docker.io/dockerui/dockerui  10.1.1.166:5000/dockerui
将本地镜像推送到私有仓库
[root@dockerRegistry opt]# docker push  10.1.1.166:5000/dockerui
The push refers to a repository [10.1.1.166:5000/dockerui] (len: 1)
Sending image list
Pushing repository 10.1.1.166:5000/dockerui (1 tags)
8260944ecb7d: Image successfully pushed 
70d943b8199f: Image successfully pushed 
337b54cfbd39: Image successfully pushed 
9ac79962b9b0: Image successfully pushed 
Pushing tag for rev [9ac79962b9b0] on {http://10.1.1.166:5000/v1/repositories/dockerui/tags/latest}
[root@dockerRegistry opt]# 
```
##按条件检索私有仓库镜像
```
[root@dockerRegistry opt]# curl -X GET http://10.1.1.166:5000/v1/search?q=dockerui
{"num_results": 1, "query": "dockerui", "results": [{"description": "", "name": "library/dockerui"}]}[root@dockerRegistry opt]# 
[root@dockerRegistry opt]# 
```
##下载私有仓库的镜像
```
[root@dockerHost ~]# docker pull 10.1.1.166:5000/busybox 
Trying to pull repository 10.1.1.166:5000/busybox ...
8c2e06607696: Download complete 
cf2616975b4a: Download complete 
6ce2e90b0bc7: Download complete 
Status: Downloaded newer image for 10.1.1.166:5000/busybox:latest
[root@dockerHost ~]# docker images
REPOSITORY                TAG                 IMAGE ID            CREATED             VIRTUAL SIZE
<none>                    <none>              8509607578d1        12 days ago         233.5 MB
<none>                    <none>              f1b10cd84249        9 weeks ago         0 B
docker.io/hello-world     latest              91c95931e552        10 weeks ago        910 B
10.1.1.166:5000/busybox   latest              8c2e06607696        10 weeks ago        2.43 MB
[root@dockerHost ~]# 

[root@dockerHost ~]# docker pull 10.1.1.166:5000/dockerui
Trying to pull repository 10.1.1.166:5000/dockerui ...
9ac79962b9b0: Download complete 
8260944ecb7d: Download complete 
70d943b8199f: Download complete 
337b54cfbd39: Download complete 
Status: Downloaded newer image for 10.1.1.166:5000/dockerui:latest
[root@dockerHost ~]# docker images
REPOSITORY                 TAG                 IMAGE ID            CREATED             VIRTUAL SIZE
<none>                     <none>              8509607578d1        13 days ago         233.5 MB
10.1.1.166:5000/dockerui   latest              9ac79962b9b0        5 weeks ago         5.422 MB
<none>                     <none>              f1b10cd84249        10 weeks ago        0 B
docker.io/hello-world      latest              91c95931e552        10 weeks ago        910 B
10.1.1.166:5000/busybox    latest              8c2e06607696        10 weeks ago        2.43 MB
[root@dockerHost ~]# 
```

##Rest API 
##开启rest服务的参数
```
--selinux-enabled --registry-mirror=http://b22d3f91.m.daocloud.io -H tcp://0.0.0.0:8888 -H unix:///var/run/docker.sock

[root@localhost ~]# curl 'http://127.0.0.1:8888/images/json?all=0'
[{"Created":1429308098,"Id":"91c95931e552b11604fea91c2f537284149ec32fff0f700a4769cfd31d7696ae","Labels":{},"ParentId":"a8219747be10611d65b7c693f48e7222c0bf54b5df8467d3f99003611afa1fd8","RepoDigests":[],"RepoTags":["docker.io/hello-world:latest"],"Size":0,"VirtualSize":910}
][root@localhost ~]# 
[root@localhost ~]# 
[root@localhost ~]# ps -ef|grep docker
root       3873      1  0 05:17 ?        00:00:00 /usr/bin/docker -d --selinux-enabled --registry-mirror=http://b22d3f91.m.daocloud.io -H tcp://0.0.0.0:8888 -H unix:///var/run/docker.sock
root       3992   2775  0 05:19 pts/0    00:00:00 grep --color=auto docker
[root@localhost ~]# 
```

##创建镜像
```
post  application/json
http://192.168.16.14:8888/v1/images/create?fromImage=hello-world&tag=latest
http://docs.docker.com/reference/api/remote_api_client_libraries/
http://17173ops.com/2014/10/13/docker%E5%9F%BA%E7%A1%80%E4%B8%8E%E9%AB%98%E7%BA%A7.shtml
```

##compose安装
```
(官方链接)[！http://docs.docker.com/compose/install/]
```
```
Compose可以让用户在集群中部署分布式应用。简单的说，Docker Compose属于一个“应用层”的服务，
用户可以定义哪个容器组运行哪个应用，它支持动态改变应用，并在需要时扩展。
使用Compose的第一步是使用YAML文件来定义容器应用的状态：

containers:
web:
 build: .
 command: python app.py
 ports:
 - "5000:5000"
 volumes:
 - .:/code
 links:
 - redis
 environment:
 - PYTHONUNBUFFERED=1
redis:
 image: redis:latest
 command: redis-server --appendonly yes
 
上面的YAML文件定义了两个容器应用，第一个容器运行Python应用，
并通过当前目录的Dockerfile文件构建。第二个容器是从DockerHub注册中心的Redis官方仓库中构建。
links指令用来定义依赖，意思是Python应用依赖于Redis应用。
定义完成后，通过下面的命令来启动应用：docker-compose up
```

```
curl -L https://github.com/docker/compose/releases/download/1.3.2/docker-compose-`uname -s`-`uname -m` > /usr/local/bin/docker-compose
chmod +x /usr/local/bin/docker-compose

pip install -U docker-compose==1.3.2
```


#基于源码构建私有仓库
```
[root@localhost ~]# cd docker-registry/
[root@localhost docker-registry]# ls
ADVANCED.md   circle.yml  CONTRIBUTING.md  Dockerfile       FAQ.md       README.md     setup.cfg  tox.ini
AUTHORS       config      DEBUGGING.md     docker_registry  LICENSE      requirements  setup.py
CHANGELOG.md  contrib     depends          DRIVERS.md       MANIFEST.in  scripts       tests
[root@localhost docker-registry]# 

[root@localhost docker-registry]# docker build -t "heidsoft-registry" .
Sending build context to Docker daemon 
FATA[0000] Post http:///var/run/docker.sock/v1.18/build?cgroupparent=&cpusetcpus=&cpushares=0&dockerfile=Dockerfile&memory=0&memswap=0&rm=1&t=heidsoft-registry: dial unix /var/run/docker.sock: no such file or directory. Are you trying to connect to a TLS-enabled daemon without TLS? 
[root@localhost docker-registry]# systemctl start dcoker
Failed to issue method call: Unit dcoker.service failed to load: No such file or directory.
[root@localhost docker-registry]# systemctl start docker
```

```
成功在本地通过源码构建了镜像仓库，总共经历了12步:
@....start 
building 'markupsafe._speedups' extension
    x86_64-linux-gnu-gcc -pthread -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -fPIC -I/usr/include/python2.7 -c markupsafe/_speedups.c -o build/temp.linux-x86_64-2.7/markupsafe/_speedups.o
    x86_64-linux-gnu-gcc -pthread -shared -Wl,-O1 -Wl,-Bsymbolic-functions -Wl,-Bsymbolic-functions -Wl,-z,relro -fno-strict-aliasing -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes -D_FORTIFY_SOURCE=2 -g -fstack-protector --param=ssp-buffer-size=4 -Wformat -Werror=format-security build/temp.linux-x86_64-2.7/markupsafe/_speedups.o -o build/lib.linux-x86_64-2.7/markupsafe/_speedups.so
Successfully installed docker-registry backports.lzma blinker Flask gevent gunicorn PyYAML requests M2Crypto sqlalchemy bugsnag Flask-cors newrelic Werkzeug Jinja2 itsdangerous greenlet webob markupsafe
Cleaning up...
 ---> bb135fe1c419
Removing intermediate container 5561b2fef818
Step 8 : RUN patch  $(python -c 'import boto; import os; print os.path.dirname(boto.__file__)')/connection.py  < /docker-registry/contrib/boto_header_patch.diff
 ---> Running in bc90ae3350bb
patching file /usr/local/lib/python2.7/dist-packages/boto/connection.py
 ---> c4fc4bf464b2
Removing intermediate container bc90ae3350bb
Step 9 : ENV DOCKER_REGISTRY_CONFIG /docker-registry/config/config_sample.yml
 ---> Running in fc182d9daed0
 ---> 9b16c0a3aaf8
Removing intermediate container fc182d9daed0
Step 10 : ENV SETTINGS_FLAVOR dev
 ---> Running in ebae054b90fb
 ---> 1b4a1e134805
Removing intermediate container ebae054b90fb
Step 11 : EXPOSE 5000
 ---> Running in 648f41896bbf
 ---> c3736b5cf3ab
Removing intermediate container 648f41896bbf
Step 12 : CMD docker-registry
 ---> Running in 3af3b4d0c90c
 ---> 80aa76e58d06
Removing intermediate container 3af3b4d0c90c
Successfully built 80aa76e58d06
@...end

进入到源码目录的config目录
# cp config/config_sample.yml /opt/data/registry/config.yml
# vi /opt/data/registry/config.yml
#这里可以设置本地存储
* SETTINGS_FLAVOR=dev，local 
* STORAGE_PATH:/tmp/registry等

```
error:
docker run -d -v /opt/data/registry:/tmp/registry -p 5000:5000 -e DOCKER_REGISTRY_CONFIG=/tmp/config.yml heidsoft-registry

ok:
后台运行
docker run  -d --privileged -e SETTINGS_FLAVOR=dev -e STORAGE_PATH=/opt/registry -v /db/docker-images:/opt/registry -p 5000:5000 heidsoft-registry 
有console运行
docker run  -i -t --privileged -e SETTINGS_FLAVOR=dev -e STORAGE_PATH=/opt/registry -v /db/docker-images:/opt/registry -p 5000:5000 heidsoft-registry /bin/bash

但不加--privileged 启动容器时 push镜像到仓库会报权限错误
将已有镜像重新标记为一个新的镜像，名称是liubin-registry
docker tag 80aa76e58d06 heidsoft.registry:5000/liubin-registry
docker push heidsoft.registry:5000/liubin-registry 

从私服上搜索存在哪些可用镜像
curl -X GET http://heidsoft.registry:5000/v1/search
docker tag 80aa76e58d06 heidsoft.registry:5000/liubin-registry

加入认证环境
wget  http://nginx.org/packages/centos/7/noarch/RPMS/nginx-release-centos-7-0.el7.ngx.noarch.rpm
rpm -ivh nginx-release-centos-7-0.el7.ngx.noarch.rpm 
yum install nginx
wget -c soft.vpser.net/lnmp/ext/htpasswd.sh
创建两个登录用户
[root@heidsoft ~]# ./htpasswd.sh -c /etc/nginx/docker-registry.htpasswd heidsoft
=====================================
# A tool like htpasswd for Nginx    #
#-----------------------------------#
# Author:Licess http://www.lnmp.org #
=====================================
Please input UserName:heidsoft
===========================
UserName was: heidsoft
===========================
Please input the Password:heidsoft
===========================
Password was: heidsoft
===========================
Please input Auth filename:heidsoft
===========================
Auth File: /usr/local/nginx/conf/heidsoft
===========================

[root@heidsoft ~]#  ./htpasswd.sh -c /etc/nginx/docker-registry.htpasswd liubin
=====================================
# A tool like htpasswd for Nginx    #
#-----------------------------------#
# Author:Licess http://www.lnmp.org #
=====================================
Please input UserName:liubin
===========================
UserName was: liubin
===========================
Please input the Password:liubin
===========================
Password was: liubin
===========================
Please input Auth filename:liubin
===========================
Auth File: /usr/local/nginx/conf/liubin
===========================

Press any key to Creat...or Press Ctrl+c to cancel
Create Auth file......
./htpasswd.sh: line 64: /usr/local/nginx/conf/liubin.conf: No such file or directory
Create Auth file successful,auth file path:/usr/local/nginx/conf/liubin.conf.
[root@heidsoft ~]# 

nginx 错误日志

```
curl http://liubin:liubin@heidsoft.registry:8080/v1/search
2015/07/18 06:58:24 [crit] 35545#0: *1 connect() to 127.0.0.1:5000 failed (13: Permission denied) while connecting to upstream, client: 192.168.1.6, server: heidsoft.registry, request: "GET /v1/search HTTP/1.1", upstream: "http://127.0.0.1:5000/v1/search", host: "heidsoft.registry:8080"
2015/07/18 06:58:24 [crit] 35545#0: *1 connect() to [::1]:5000 failed (13: Permission denied) while connecting to upstream, client: 192.168.1.6, server: heidsoft.registry, request: "GET /v1/search HTTP/1.1", upstream: "http://[::1]:5000/v1/search", host: "heidsoft.registry:8080"
```

临时关闭selinux后能根据认证文件请求到
```
setenforce 0
curl http://liubin:liubin@heidsoft.registry:8080/v1/search
```

```
docker启动失败

[root@heidsoft log]# tailf messages 
Jul 18 07:17:06 localhost docker: time="2015-07-18T07:17:06-04:00" level=info msg="-job acceptconnections() = OK (0)"
Jul 18 07:17:06 localhost docker: time="2015-07-18T07:17:06-04:00" level=info msg="Daemon has completed initialization"
Jul 18 07:17:06 localhost systemd: Started Docker Application Container Engine.
Jul 18 07:18:03 localhost systemd: Starting Docker Storage Setup...
Jul 18 07:18:03 localhost docker-storage-setup: Metadata volume docker-poolmeta already exists. Not creating a new one.
Jul 18 07:18:03 localhost docker-storage-setup: Internal error: Unable to create new logical volume with no extents.
Jul 18 07:18:03 localhost systemd: docker-storage-setup.service: main process exited, code=exited, status=5/NOTINSSTALLED
Jul 18 07:18:03 localhost systemd: Failed to start Docker Storage Setup.
Jul 18 07:18:03 localhost systemd: Unit docker-storage-setup.service entered failed state.
Jul 18 07:18:03 localhost systemd: Started Docker Application Container Engine.

去掉--storage-opt dm.no_warn_on_loop_devices=true  参数启动成功，奇怪了
```

```
2015/07/18 07:22:37 [crit] 36084#0: *4060 open() "/etc/nginx/docker-registry.htpasswd.conf" failed (24: Too many open files), client: 192.168.1.6, server: heidsoft.registry, request: "GET /v1/users/ HTTP/1.0", host: "heidsoft.registry:8080"
ulimit -n 30000

```










```




#容器存储问题

```
1、容器间的链接：

运行一个容器，给它一个名称，例如：


docker run -d -p 0.0.0.0:4455:22 -p 0.0.0.0:8080:80 --name one centos6-ssh
再运行另一个容器


docker run -d -p 0.0.0.0:4456:22 -p 0.0.0.0:8088:80 --link /one:two centos6-ssh2 env
说明：

/one:two 

one是第一个容器的名称，two是第二个容器的名称，

env是打印出来 第二个容器的环境变量

这样两容器就建立起一个网络通道，one和two容器所开放的端口也就是Dockerfile文件中定义开放的端口就可以连通了，

在宿主机上使用iptables命令来查看，例如：

iptables -L -n
Chain FORWARD (policy ACCEPT)
target     prot opt source               destination         
ACCEPT     tcp  --  172.17.1.28          172.17.1.29         tcp spt:3306 
ACCEPT     tcp  --  172.17.1.29          172.17.1.28         tcp dpt:3306 
ACCEPT     tcp  --  172.17.1.28          172.17.1.29         tcp spt:22 
ACCEPT     tcp  --  172.17.1.29          172.17.1.28         tcp dpt:22
从这里看到两个容器间端口可以互相的访问了，

说明：

这里的端口是以one这个容器所开放的端口，如one开放22，3306，而two容器只开放了22，在two上也会放3306给one，反之就不行了。--link是以连接容器开放的端口为准的。

2、Docker 容器下数据卷的理解

一个数据卷就是经过特殊设计的,在一个或多个容器中通过UFS文件系统提供的一些特性 

实现数据持久化或共享.

数据卷可以在容器之间共享和重复利用

可以对数据卷里的内容直接进行修改

对镜像的更新不会改变数据卷的内容

卷会一直持续到没有容器使用他们

2.1、添加一个数据卷

可以使用带有 -v 参数的 docker run 命令给容器添加一个数据卷.

docker run -d -p 0.0.0.0:4445:22 --name data -v /data centos6-ssh
这个在容器里就会有一个/data的卷

在Dockefile中使用VOLUME指令来创建添加一个或多个数据卷

2.2、挂载宿主文件夹到数据卷

使用-v参数也可以挂载宿主的文件夹到容器里


docker run -d -p 0.0.0.0:44455:22 --name data1 -v /src/data:/opt/data centos6-ssh
这样会把本地的/src/data文件夹挂在容器/opt/data目录

宿主机上的文件夹必须是绝对路径，而且当文件夹不存在时会自动创建

此功能在Dockerfile文件中无法使用

默认情况下Docker以读写权限挂载数据卷,但是我们也可以以只读方式进行挂载

docker run -d -p 0.0.0.0:44455:22 --name data1 -v /src/data:/opt/data:ro centos6-ssh
还是上面的那个命令，只是我们添加了一个ro选项来制定挂载时文件权限应该是只读的

2.3、创建和挂在一个数据卷容器

如果一些数据需要在容器间共享最好的方式来创建一个数据卷容器，然后从数据卷容器中挂载数据

  1\创建一个带有命名容器来共享数据


 docker run -d -v /dbdata --name dbdata centos6-ssh
  2\在另一个容器中使用--volumes-from标记挂在/dbdata卷

docker run -d --volumes-from dbdata --name db1 centos6-ssh2
  3\在另一个容器中同时也挂载/dbdata卷

docker run -d --volumes-from dbdata --name db2 centos6-ssh3


可以使用多个 -–volumes-from 参数来把多个容器中的多个数据卷放到一起

 可以挂载通过挂载dbdata容器实现的容器db1和db2来扩展关系链,例如：

docker run -d --name db2 --volumes-from db1 centos6-ssh4

2.4、备份，恢复，迁移数据

使用它们来进行备份,恢复或迁移数据.如下所示,我们使用 

–volumes-from 标记来创建一个挂载了要备份数据卷的容器.

docker run --volumes-from dbdata -v $(pwd):/backup centos6-ssh tar cvf /backup/backup.tar /dbdata
这里我们创建并登录了一个新容器，挂载了dbdata容器中的数据卷，并把本地的一个目录挂载了/backup下，最后再传一条tar命令来备份dbdata卷到/backup下，当命令执行完成后容器就会停止运行，并保留dbdata的备份，在本地目录下会一个备份的文件

注：新创建的容器中要有tar命令，

得到备份数据就可以恢复或迁移数据了
```
#问题

1.如何在Docker容器内外互相拷贝数据?

```
#从容器内拷贝文件到主机上
docker cp <containerId>:/file/path/within/container /host/path/target 

#用-v挂载主机数据卷到容器内
docker run -v /path/to/hostdir:/mnt $container  
在容器内拷贝  
cp /mnt/sourcefile /path/to/destfile  
``` 

2.直接在主机上拷贝到容器物理存储系统
```
docker inspect -f '{{.id}}' 9e3671679c8c 
```