<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>声明示例</title>
</head>
<body>
<!-- 下面是JSP声明部分 -->
<%!
//声明一个整形变量
public int count;
//声明一个方法
public String info()
{
	return "hello";
}
%>
</body>
<%
//将count的值输出后加1
out.println(count++);
%>
</br>
<%
//输出info()方法的返回值
out.println(info());
%>
</html>