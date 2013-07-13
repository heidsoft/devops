<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>JSP脚本中执行FOR循环</title>
<style type="text/css">
p{
text-indent: 2em;/*段落首行缩进2字符 */
font-size: 20px;/*字体大小 */
font-family: cursive;/*字体-家族 */
}
#t1{
	background-color: #9999dd;
	border: 1px;
}
</style>
</head>
<body>
<p>
	aaaaaaaaaaaaaaqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqreeeeeeeeeeeeeeee
	bbbbbbbbbbbbbbqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqreeeeeeeeeeeeeeeeeeee
	ccccccccccccccqqqqqqqqqqqqqreeeeeeeeeeeeeeeeeeeeeeereeeeeeeeeeeeeeeeeeeee
	ddddddddddddddeeeeerrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
</p>
<table id="t1">
<%
	for(int i=0;i<10;i++){
%>
		<tr>
			<td>循环变量值:</td>
			<td><%=i%></td>
		</tr>
<%
	}
%>

</table>
</body>
</html>