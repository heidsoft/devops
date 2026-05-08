# _docs/git

> Git 版本控制

---

## 📄 笔记文件

| 文件 | 说明 |
|------|------|
| `工具使用.md` | Git 工具使用（maven→gradle 转换、Eclipse 工程） |

---

## 📁 子目录

### git/

- `Git查看、删除、重命名远程分支和tag.pdf` — Git 操作参考
- `Maxthon.pdf` — Maxthon 相关（疑似浏览器集成文档）

---

## 工具使用.md 精华

**Maven → Gradle 转换：**
```bash
gradle init --type pom
```

**Maven → Eclipse：**
```bash
# 生成 Eclipse 工程文件
mvn eclipse:eclipse
```

**Git 查看远程分支：**
```bash
git branch -r   # 查看远程分支
git push origin :branch  # 删除远程分支
git remote prune origin  # 清理已删除的远程分支
```

---

*最后更新：2026-05-09*
