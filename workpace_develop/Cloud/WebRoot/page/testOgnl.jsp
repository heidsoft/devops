<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@taglib  prefix="s" uri="/struts-tags"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>OGNL测试</title>
</head>
<body>
	<s:form action="testOgnl">
		<!-- 该表单域封装的请求参数名为user.name -->
		<s:textfield name="user.name" label="用户名"/>
		<!-- 该表单域封装的请求参数名为user.pass -->
		<s:textfield name="user.pass" label="密码"/>
	
		<tr>
			<td colspan="2">
				<s:submit value="转换" theme="simple"/>
				<s:reset value="重填" theme="simple"/>
			</td>
		</tr>
	</s:form>
</body>
</html>