Spring Security  
```
为基于J2EE企业应用软件提供了全面安全服务。特别是使用领先的J2EE解决方案-Spring框架开发的企业软件项目。
人们使用Spring Security有很多种原因，不过通常吸引他们的是在J2EE Servlet规范或EJB规范中找不到典型企业应用场景的解决方案。

特别要指出的是他们不能再WAR 或 EAR 级别进行移植。这样，如果你更换服务器环境，就要，在新的目标环境进行大量的工作，对你的应用系统进行重新配 置安全。
使用Spring Security  解决了这些问题，也为你提供很多有用的，完全可以指定的其他安全特性。

安全包括两个主要操作。

第一个被称为认证，是为用户建立一个他所声明的主体。主题一般式指用户，
设备或可以在你系统中执行动作的其他系统。授权指的是一个用户能否在你的应用中执行某个操作，
在到达授权判断之前，身份的主题已经由 身份验证过程建立了。
这些概念是通用的，不是Spring Security特有的。
在身份验证层面，Spring  Security广泛支持各种身份验证模式，这些验证模型绝大多数都由第三方提供，或则正在开发的有关标准机构提供的，
例如 Internet  Engineering Task Force.作为补充，Spring Security 也提供了自己的一套验证功能。

Spring Security 目前支持认证一体化如下认证技术：
HTTP BASIC authentication headers (一个基于IEFT  RFC 的标准)
HTTP Digest authentication headers (一个基于IEFT  RFC 的标准)
HTTP X.509 client certificate exchange  (一个基于IEFT RFC 的标准)
LDAP (一个非常常见的跨平台认证需要做法，特别是在大环境)
Form-based authentication (提供简单用户接口的需求)
OpenID authentication
Computer Associates Siteminder
JA-SIG Central Authentication Service  (CAS，这是一个流行的开源单点登录系统)
Transparent authentication context  propagation for Remote Method Invocation and HttpInvoker  (一个Spring远程调用协议)