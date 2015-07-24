#jclouds分析
##jclouds定位
```
Apache jclouds是一套面向Java平台的开源多云工具包，旨在为用户提供更为广阔的自由发挥空间、
从而在对各类特定云功能拥有充分控制权的前提下创建出能够在不同云环境之间随意迁移的应用程序方案
“开源”代表着该项目主要由社区体系负责构建。而“多云”意味着jclouds能够与大量公有及私有云体系顺利协作，
其中包括目前在市场上占据优势地位的各主流解决方案。“工具包”说明我们并非单纯为其指定一种编程语言，
同时也将Chef集成及命令行机制引入其中。“Java平台”是指我们以JVM作为运行基础，
此外还囊括了与Scala、Groovy以及Clojure的协作能力。“迁移”代表着项目本身对于所处云环境并未做出明确限定。
“特定云功能”则强调jclouds不仅能够在不同云环境之间顺利迁移，同时也能够涵盖某些云方案所提供的特定功能，
从而帮助开发人员根据需要随意加以使用。“充分控制权”指的是以最具实际价值的方式利用jclouds对自己的用例加以支持，
且拥有随意迁移或者发挥特定云功能的充分自由。

Ruby中的Fog、Node.js中的pkgcloud以及Python中的libcloud。

谷歌计算引擎以及Mesosphere开源项目利用jclouds在云环境下创建集群。
开发人员依赖于jclouds，并且利用它创建出各种已经准备好进入生产环境的应用程序。


您能具体说说jclouds在摆脱云环境限定方面所带来的实际优势吗?
　　这类优势其实多种多样，但在我看来它们可以归结于两大主要原因：避免供应商锁定以及别把鸡蛋都放在同一个篮子当中。
　　那些工程技术团队规模较小的小型企业(例如初创企业)非常乐于使用云方案。随着业务的不断拓展，他们可能逐渐发现自己当初所选择的云服务供应商已经无法继续满足其业务层面的实际要求。此类情况可能体现在各个方面，其中包括使用成本、性能表现以及技术支持能力等等。与此同时，他们可能还会发现自己被牢牢锁定在了当初所选择的云服务供应商身上。如果他们能够从一开始就充分享受到像jclouds这样不限定云环境类型的工具所带来的优势，那么能够轻松切换云平台来实现成本削减将完全可行。
　　那些规模较大的企业往往拥有实力更加雄厚的工程技术团队，但他们同样有理由使用云来支撑自身业务体系。有些时候，问题的重点并不仅仅体现在避免供应商锁定方面。其核心实质是，我们不能把所有鸡蛋放在同一个篮子当中，而从起步阶段就使用jclouds这类不限定云环境类型的工具能够很好地实现这类目标。无论是与多家云服务供应商协作构建起一套灾难恢复场景，还是希望通过云服务供应商之间的正面竞争来促进其服务质量，最终的受益者都将是用户。

jclouds项目是由Adrian Cole在五年多之前所创立的，目前他仍然活跃在项目当中。
　　我们拥有一个坚实的项目管理委员会成员团队以及众多委员，其中一些属于个人贡献者、另一些则隶属于包括各类云服务供应商在内的不同机构。除了管理核心之外，我们还从来自全世界的项目参与者手中获取代码贡献。纵观项目的整个发展历史，我们已经收到了来自超过100位贡献者提供的8500多项提交成果。感兴趣的朋友可以点击此处访问并了解如何加入我们的技术社区。
　　加入Apache软件基金会对于我们来说是一次意义重大的转折性事件。技术方面的变动当然也是存在的，但我们仍然通过GitHub pull请求来获取贡献并利用持续集成机制保障项目完整性。事实上，主要的变化发生在项目执行流程层面。在加入Apache软件基金会之前，我们虽然也拥有自己的处理流程，但转制所带来的过渡阶段迫使我们利用Apache软件基金会所固有的流程结构帮助自身将上述机制进行规范化处理。成长的过程中当然伴随着痛苦，不过这一切努力最终打造出了更为理想的项目成果，而且目前负责jclouds管理工作的成员都真正对其拥有强烈的热情与期待。
　　如果我想利用jclouds与自己的私有OpenStack云相对接，应该如何着手实现这一目标呢?
　　jclouds属于面向OpenStack的官方Java SDK。大家可以遵循developer.openstack.org网站中所提供的面向OpenStack的jclouds上手指南资料。其中的内容会就jclouds安装、技术术语差异以及一部分示例代码帮助开发人员构建起更加明确的实施认知。在进行过初步尝试之后，建议大家最好能后退一步、认真阅读项目中的各类核心概念，否则各位很可能会只见树木而不见森林、难窥整个项目的全貌。如果大家的用例要求使用具备可移植特性且不受云环境限制的代码，各位还需要深入阅读ComputeService与BlobStore中的相关内容。
　　关于jclouds，您还有什么希望与大家分享的内容吗?
　　如果我最后不强调“pull请求火热征集中”，肯定就没法凸显jclouds作为开源项目的本质特征了。我们始终欢迎任何感兴趣的朋友在任何时间加入到贡献者这个大家庭中来。解答疑问的最佳方式是点击此处访问我们的“如何进行贡献”维基页面来获取更多具体信息。我们也热切期待能有更多朋友为我们提供说明文档。大家可能已经注意到，我们网站上每个页面的页脚处都设有一条链接，标明“修复此页面”。只要点击这条链接，大家就能直接进入GitHub编辑器并对当前页面的markdown源代码进行查看，并且可以对其内容进行修改。没错，做出贡献就是这么简单，开源世界就是这样一个轻松而美好的领域
```

