<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>JSP表达式</title>
</head>
<body>
<%!
public int count;
public String info()
{
	return "hello";
}
%>
</body>
<!-- 使用表达式输出变量值 -->
<%=count++%>
<br/>
<!-- 使用表达式输出方法返回值 -->
<%=info()%>
</html>