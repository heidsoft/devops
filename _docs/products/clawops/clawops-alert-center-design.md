# ClawOps 监控告警中心详细设计

> 商用级监控告警模块的设计文档

---

## 一、整体架构

```
┌─────────────────────────────────────────────────────────────────────────┐
│                         监控告警中心架构                                 │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│  数据层                    处理层                    展示层             │
│  ┌─────────┐            ┌─────────┐            ┌─────────┐            │
│  │ 主机监控 │ ──┐       │ 告警聚合 │            │ 告警看板 │            │
│  └─────────┘   │       └─────────┘            └─────────┘            │
│  ┌─────────┐   │       ┌─────────┐            ┌─────────┐            │
│  │ 应用监控 │ ──┼──────→│ 智能降噪 │ ──────────→│ 处理工单 │            │
│  └─────────┘   │       └─────────┘            └─────────┘            │
│  ┌─────────┐   │       ┌─────────┐            ┌─────────┐            │
│  │ 网络监控 │ ──┤       │ 根因分析 │            │ 统计报表 │            │
│  └─────────┘   │       └─────────┘            └─────────┘            │
│  ┌─────────┐   │       ┌─────────┐                                   │
│  │ 业务监控 │ ──┘       │ 自动处置 │                                   │
│  └─────────┘           └─────────┘                                   │
│                                                                         │
│  ┌─────────────────────────────────────────────────────────────────┐   │
│  │                        通知渠道                                  │   │
│  │   钉钉 │ 飞书 │ 企业微信 │ 短信 │ 电话 │ 邮件                   │   │
│  └─────────────────────────────────────────────────────────────────┘   │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

---

## 二、告警生命周期

```
┌────────┐    ┌────────┐    ┌────────┐    ┌────────┐    ┌────────┐
│ 产生   │ → │ 聚合   │ → │ 降噪   │ → │ 分级   │ → │ 通知   │
└────────┘    └────────┘    └────────┘    └────────┘    └────────┘
                                                  ↓
                                            ┌────────┐
                                            │ 处理   │
                                            └────────┘
                                                  ↓
                                            ┌────────┐
                                            │ 闭环   │
                                            └────────┘
```

### 2.1 告警聚合

**目的**：减少告警风暴，合并相关告警

**聚合维度**：

```yaml
aggregation_rules:
  - name: "同一服务告警聚合"
    group_by: ["service", "alert_name"]
    time_window: "5m"
    max_alerts: 100
    
  - name: "关联告警聚合"
    group_by: ["host", "timestamp"]
    correlation:
      - source: "host_down"
        related: ["service_down", "db_connection_failed"]
      - source: "network_issue"
        related: ["timeout", "latency_high"]
```

**示例**：

```
原始告警（10:00-10:05）：
├── host-01 CPU 高
├── host-01 内存高
├── host-01 磁盘 IO 高
├── host-02 CPU 高
├── payment-service 响应慢
├── payment-service 错误率高
└── db-connection 连接超时

聚合后：
├── [host-01] 资源异常（聚合 3 条）
├── [host-02] CPU 高（1 条）
└── [payment-service] 服务异常（聚合 3 条）
    └── 根因：db-connection 超时
```

### 2.2 智能降噪

**降噪策略**：

| 策略 | 说明 | 配置示例 |
|------|------|----------|
| 抑制 | 条件满足时抑制告警 | 维护窗口内不告警 |
| 静默 | 指定时间内静默 | 预期变更期间静默 |
| 去重 | 重复告警只保留一条 | 5 分钟内相同告警 |
| 依赖 | 依赖服务异常时抑制 | 网络断开时抑制主机告警 |

**配置示例**：

```yaml
silence_rules:
  - name: "维护窗口静默"
    match:
      labels:
        env: "production"
    time_range:
      start: "2026-03-23 02:00"
      end: "2026-03-23 06:00"
    reason: "计划维护"
    
inhibition_rules:
  - name: "网络故障抑制"
    source_match:
      alertname: "NetworkDown"
    target_match:
      alertname: "HostDown"
    equal: ["instance"]
