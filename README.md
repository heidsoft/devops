# devops

> DevOps 经验总结、实践记录与产品化探索

---

## 📋 项目简介

本仓库记录了我在 DevOps 领域的经验沉淀，包括：
- 容器化（Docker/K8s）实战笔记
- 私有云/混合云架构（OpenStack/CloudStack/ZStack）
- 中间件（RabbitMQ/Nginx/HAProxy）实践
- 前端工程化（AngularJS/DataTables）
- Git 版本控制与团队协作
- 设计模式与代码重构

大部分内容为工作笔记和学习资料，供同行参考。

---

## 📂 目录结构

```
devops/
├── _docs/                          # 📚 技术文档（按主题分类）
│   ├── devops/                     # 容器化 · K8s · Spring · 鉴权
│   ├── architecture/                # 架构设计（SOA/ESB/高可用）
│   ├── cloud/                      # 私有云（OpenStack/CloudStack/ZStack）
│   ├── middleware/                 # 中间件（RabbitMQ/Nginx/HAProxy）
│   ├── network/                   # 网络（SDN/iptables/网络嗅探）
│   ├── frontend/                  # 前端（AngularJS/CSS/DataTables）
│   ├── linux/                     # Linux（libvirt/vagrant/内核）
│   ├── db/                        # 数据库（哈希表/存储）
│   └── git/                       # Git 版本控制
├── _code/                         # 💻 代码
│   ├── src/                       # Go 源码（heidsoft.go）
│   └── code-refactoring/          # 重构代码示例
├── _design-patterns/              # 🎨 设计模式
│   └── 设计模式/                   # UML/状态机/职责链
└── _archive/                       # 📦 归档（学习资料/图片/废弃内容）
```

---

## 📚 文档索引（_docs/）

### _docs/devops/ — 容器化 · K8s · Spring · 鉴权

**📄 笔记文件：**
| 文件 | 说明 |
|------|------|
| `Dockerfile.md` | Dockerfile 写法 |
| `Docker功能点.md` | Docker 功能点清单 |
| `Docker容器规范.md` | 容器规范 |
| `Docker镜像规范.md` | 镜像规范 |
| `docker-cluster.md` | Docker 集群 |
| `docker实战.md` | Docker 实战 |
| `使用Device Mapper来改变Docker容器的大小.md` | Device Mapper |
| `pod.md` | K8s Pod 笔记 |
| `mesos-slave命令介绍.md` | Mesos 命令 |
| `Spring.md` | Spring 笔记 |
| `Golang.md` | Go 语言笔记 |
| `UML精粹.md` | UML 精粹 |
| `ITIL_v3_学习.md` | ITIL v3 学习 |
| `commons-pool实战.md` | commons-pool 实战 |
| `OAuth开发与集成.md` | OAuth 开发集成 |
| `OAuth 2 开发人员指南.md` | OAuth2 指南 |
| `OAuth开发与集成.md` | OAuth 开发 |
| `AI-DevOps/README.md` | AI-DevOps 智能运维 |
| `paas/*.pdf` | PaaS 学习资料 |
| `mvn/maven实践.md` | Maven 实践 |

**📁 子目录：**
- `docker/` — Docker PDF 教程（20+ 篇）
- `k8s/` — Kubernetes PDF 资料
- `Spring/` — Spring Security 笔记
- `aufs2-base5/` — AuFS2 内核补丁源码
- `union-file-system/` — UnionFS 文档
- `dockerui/` — Docker UI 界面

---

### _docs/architecture/ — 架构设计

**📄 笔记文件：**
| 文件 | 说明 |
|------|------|
| `soa.md` | SOA 架构 |
| `esb.md` | ESB 企业服务总线 |
| `esb_faq.md` | ESB 常见问题 |
| `服务发现.md` | 服务发现方案 |
| `高可用.md` | 高可用架构 |
| `软件架构.md` | 软件架构设计 |

---

### _docs/cloud/ — 私有云

**📄 笔记文件：**
| 文件 | 说明 |
|------|------|
| `OpenStack.md` | OpenStack 笔记 |
| `cloudstack.md` | CloudStack 笔记 |
| `CloudStack全局参数.md` | CloudStack 参数 |
| `cloudstack问题答疑.md` | CloudStack FAQ |
| `xenserver.md` | XenServer 笔记 |
| `虚拟化.md` | 虚拟化技术 |
| `jclouds架构分析.md` | jclouds 架构 |

