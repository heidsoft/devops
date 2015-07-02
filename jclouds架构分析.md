#jclouds分析
##注解说明
###@Documented
```
Documented 注解表明这个注解应该被 javadoc工具记录. 默认情况下,javadoc是不包括注解的. 但如果声明注解时指定了 @Documented,则它会被 javadoc 之类的工具处理, 所以注解类型信息也会被包括在生成的文档中
```
###@AutoService
```
https://github.com/google/auto
```
##第三方技术说明
```
Google-Guice:是一个轻量级的DI框架
http://blog.csdn.net/derekjiang/article/details/7231490

Shrinkwrap 是归档操作的 Java API。Shrinkwrap 提供一个简单的 API 来接收类似 Java 的 JARs，WARs 的归档。ShrinkWrap 项目提供一个简单的 API 来程序化的接收代码归档，允许导出 ZIP 或者其他文件格式，使得更快的原型 "虚拟化" 的从资源中归档，比如类路径，文件系统或者远程 URLs。
https://github.com/shrinkwrap/shrinkwrap
```