##jclouds支持平台
```
Abiquo Quick Start
Abiquo Detailed User Guide
Amazon Web Services
Amazon EC2
Amazon S3
Amazon SQS
Amazon Elastic Block Storage
Azure Storage Service
BlueLock vCloud
Chef
CloudSigma
GoGrid
Google App Engine
HP Cloud Services
OpenStack
Rackspace
Terremark
Terremark eCloud
Terremark vCloud Express
VMWare vCloud
VMWare vCloud Director 1.5
```
##注解说明
###@Documented
```
Documented 注解表明这个注解应该被 javadoc工具记录. 默认情况下,javadoc是不包括注解的. 但如果声明注解时指定了 @Documented,则它会被 javadoc 之类的工具处理, 所以注解类型信息也会被包括在生成的文档中
```
###@AutoService
```
https://github.com/google/auto
```

###@Beta
```
/**
 * 表明一个公用API的未来版本是受不兼容变更或删除限制的
 * 拥有这个注释标志的API不受任何兼容性保证
 *
 */
@Retention(RetentionPolicy.CLASS)
@Target({
        ElementType.ANNOTATION_TYPE,
        ElementType.CONSTRUCTOR,
        ElementType.FIELD,
        ElementType.METHOD,
        ElementType.TYPE})
@Documented
@GwtCompatible
public @interface Beta {}
```
###@GwtCompatible
```
/**
 * 表明一个类型可能会与 Google Web Toolkit 一起使用.
 * 如果一个方法使用这个注释,说明这个方法的返回值是 GWT 兼容的
 *
 */
@Retention(RetentionPolicy.CLASS)
@Target({ ElementType.TYPE, ElementType.METHOD })
@Documented
@GwtCompatible
public @interface GwtCompatible {

    /**
     * 说明一个类型或者方法的返回值是否支持 GWT 序列化
     *
     */
    boolean serializable() default false;

    /**
     * 说明一个类型是否在 GWT 被模拟.
     * 被模拟的源(父源)和JVM的实现不一样
     *
     */
    boolean emulated() default false;
}
```