```

### 2.3 告警分级

**分级标准**：

| 级别 | 定义 | 响应时间 | 通知方式 | 示例 |
|------|------|----------|----------|------|
| **P0** | 核心业务中断 | 5 分钟 | 电话+短信+IM | 支付系统不可用 |
| **P1** | 重要功能受损 | 15 分钟 | 短信+IM | 数据库连接池耗尽 |
| **P2** | 性能下降 | 1 小时 | IM | API 响应超时增加 |
| **P3** | 潜在风险 | 4 小时 | 邮件 | 磁盘空间使用率 80% |

**自动分级规则**：

```yaml
severity_rules:
  - name: "核心业务P0"
    match:
      labels:
        service: ["payment", "order", "user"]
        status: "down"
    severity: "P0"
    
  - name: "数据库P1"
    match:
      labels:
        component: "database"
        metrics: ["connection_exhausted", "replication_lag_high"]
    severity: "P1"
    
  - name: "性能P2"
    match:
      labels:
        type: "performance"
    severity: "P2"
```

---

## 三、告警通知

### 3.1 通知策略

```yaml
notification_policies:
  - name: "P0告警"
    severity: ["P0"]
    channels:
      - type: "phone"
        escalation_timeout: "5m"
      - type: "sms"
        recipients: ["oncall_team"]
      - type: "dingtalk"
        at_all: true
    escalation:
      - delay: "5m"
        notify: ["manager"]
      - delay: "15m"
        notify: ["director"]
        
  - name: "P1告警"
    severity: ["P1"]
    channels:
      - type: "sms"
      - type: "feishu"
    escalation:
      - delay: "15m"
        notify: ["manager"]
```

### 3.2 值班轮换

```yaml
oncall_schedules:
  - name: "主值班"
    team: "sre_team"
    rotation: "weekly"
    members: ["张三", "李四", "王五"]
    time_range: "09:00-21:00"
    
  - name: "夜间值班"
    team: "sre_team"
    rotation: "daily"
    members: ["张三", "李四", "王五"]
    time_range: "21:00-09:00"
    
  - name: "周末值班"
    team: "all_team"
    rotation: "weekly"
    members: ["全员轮换"]
```

---

## 四、故障诊断

### 4.1 自动诊断流程

```
告警触发
    │
    ▼
┌─────────────────┐
│ 收集上下文      │ ← 主机信息、服务状态、近期变更
└─────────────────┘
    │
    ▼
┌─────────────────┐
│ AI 分析         │ ← 日志分析、指标关联、拓扑分析
└─────────────────┘
    │
    ▼
┌─────────────────┐
│ 匹配知识库      │ ← 历史案例、解决方案
└─────────────────┘
    │
    ├──→ 有匹配案例 → 推荐解决方案
    │
    └──→ 无匹配 → 生成诊断报告
```

### 4.2 诊断规则库

```yaml
diagnosis_rules:
  - name: "数据库慢查询"
    triggers:
      - alert: "SlowQueryDetected"
    diagnosis:
      - step: "获取慢查询SQL"
        action: "mysql.slow_query.get"
      - step: "分析执行计划"
        action: "mysql.explain.analyze"
      - step: "检查索引使用"
        action: "mysql.index.check"
    suggestions:
      - condition: "full_table_scan"
        action: "建议添加索引"
        auto_fix: false
      - condition: "temp_table"
        action: "优化查询语句"
        auto_fix: false
        
  - name: "服务响应慢"
    triggers:
      - alert: "ServiceLatencyHigh"
    diagnosis:
      - step: "检查下游依赖"
        action: "dependency.check"
      - step: "检查资源使用"
        action: "resource.check"
      - step: "分析调用链"
        action: "trace.analyze"
```

---

## 五、自动修复

### 5.1 自愈规则配置

```yaml
auto_remediation:
  enabled: true
  require_approval: false  # P0/P1 需要审批
  log_all_actions: true
  
  rules:
    - name: "服务自动重启"
      trigger:
        alert: "ServiceDown"
        duration: "1m"
      action:
        type: "restart_service"
        params:
          service: "${service_name}"
          max_retries: 3
          retry_interval: "30s"
      rollback:
        enabled: true
        on_failure: "alert_manual"
        
    - name: "自动扩容"
      trigger:
        alert: "HighCPU"
        threshold: 85
        duration: "5m"
      action:
        type: "scale_out"
        params:
          service: "${service_name}"
          min_replicas: 2
          max_replicas: 10
          step: 1
      approval:
        required: false
        
    - name: "磁盘清理"
      trigger:
        alert: "DiskSpaceLow"
        threshold: 90
      action:
        type: "clean_logs"
        params:
          paths: ["/var/log", "/tmp"]
          keep_days: 3
          dry_run: false