**📁 子目录：**
- `zstack/` — ZStack 架构白皮书（7篇）
- `jclouds/` — jclouds API 测试截图

---

### _docs/middleware/ — 中间件

**📄 笔记文件：**
| 文件 | 说明 |
|------|------|
| `消息队列.md` | 消息队列实战 |

**📁 子目录：**
- `rabbitmq/` — RabbitMQ 参考文档
- `haproxy/` — HAProxy 配置参考
- `openresty/` — OpenResty 笔记
- `apache/` — Apache 原理

---

### _docs/network/ — 网络

**📄 笔记文件：**
| 文件 | 说明 |
|------|------|
| `sdn.md` | SDN 软件定义网络 |
| `iptables手册.md` | iptables 手册 |
| `网络嗅探.md` | 网络嗅探实战 |

---

### _docs/frontend/ — 前端

**📄 笔记文件：**
| 文件 | 说明 |
|------|------|
| `前端架构.md` | 前端架构设计 |

**📁 子目录：**
- `angularjs/` — AngularJS 中文API、教程、Stack Overflow 合集
- `css/` — CSS 盒子模型、行级标签等图解
- `datatables/` — DataTables 使用详细说明

---

### _docs/linux/ — Linux

**📄 笔记文件：**
| 文件 | 说明 |
|------|------|
| `libvirt/libvirt.md` | libvirt 虚拟化 |
| `vagrant使用.md` | Vagrant 使用 |
| `内核启动过程.md` | Linux 启动过程 |
| `内核编译.md` | 内核编译步骤 |
| `ubuntu-rabbitmq-install/install.md` | Ubuntu 安装 RabbitMQ |

---

### _docs/db/ — 数据库

**📄 笔记文件：**
| 文件 | 说明 |
|------|------|
| `storage/从头到尾彻底解析哈希表算法.md` | 哈希表算法详解 |
| `存储测试.md` | 存储测试记录 |

---

### _docs/git/ — 版本控制

**📄 笔记文件：**
| 文件 | 说明 |
|------|------|
| `工具使用.md` | Git 工具使用 |

**📁 子目录：**
- `git/` — Git 操作参考 PDF

---

## 💻 代码索引（_code/）

| 路径 | 说明 |
|------|------|
| `_code/src/src/heidsoft.go` | Go 源码 |
| `_code/src/src/heidsoft_test.go` | Go 测试 |
| `_code/code-refactoring/重构.md` | 重构笔记 |
| `_code/code-refactoring/` | 重构模式图解（12张） |

---

## 🎨 设计模式索引（_design-patterns/）

| 文件 | 说明 |
|------|------|
| `设计模式/state模式.pdf` | 状态模式 |
| `设计模式/UML图中类之间的关系.pdf` | UML 类关系 |
| `设计模式/职责链模式（Chain of Responsibility）的Java实现.pdf` | 职责链模式 |
| `设计模式/link.txt` | 参考链接 |

---

## 📦 归档内容（_archive/）

> 以下内容已归档，不再维护

| 路径 | 说明 |
|------|------|
| `_archive/android.md` | Android 笔记 |
| `_archive/软件工程.md` | 软件工程 |
| `_archive/wordpress/index.md` | WordPress |
| `_archive/video/` | 视频资料 |
| `_archive/weichat/` | 微信素材 |
| `_archive/树莓派/` | 树莓派资料 |
| `_archive/跨域分析/` | 跨域分析 PDF 合集 |
| `_archive/_images/` | 所有图片素材 |
| `_archive/*.pdf` | 外部学习资料 PDF（OAuth/ITIL/架构实战等） |

---

## 🔗 相关项目

- [heidsoft/heids](https://github.com/heidsoft/heids) - 个人主页
- [heidsoft/heidsoft-devops](https://github.com/heidsoft/heidsoft-devops) - DevOps 实践
- [cloudmesh.top](https://cloudmesh.top) - 官网

---

*最后更新：2026-05-09*