###@GwtIncompatible
```
/**
 * 说明一个方法可能无法与 GWT 一起使用
 * 他只能用于被 @GwtCompatible 标志的类的字段,方法和内部类
 *
 */
@Retention(RetentionPolicy.CLASS)
@Target({
        ElementType.TYPE, ElementType.METHOD,
        ElementType.CONSTRUCTOR, ElementType.FIELD })
@Documented
@GwtCompatible
public @interface GwtIncompatible {
    /**
     * 用于表示不兼容 GWT 的原因
     * 
     */
    String value();
}
```

##第三方技术说明
```
Google-Guice:是一个轻量级的DI框架
http://blog.csdn.net/derekjiang/article/details/7231490

Shrinkwrap 是归档操作的 Java API。Shrinkwrap 提供一个简单的 API 来接收类似 Java 的 JARs，WARs 的归档。ShrinkWrap 项目提供一个简单的 API 来程序化的接收代码归档，允许导出 ZIP 或者其他文件格式，使得更快的原型 "虚拟化" 的从资源中归档，比如类路径，文件系统或者远程 URLs。
https://github.com/shrinkwrap/shrinkwrap

```
###maven-assembly-plugin
```
你是否想要创建一个包含脚本、配置文件以及所有运行时所依赖的元素（jar）Assembly插件能帮你构建一个完整的发布包。
Assembly插件会生成 “assemblies”， 此特性等同于的Maven 1 distribution plug-in.。该插件不仅支持创建二进制归档文件，也支持创建源码归档文件。这些assemblies定义在一个assembly描述符文件里。你可以选择自定义assembly描述符或者直接使用插件自带的三个预定义描述符中的任何一个.
目前Assembly插件支持如下格式的归档文件:
zip
tar.gz
tar.bz2
jar
dir
war
and any other format that the ArchiveManager has been configured for
Maven 2上使用assembly的简单步骤:
从预定义描述符里选择一个或者自己编写一个assembly描述符号。
工程的pom.xml里配置Assembly插件。
在工程根目录下运行”mvn assembly:assembly”命令 。
如何自定义assembly描述符，详见Assembly Descriptor Format.
什么是Assembly?
“assembly”是把一组文件、目录、依赖元素组装成一个归档文件. 比如, 假设一个 Maven project定义了一个JAR artifact，它包含控制台应用程序和Swing应用程序 。这样一个工程可以定义两套包含描述符，一套给给控制台应用，另一套给Swing应用程序，它们包含各自的脚本、目录和依赖。
Assembly Plugin的描述符可以定义任何一个文件或者目录归档方式。举个例子，如果的你的Maven 2工程包含”src/main/bin”这个目录，你可以指示Assembly插件复制“src/main/bin”目录下所有的文件到bin目录里（归档文件里的目录），并且可以修改它们的权限属性（UNIX mode）。见 assembly descriptor.
The Maven Assembly Plugin
Maven 2.0的Assembly插件目的是提供一个把工程依赖元素、模块、网站文档等其他文件存放到单个归档文件里。
使用任何一个预定义的描述符你可以轻松的构建一个发布包。这些描述符能处理一些常用的操作,如：把依赖的元素的归档到一个jar文件. 当然, 你可以自定义描述符来更灵活的控制依赖，模块，文件的归档方式。
 
maven-assembly-plugin : 是maven中针对打包任务而提供的标准插件
```

##数据类型
###TypeToken
```
guava反射包中的TypeToken类是用来解决java运行时泛型类型被擦除的问题的，有点不好理解，我们通过一个例子来认识什么是泛型的运行时类型擦除。
ArrayList<String> stringList = Lists.newArrayList();
ArrayList<Integer> intList = Lists.newArrayList();
System.out.println("intList type is " + intList.getClass());
System.out.println("stringList type is " + stringList.getClass());
System.out.println(stringList.getClass().isAssignableFrom(intList.getClass()));

TypeToken的方法列表如下：
方法	描述
getType()	获得包装的java.lang.reflect.Type.
getRawType()	返回大家熟知的运行时类
getSubtype(Class<?>)	返回那些有特定原始类的子类型。举个例子，如果这有一个Iterable并且参数是List.class，那么返回将是List。
getSupertype(Class<?>)	产生这个类型的超类，这个超类是指定的原始类型。举个例子，如果这是一个Set并且参数是Iterable.class，结果将会是Iterable。
isAssignableFrom(type)	如果这个类型是 assignable from 指定的类型，并且考虑泛型参数，返回true。List<? extends Number>是assignable from List，但List没有.
getTypes()	返回一个Set，包含了这个所有接口，子类和类是这个类型的类。返回的Set同样提供了classes()和interfaces()方法允许你只浏览超类和接口类。
isArray()	检查某个类型是不是数组，甚至是<? extends A[]>。
getComponentType()	返回组件类型数组。
```


