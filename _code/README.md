# _code

> 代码与重构实践

---

## src/ （Go 源码）

- `heidsoft.go` — 主程序
- `heidsoft_test.go` — 测试

---

## code-refactoring/ （重构模式）

**笔记：** `重构.md` — 重构箴言 12 条（精华）

**图解（12张）：**
| 图片 | 说明 |
|------|------|
| 重构-Extract Method.png | 提取方法 |
| 重构-Extract Class.png | 提取类 |
| 重构-Extract Subclass.png | 提取子类 |
| 重构-Form Template Method.png | 表单模板方法 |
| 重构-Introduce Parameter Object.png | 引入参数对象 |
| 重构-Preserve Whole Object.png | 保持对象完整 |
| 重构-Pull Up Method.png | 上拉方法 |
| 重构-Replace Method with Method Object.png | 用方法对象替换方法 |
| 重构-Replace Parameter with Method.png | 用方法替换参数 |
| 重构-Replace Temp with Query.png | 用查询替换临时变量 |
| 重构-Substitute Algorithm.png | 替换算法 |

---

## 重构箴言（重构.md 精华）

> 三次法则：事不过三，三则重构
> - 第一次：只管去做
> - 第二次：做类似的事情产生反感
> - 第三次：在做类似事，就应该重构

> 消除重复代码，可以确定所有事务和行为在代码中只表述一次，**这正是优秀设计的根本**

> 良好的设计维持软件开发速度的根本，重构可以帮助你更快的开发软件，**它阻止软件腐败变质**

> 语义保护性重构 — 修改旧函数时，保留旧函数，让旧函数调用新函数，并将旧函数标记为 `@deprecated`

---

*最后更新：2026-05-09*
