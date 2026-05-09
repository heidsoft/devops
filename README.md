# devops

> DevOps 经验总结、实践记录与产品化探索

---

## 📋 项目简介

本仓库记录了我在 DevOps 领域的经验沉淀，包括：
- 容器化（Docker/K8s）实战笔记
- 私有云/混合云架构（OpenStack/CloudStack/ZStack）
- 中间件（RabbitMQ/Nginx/HAProxy）实践
- 前端工程化（AngularJS/DataTables）
- 网络与 SDN
- Git 版本控制与团队协作
- 设计模式与代码重构
- **产品设计文档**（智能补货助手 / ClawOps ITSM / AI 合同审核）

大部分内容为工作笔记和学习资料，供同行参考。

---

## 🛍️ 产品文档

> 官网 [cloudmesh.top](https://cloudmesh.top) 与 GitHub 联动，更多产品资料在线浏览

| 产品 | 一句话介绍 | 状态 |
|------|-----------|------|
| [**智能补货助手**](_docs/products/smart-replenishment/) | AI 销量预测 + 对话补货，零售小店必备 | 设计完成 |
| [**ClawOps ITSM**](_docs/products/clawops/) | 企业级运维平台，多租户+插件化 | 路线图进行中 |
| [**AI 合同审核 MVP**](_docs/products/ai-contract-review/) | 上传合同→3分钟出报告，¥9.9起 | MVP 完成 |

---

## 📂 目录结构

```
devops/
├── _docs/                          # 📚 技术文档（按主题分类）
│   ├── devops/                     # 容器化 · K8s · Spring · 鉴权
│   ├── architecture/               # 架构设计（SOA/ESB/高可用）
│   ├── cloud/                     # 私有云（OpenStack/CloudStack/ZStack）
│   ├── middleware/                # 中间件（RabbitMQ/Nginx/HAProxy）
│   ├── network/                   # 网络（SDN/iptables/网络嗅探）
│   ├── frontend/                  # 前端（AngularJS/CSS/DataTables）
│   ├── linux/                     # Linux（libvirt/vagrant/内核）
│   ├── db/                        # 数据库（哈希表/存储）
│   ├── git/                       # Git 版本控制
│   └── products/                 # 🆕 产品设计文档
│       ├── smart-replenishment/   # 智能补货助手
│       ├── clawops/               # ClawOps ITSM
│       └── ai-contract-review/    # AI 合同审核 MVP
├── _code/                         # 💻 代码
│   ├── src/                       # Go 源码
│   └── code-refactoring/         # 重构代码示例
├── _design-patterns/             # 🎨 设计模式
│   └── 设计模式/                   # UML/状态机/职责链
└── _archive/                      # 📦 归档（学习资料/图片/废弃内容）
```

---

## 📚 快速索引

### [_docs/devops/](_docs/devops/) — 容器化 · K8s · Spring · 鉴权

> ⭐ 核心实战目录，含 Docker/Mesos/K8S/Marathon 完整运维日志、commons-pool 连接池原创代码、OAuth 踩坑记录

- [docker实战.md](_docs/devops/docker实战.md) — Boot2Docker / Marathon / K8S 实战命令
- [commons-pool实战.md](_docs/devops/commons-pool实战.md) — GenericObjectPool 连接池详解 + 完整 Java 示例
- [pod.md](_docs/devops/pod.md) — K8s Pod 生命周期与钩子
- [docker-cluster.md](_docs/devops/docker-cluster.md) — Docker 主流集群对比
- [OAuth开发与集成.md](_docs/devops/OAuth开发与集成.md) — OAuth 踩坑 NoSuchMethodError
- [AI-DevOps/](_docs/devops/AI-DevOps/) — AI-DevOps 智能运维
- [docker/](_docs/devops/docker/) — Docker PDF 教程 20+ 篇
- [k8s/](_docs/devops/k8s/) — Kubernetes PDF 资料

---

### [_docs/architecture/](_docs/architecture/) — 架构设计

> SOA / ESB / 高可用 / 服务发现，含实战 Q&A

- [esb.md](_docs/architecture/esb.md) — ESB 企业服务总线简介
- [esb_faq.md](_docs/architecture/esb_faq.md) — ESB 实战问答
- [高可用.md](_docs/architecture/高可用.md) — Galera Cluster / KeepAlived 方案

---

### [_docs/cloud/](_docs/cloud/) — 私有云

> CloudStack / OpenStack / ZStack / jclouds，含 API 调用示例

- [cloudstack.md](_docs/cloud/cloudstack.md) — CloudStack 4.3 研究 + API 调用日志
- [CloudStack全局参数.md](_docs/cloud/CloudStack全局参数.md) — 305 个配置参数
- [zstack/](_docs/cloud/zstack/) — ZStack 架构白皮书 7 篇
- [jclouds/](_docs/cloud/jclouds/) — jclouds API 测试截图

---

### [_docs/middleware/](_docs/middleware/) — 中间件

> RabbitMQ / HAProxy / OpenResty / Apache

- [消息队列.md](_docs/middleware/消息队列.md) — Spring AMQP 实战笔记
- [rabbitmq/](_docs/middleware/rabbitmq/) — RabbitMQ 参考手册
- [openresty/](_docs/middleware/openresty/) — OpenResty + php-fpm 配置

---

### [_docs/network/](_docs/network/) — 网络

> SDN / iptables / 网络嗅探

- [sdn.md](_docs/network/sdn.md) — 软件定义网络：Floodlight / OpenFlow / Mininet
- [iptables手册.md](_docs/network/iptables手册.md) — 三表五链操作手册
- [网络嗅探.md](_docs/network/网络嗅探.md) — 共享型 vs 交换型以太网，网卡工作模式

---

### [_docs/frontend/](_docs/frontend/) — 前端

> AngularJS / CSS / DataTables，含 $watch/$digest 原理剖析

- [Angularjs.md](_docs/frontend/angularjs/Angularjs.md) — AngularJS 原理：scope / $watch / $digest 循环
- [前端架构.md](_docs/frontend/前端架构.md) — 前端架构设计
- [angularjs/](_docs/frontend/angularjs/) — AngularJS PDF 教程 + Stack Overflow 精选
- [datatables/](_docs/frontend/datatables/) — DataTables 详细使用说明

---

### [_docs/linux/](_docs/linux/) — Linux

> libvirt / vagrant / 内核，含命令速查

- [vagrant使用.md](_docs/linux/vagrant使用.md) — vagrant 命令速查
- [内核启动过程.md](_docs/linux/内核启动过程.md) — start_kernel() → rest_init()
- [内核编译.md](_docs/linux/内核编译.md) — make config / menuconfig / defconfig
- [libvirt/](_docs/linux/libvirt/) — libvirt 下载安装与对象模型

---

### [_docs/db/](_docs/db/) — 数据库

> 哈希表算法 / 存储测试

- [storage/从头到尾彻底解析哈希表算法.md](_docs/db/storage/从头到尾彻底解析哈希表算法.md) — ⭐ 原创 哈希表算法详解
- [存储测试.md](_docs/db/存储测试.md) — CloudStack 存储池创建 API 测试

---

### [_docs/git/](_docs/git/) — Git 版本控制

> 工具使用 / 远程分支管理

- [工具使用.md](_docs/git/工具使用.md) — maven→gradle 转换、Git 远程分支操作
- [git/](_docs/git/git/) — Git 操作参考 PDF

---

### [_docs/products/](_docs/products/) — 🆕 产品设计文档

| 产品 | 目录 | 说明 |
|------|------|------|
| 智能补货助手 | [smart-replenishment/](_docs/products/smart-replenishment/) | 市场调研/竞品分析/产品定义/技术方案 |
| ClawOps ITSM | [clawops/](_docs/products/clawops/) | 架构设计/告警中心/商业化/路线图 |
| AI 合同审核 MVP | [ai-contract-review/](_docs/products/ai-contract-review/) | MVP 方案/目标用户/定价 |

---

## 💻 代码索引（[_code/](_code/)）

- [heidsoft.go](_code/src/src/heidsoft.go) — Go 源码
- [heidsoft_test.go](_code/src/src/heidsoft_test.go) — Go 测试
- [重构.md](_code/code-refactoring/重构.md) — 重构箴言 12 条
- [重构模式图解](_code/code-refactoring/) — 12 张重构模式图片

---

## 🎨 设计模式（[_design-patterns/](_design-patterns/)）

- [UML图中类之间的关系.pdf](_design-patterns/设计模式/UML图中类之间的关系.pdf) — UML 类 6 种关系
- [state模式.pdf](_design-patterns/设计模式/state模式.pdf) — 状态模式
- [职责链模式.pdf](_design-patterns/设计模式/职责链模式（Chain%20of%20Responsibility）的Java实现.pdf) — 职责链 Java 实现

---

## 📦 归档（[_archive/](_archive/)）

> 已归档，不再维护

| 目录 | 内容 |
|------|------|
| [_archive/android.md](_archive/android.md) | Android 笔记 |
| [_archive/weichat/](_archive/weichat/) | 微信二维码素材 |
| [_archive/树莓派/](_archive/树莓派/) | 树莓派 PDF |
| [_archive/跨域分析/](_archive/跨域分析/) | 跨域分析 PDF 合集 |
| [_archive/_images/](_archive/_images/) | 所有图片素材 30+ 张 |
| [_archive/*.pdf](_archive/) | 外部学习资料 PDF |

---

## 🔗 相关项目

- [cloudmesh.top](https://cloudmesh.top) — 官网
- [heidsoft/heidsoft](https://github.com/heidsoft/heidsoft) — 个人主页

---

*最后更新：2026-05-09*
