# _docs/devops

> DevOps 核心实践：容器化、K8s、微服务、Spring、鉴权

---

## 📄 笔记文件

| 文件 | 说明 |
|------|------|
| `docker实战.md` | **⭐ 核心文档** Docker/Mesos/K8S/Marathon 实战安装运维日志，含 2015 年生产环境操作记录 |
| `docker-cluster.md` | Docker 主流集群方案对比（fleet 等） |
| `Dockerfile.md` | Dockerfile SSH 镜像模板 |
| `Docker功能点.md` | Docker 操作清单（镜像/容器/网络） |
| `Docker容器规范.md` | 容器规范 v1 |
| `Docker镜像规范.md` | 镜像规范 v1.0.0 |
| `docker实战.md` | Boot2Docker/Marathon/K8S 安装运维命令 |
| `pod.md` | K8s Pod 生命周期与钩子 |
| `使用Device Mapper来改变Docker容器的大小.md` | Device Mapper 扩容 |
| `mesos-slave命令介绍.md` | Mesos slave 命令 |
| `Spring.md` | Spring MVC TEST |
| `commons-pool实战.md` | **⭐ 原创代码** GenericObjectPool 连接池详解+完整Java示例 |
| `Golang.md` | Go 语言变量声明 |
| `UML精粹.md` | UML 类图关系 |
| `ITIL_v3_学习.md` | ITIL v3 持续服务改进 |
| `OAuth开发与集成.md` | OAuth 踩坑：NoSuchMethodError |
| `OAuth 2 开发人员指南.md` | OAuth2 开发指南 |
| `AI-DevOps/README.md` | AI-DevOps 智能运维 |

---

## 📁 子目录

### docker/ （Docker PDF 教程，20+ 篇）

主要资料：
- Docker Getting Start Related Knowledge.pdf — 入门知识
- Docker Tutorial Series Part 1 — Docker 入门教程
- 深入理解 Docker 网络与 Pipework 源码解读
- 基于 kubernetes 构建 Docker 集群管理详解
- 《Go语言编程》高清完整版电子书
- LXC 常用命令介绍
- Microservices.pdf
- Pipework/Weave/Flannel 对比
- 私有 Registry 搭建教程
- Remote API client libraries

### k8s/ （Kubernetes 资料）

- Kubernetes应用部署模型解析（原理篇）.pdf
- Kubernetes应用部署模型解析（部署篇）.pdf
- 基于kubernetes构建Docker集群管理详解.pdf
- k8s-master.png / k8s-proxy.png / etcd-runing-info.png

### Spring/ 

- Spring Security.md — Spring Security 笔记

### mvn/

- maven实践.md — Maven 实战

### paas/

- PaaS-migration.pdf — PaaS 迁移白皮书
- CCRA 4.0 Overview — 云认证参考
- Real-time-Quality-in-Clouds.pdf — 云质量
- SGCertifiedTechnicalArchitect.pdf — 认证架构师
- modelsforhierarchicaldata — 层级数据模型

### aufs2-base5/

- AuFS2 内核补丁 for 2.6.27
- aufs2-util/ — 工具源码（C 语言）

### union-file-system/

- Linux AuFS Examples 教程
- Union file systems 实现对比（LWN）
- Ubuntu AuFS Root Filesystem on USB Flash

### dockerui/

- dockerui.md — Docker UI 界面使用说明
- 截图 1-5.png

---

## 🔥 docker实战.md 精华摘要

**Marathon + Mesos 部署：**
```bash
# 启动 mesos + marathon
marathon --master zk://127.0.0.1:2181/mesos --zk zk://127.0.0.1:2181/marathon

# 通过 Marathon REST API 创建 app
curl -X POST http://192.168.16.59:8080/v2/apps -d @basic-3.json -H "Content-type: application/json"

# mesos-slave 容器化配置
echo 'docker,mesos' > /etc/mesos-slave/containerizers
echo '5mins' > /etc/mesos-slave/executor_registration_timeout
mesos-slave --containerizers=docker,mesos --master=zk://.../mesos
```

**K8S 早期版本安装（v0.17）：**
```bash
# 安装 etcd
./etcd -name etcdserver -data-dir /data/etcd -peer-bind-addr 0.0.0.0:7001

# master 节点服务
systemctl start kube-apiserver kube-controller-manager kube-scheduler

# minion 节点服务  
systemctl start docker kubelet kube-proxy

# kubectl 查看资源
kubectl get pods / kubectl get services / kubectl get replicationControllers
```

**私有 Registry 部署：**
```bash
# 构建registry镜像
docker build -t "heidsoft-registry" .
# 启动（需 --privileged）
docker run -d --privileged -e SETTINGS_FLAVOR=dev -v /db/docker-images:/opt/registry -p 5000:5000 heidsoft-registry

# push/pull
docker tag 80aa76e58d06 heidsoft.registry:5000/liubin-registry
docker push heidsoft.registry:5000/liubin-registry
curl -X GET http://heidsoft.registry:5000/v1/search
```

**Docker 存储问题排查：**
```
# thin pool 100% 满的解决
lvresize -L 5G centos /dev/centos/docker-pool

# 扩容 /opt
lvcreate -L 5G centos
mount /dev/mapper/centos-lvol1 /opt
```

---

## commons-pool 精华

连接池配置三种场景：

| 配置 | maxActive | maxIdle | maxWait | 效果 |
|------|-----------|---------|---------|------|
| test1 | 5 | 5 | 5s | 超时丢弃 |
| test2 | 5 | 5 | 20s | 等久一点能拿到 |
| test3 | 5 | 0 | -1 | 物理连接，用完关闭 |

---

*最后更新：2026-05-09*
