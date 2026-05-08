# _docs/network

> 网络与 SDN

---

## 📄 笔记文件

| 文件 | 说明 |
|------|------|
| `sdn.md` | **⭐ 核心文档** 软件定义网络，工具链：Floodlight / OpenFlow / Mininet |
| `iptables手册.md` | **⭐ 原创** iptables 操作手册，三表（filter/nat/mangle）+ 五链（INPUT/FORWARD/OUTPUT/PREROUTING/POSTROUTING） |
| `网络嗅探.md` | 网络嗅探原理：共享型以太网 vs 交换型以太网，网卡工作模式（广播/组播/单播/混杂） |

---

## SDN 工具链（sdn.md）

| 工具 | 链接 |
|------|------|
| Floodlight | http://www.projectfloodlight.org/floodlight/ |
| OpenFlow | http://archive.openflow.org/ |
| Mininet | http://mininet.org/ |

---

## iptables 快速查表

**三表：**
- `filter` — 默认表，过滤 INPUT/FORWARD/OUTPUT
- `nat` — 网络地址转换 PREROUTING/OUTPUT/POSTROUTING
- `mangle` — 报文修改

**五链：**
- `INPUT` — 入站包
- `OUTPUT` — 本地生成包
- `FORWARD` — 转发包
- `PREROUTING` — 路由前
- `POSTROUTING` — 路由后

---

*最后更新：2026-05-09*
