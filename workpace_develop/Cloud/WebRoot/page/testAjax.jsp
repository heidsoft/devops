<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@taglib prefix="s" uri="/struts-tags" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>使用JSON插件</title>
<script type="text/javascript" src="../js/jquery/jquery-2.0.1.js"></script>

</head>
<body>
<s:form id="loginForm">
	<s:textfield name="user" label="用户名"/>
	<s:textfield name="pass" label="密码" />
	<tr>
	<td colspan="2">
	<input id="loginBn" type="button" value="提交"/>
	</td>
	</tr>
</s:form>
<div id="show" style="display:none;">
</div>
<script type="text/javascript">
	
	$("#loginBn").click(function(){
		console.log($("#loginForm").serializeArray());
		console.log("helloworld");
		$.get("loginPro",$("#loginForm").serializeArray(),
			//指定回调函数
			function(data,statusText)
			{
				$("#show").height(80)
						  .width(300)
						  .css("border","1px solid black")
						  .css("background-color","#efef99")
						  .css("color","#ff0000")
						  .css("padding","20px")
						  .empty();
				$("#show").append("登录结果:"+data+"<br />");
				$("#show").show(2000);
			},
			//指定服务器响应为html
			"html");
	});
</script>
</body>
</html>