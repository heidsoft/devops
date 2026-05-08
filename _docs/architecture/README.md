# _docs/architecture

> 架构设计：SOA / ESB / 高可用 / 服务发现

---

## 📄 笔记文件

| 文件 | 说明 |
|------|------|
| `soa.md` | SOA 面向服务架构 |
| `esb.md` | **⭐ 核心文档** ESB 企业服务总线简介，Karaf/Camel 开源框架 |
| `esb_faq.md` | **⭐ 核心文档** ESB 实战问答（应用场景、如何消除技术差异、分布式运行管理） |
| `服务发现.md` | 使用 DNS 作为 REST Web 服务的发现机制 |
| `软件架构.md` | 软件架构定义、软件元素外部可见属性 |
| `高可用.md` | 高可用方案：Galera Cluster（codership）/ KeepAlived |

---

## ESB 精华（esb.md / esb_faq.md）

**ESB 是什么：**
> Enterprise Service Bus，传统中间件技术与 XML、Web 服务结合的产物，构筑企业神经系统的必要元素。

**核心能力：**
- 事件驱动 + 文档导向处理模式
- 分布式运行管理机制
- 基于内容的路由和过滤
- 复杂数据传输能力
- 标准接口

**开源框架：**
- [Karaf](http://karaf.apache.org/) — OSGi 容器
- [Camel](http://camel.apache.org/) — 路由/中介

---

## 高可用方案

| 方案 | 链接 |
|------|------|
| Galera Cluster | http://codership.com/content/using-galera-cluster |
| KeepAlived | http://www.keepalived.org/ |

---

*最后更新：2026-05-09*