```

### 5.2 自愈操作审计

所有自动修复操作必须记录：

```json
{
  "id": "auto-fix-20260323-001",
  "timestamp": "2026-03-23T10:15:00Z",
  "trigger_alert": "ServiceDown",
  "action": "restart_service",
  "target": "payment-service",
  "result": "success",
  "duration": "15s",
  "before_state": "down",
  "after_state": "running",
  "approved_by": "auto",
  "operator": "clawops-agent"
}
```

---

## 六、告警看板

### 6.1 实时看板

```
┌─────────────────────────────────────────────────────────────────┐
│                    ClawOps 告警中心                              │
├─────────────────────────────────────────────────────────────────┤
│                                                                 │
│  ┌──────┐ ┌──────┐ ┌──────┐ ┌──────┐ ┌──────┐                 │
│  │ P0: 1│ │ P1: 3│ │ P2: 8│ │ 待处理│ │ 今日处理│               │
│  │  🔴  │ │  🟡  │ │  🟢  │ │   5   │ │   12   │               │
│  └──────┘ └──────┘ └──────┘ └──────┘ └──────┘                 │
│                                                                 │
│  ┌─────────────────────────────────────────────────────────┐   │
│  │ 🔴 P0 - payment-service 响应超时                        │   │
│  │    时间: 10:15  持续: 5分钟  处理人: 张三               │   │
│  │    [查看详情] [一键诊断] [处理]                          │   │
│  └─────────────────────────────────────────────────────────┘   │
│                                                                 │
│  ┌─────────────────────────────────────────────────────────┐   │
│  │ 🟡 P1 - db-prod 连接数告警                               │   │
│  │    时间: 10:10  持续: 10分钟  等待处理                   │   │
│  │    [查看详情] [认领]                                     │   │
│  └─────────────────────────────────────────────────────────┘   │
│                                                                 │
└─────────────────────────────────────────────────────────────────┘
```

### 6.2 告警详情页

```
┌─────────────────────────────────────────────────────────────────┐
│  告警详情: payment-service 响应超时                              │
├─────────────────────────────────────────────────────────────────┤
│                                                                 │
│  基本信息                                                       │
│  ├── 告警级别: P0                                               │
│  ├── 触发时间: 2026-03-23 10:15:00                              │
│  ├── 持续时间: 5 分钟                                           │
│  ├── 服务: payment-service                                      │
│  └── 环境: production                                           │
│                                                                 │
│  AI 诊断                                                        │
│  ├── 根因: 数据库连接池耗尽                                     │
│  ├── 影响: 支付接口响应超时                                     │
│  └── 置信度: 85%                                                │
│                                                                 │
│  相关指标                                                       │
│  ├── CPU: 45% → 78% (10:10)                                    │
│  ├── 内存: 62% (稳定)                                          │
│  ├── 响应时间: 200ms → 3500ms                                  │
│  └── 错误率: 0.1% → 15%                                        │
│                                                                 │
│  推荐操作                                                       │
│  ├── [一键修复] 重置连接池                                     │
│  ├── [一键修复] 重启服务                                       │
│  └── [人工处理] 查看详细日志                                   │
│                                                                 │
│  处理记录                                                       │
│  ├── 10:15 张三 认领告警                                       │
│  ├── 10:16 AI 完成自动诊断                                     │
│  └── 10:17 执行连接池重置...                                   │
│                                                                 │
└─────────────────────────────────────────────────────────────────┘
```

---

## 七、API 接口

### 7.1 告警列表

```
GET /api/v1/alerts

参数:
- severity: P0/P1/P2/P3
- status: firing/resolved
- service: 服务名
- start: 开始时间
- end: 结束时间
- page: 页码
- size: 每页数量

响应:
{
  "total": 156,
  "items": [
    {
      "id": "alert-001",
      "severity": "P0",
      "status": "firing",
      "title": "payment-service 响应超时",
      "service": "payment-service",
      "startTime": "2026-03-23T10:15:00Z",
      "duration": "5m",
      "assignee": "张三"
    }
  ]
}
```

### 7.2 告警处理

```
POST /api/v1/alerts/{id}/acknowledge

请求体:
{
  "action": "acknowledge",  // acknowledge/resolve/escalate
  "assignee": "张三",
  "comment": "正在排查"
}
```

### 7.3 执行自愈

```
POST /api/v1/alerts/{id}/remediate

请求体:
{
  "action": "restart_service",
  "params": {
    "service": "payment-service"
  },
  "approved": true
}
```

---

*文档版本：v1.0*
*更新时间：2026-03-23*