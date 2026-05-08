# _docs/middleware

> 中间件实践：RabbitMQ / HAProxy / OpenResty / Apache

---

## 📄 笔记文件

| 文件 | 说明 |
|------|------|
| `消息队列.md` | **⭐ 原创** Spring AMQP 实现、RabbitMQ 消息队列实战笔记 |

---

## 📁 子目录

### rabbitmq/

- `rabbitmq-ref.pdf` — RabbitMQ 参考手册（英文 PDF）

### haproxy/

- `haproxy.pdf` — HAProxy 配置参考文档

### openresty/

- `index.md` — OpenResty + php-fpm 安装配置链接、CentOS + MariaDB + PHP 搭建 Web 服务器笔记

### apache/

- `apache-how-it-work.pdf` — Apache 工作原理

---

## 消息队列精华（消息队列.md）

**Spring AMQP 是什么：**
> The Spring AMQP project applies core Spring concepts to the development of AMQP-based messaging solutions.
> Provides a "template" as a high-level abstraction for sending and receiving messages.
> Provides a "listener container" for asynchronous processing of inbound messages.

**组成：**
- `spring-amqp` — 基础抽象层
- `spring-rabbit` — RabbitMQ 实现
- Listener container — 用于异步处理入站消息

---

*最后更新：2026-05-09*
