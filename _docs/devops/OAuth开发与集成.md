```
java.lang.NoSuchMethodError: org.springframework.security.web.access.expression.WebSecurityExpressionRoot.setDefaultRolePrefix(Ljava/lang/String;)V
```

```
spring @Qualifier注解
@Autowired是根据类型进行自动装配的。
如果当Spring上下文中存在不止一个UserDao类型的bean时，
就会抛出BeanCreationException异常;
如果Spring上下文中不存在UserDao类型的bean，也会抛出BeanCreationException异常。
我们可以使用@Qualifier配合@Autowired来解决这些问题。如下：
```