##主要类
```
DelegatesToInvocationFunction  代表调用功能
```


##错误
```
[ERROR] Failed to execute goal org.apache.maven.plugins:maven-assembly-plugin:2.3:single (source-release-assembly) on project jclouds-all: Execution source-release-assembly of goal org.apache.maven.plugins:maven-assembly-plugin:2.3:single failed: Plugin org.apache.maven.plugins:maven-assembly-plugin:2.3 or one of its dependencies could not be resolved: Failed to collect dependencies at org.apache.maven.plugins:maven-assembly-plugin:jar:2.3 -> org.apache.jclouds:jclouds-assemblies:jar:1.7.0-SNAPSHOT: Failed to read artifact descriptor for org.apache.jclouds:jclouds-assemblies:jar:1.7.0-SNAPSHOT: Could not find artifact org.apache.jclouds:jclouds-project:pom:1.7.0-SNAPSHOT in apache-snapshots (https://repository.apache.org/content/repositories/snapshots) -> [Help 1]
[ERROR] 
[ERROR] To see the full stack trace of the errors, re-run Maven with the -e switch.
[ERROR] Re-run Maven using the -X switch to enable full debug logging.
[ERROR] 
[ERROR] For more information about the errors and possible solutions, please read the following articles:
[ERROR] [Help 1] http://cwiki.apache.org/confluence/display/MAVEN/PluginResolutionException





Docker:version 1.6.2, build ba1f6c3/1.6.2
库名:jcloud-lab  2.0.0-SNAPSHOT
功能: 镜像列表list
错误:
java.lang.NullPointerException: Null parentId
	at org.jclouds.docker.domain.AutoValue_ImageSummary.<init>(AutoValue_ImageSummary.java:30)
	at org.jclouds.docker.domain.ImageSummary.create(ImageSummary.java:48)
	at sun.reflect.NativeMethodAccessorImpl.invoke0(Native Method)
	at sun.reflect.NativeMethodAccessorImpl.invoke(NativeMethodAccessorImpl.java:62)
	at sun.reflect.DelegatingMethodAccessorImpl.invoke(DelegatingMethodAccessorImpl.java:43)
	at java.lang.reflect.Method.invoke(Method.java:497)
	at com.google.common.reflect.Invokable$MethodInvokable.invokeInternal(Invokable.java:197)
	at com.google.common.reflect.Invokable.invoke(Invokable.java:102)
	at org.jclouds.json.internal.DeserializationConstructorAndReflectiveTypeAdapterFactory$DeserializeIntoParameterizedConstructor.newInstance(DeserializationConstructorAndReflectiveTypeAdapterFactory.java:224)
	at org.jclouds.json.internal.DeserializationConstructorAndReflectiveTypeAdapterFactory$DeserializeIntoParameterizedConstructor.read(DeserializationConstructorAndReflectiveTypeAdapterFactory.java:204)
	at org.jclouds.json.internal.NullFilteringTypeAdapterFactories$IterableTypeAdapter.readAndBuild(NullFilteringTypeAdapterFactories.java:90)
	at org.jclouds.json.internal.NullFilteringTypeAdapterFactories$IterableTypeAdapter.read(NullFilteringTypeAdapterFactories.java:82)
	at org.jclouds.json.internal.NullFilteringTypeAdapterFactories$IterableTypeAdapter.read(NullFilteringTypeAdapterFactories.java:61)



```