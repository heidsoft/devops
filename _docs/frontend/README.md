# _docs/frontend

> 前端工程化研究：AngularJS / CSS / DataTables

---

## 📄 笔记文件

| 文件 | 说明 |
|------|------|
| `前端架构.md` | 前端架构设计 |

---

## 📁 子目录

### angularjs/

**笔记：**
- `Angularjs.md` — AngularJS 原理剖析：scope/$watch/$digest 循环（原创精华）
- `angularjs四大核心特性.png` — 特性图解
- `angularjs-嵌套form-01.png` — 表单嵌套
- `angularjs-token-认证.pdf` — Token 认证
- `前端路由的基本原理.png` / `为什么需要前端路由.png` — 路由原理图解
- `指令01~03.png` — 指令三个阶段
- `restrict匹配模式.png` — 指令匹配模式
- `angularjs-form-01.png` / `angularjs-form-02.png` — 表单图解
- `嵌套路由的语法.png` — 嵌套路由

**PDF 教程（Stack Overflow 精选）：**
- AngularJS + JQuery — dynamic content working — Stack Overflow
- AngularJS ui-router 嵌套路由 — OPEN 开发经验库
- AngularJS 中 Factory vs Service vs Provider 区别
- AngularJS 开发指南 29：单元测试
- AngularJS 开发指南 33：将服务注入到控制器中
- Interceptors in AngularJS and Useful Examples
- 理解 Angular 中的 $apply() 以及 $digest()
- 在 AngularJS 应用中通过 JSON 文件来设置状态
- 如何测试 AngularJS 中的 Service
- dom - AngularJS - Compiling dynamic HTML strings from database
- model binding - Bind Angularjs to newly created html element dynamically
- AngularJS 中文API参考手册.chm

### css/

- `css样式原则.png` — CSS 样式原则
- `盒子模型.png` / `盒子模型3d图形.png` — 盒子模型图解
- `行级标签.png` — 行级标签

### datatables/

- `dataTables-使用详细说明整理 - 行百里者半九十 - 博客频道 - CSDN.pdf` — DataTables 详细使用说明

---

## AngularJS 精华（Angularjs.md）

**$watch 工作原理：**
```javascript
$scope.$watch('aModel', function(newValue, oldValue) {
  // update the DOM with newValue
});
```

**$digest 循环：**
- watchers 被逐个检查
- 如果值变了，AngularJS 刷新 scope 模型
- 然后调用对应 watcher 的回调函数

---

*最后更新：2026-05-09*
