<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@taglib  prefix="s" uri="/struts-tags"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>OGNL测试</title>
</head>
<body>
	<s:form action="testMapOgnl">
		<!-- 该表单域封装的请求参数名为user.name -->
		<s:textfield name="users[one].name" label="第one个用户名"/>
		<s:textfield name="users[one].pass" label="第one个密码"/>
		<s:textfield name="users[two].name" label="第two个用户名"/>
		<s:textfield name="users[two].pass" label="第two个密码"/>
	
		<tr>
			<td colspan="2">
				<s:submit value="转换" theme="simple"/>
				<s:reset value="重填" theme="simple"/>
			</td>
		</tr>
	</s:form>
</body>
</html>