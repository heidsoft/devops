# _docs/cloud

> 私有云平台研究：CloudStack / OpenStack / ZStack / jclouds

---

## 📄 笔记文件

| 文件 | 说明 |
|------|------|
| `cloudstack.md` | **⭐ 核心文档** CloudStack 4.3 研究、系统虚拟机密码、挂载 iso 分析、API 调用示例 |
| `CloudStack全局参数.md` | CloudStack 305 个配置参数 JSON 完整列表 |
| `cloudstack问题答疑.md` | CloudStack 运维 FAQ（英文） |
| `OpenStack.md` | OpenStack 研究、资源链接 |
| `xenserver.md` | XenServer XenApi 笔记 |
| `虚拟化.md` | 全虚拟化/半虚拟化技术 |
| `jclouds架构分析.md` | jclouds 多云工具包定位分析 |

---

## 📁 子目录

### zstack/ （ZStack 架构白皮书，7篇）

| 文件 | 说明 |
|------|------|
| `ZStack Architecture.pdf` | ZStack 整体架构 |
| `ZStack - The Cascade Framework.pdf` | 级联框架 |
| `ZStack - The In-Process Microservices Architecture.pdf` | 进程内微服务架构 |
| `ZStack - The Tag System.pdf` | 标签系统 |
| `ZStack - The Versatile Plugin System.pdf` | 灵活插件系统 |
| `ZStack - The Workflow Engine.pdf` | 工作流引擎 |
| `ZStack - ZStack's Scalability Secrets Part 1_ Asynchronous Architecture.pdf` | 可扩展性：异步架构 |
| `ZStack - ZStack's Scalability Secrets Part 2_ Stateless Services.pdf` | 无状态服务 |
| `ZStack - ZStack's Scalability Secrets Part 3_ Lock-free Architecture.pdf` | 无锁架构 |

### jclouds/ （jclouds API 测试截图）

- jclouds-debug-01~06.png — 调试截图
- jclouds-api-testing.png — API 测试
- jclouds-rest-debug-01.png — REST 调试
- 通过 REST 请求创建容器截图
- JCLOUDS-*.pdf — 官方白皮书
- apachejcloudsanddocker — jclouds 与 Docker 集成

---

## CloudStack 精华

**系统虚拟机密码：** `6m1ll10n`

**核心 API 调用：**
```bash
# 挂载 ISO
http://192.168.150.16:8080/client/api?command=detachIso&virtualmachineid=...&response=json

# 查询网络
http://192.168.150.16:8080/client/api?command=listNetworks&id=...&response=json

# 查询异步作业结果
http://192.168.150.16:8900/client/api?command=queryAsyncJobResult&jobId=...

# 添加主存储
POST http://192.168.150.16:8900/client/api?command=createStoragePool&zoneid=...&podId=...
```

**CloudStack 配置参数：** 共 305 个（见 `CloudStack全局参数.md` JSON 文件）

---

*最后更新：2026-05-09*
