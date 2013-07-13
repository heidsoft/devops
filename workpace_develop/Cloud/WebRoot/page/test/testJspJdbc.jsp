<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>'
<%@ page import="java.sql.*" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>JSP连接JDBC</title>
</head>
<body>
<%
	//注册数据库驱动
	Class.forName("com.mysql.jdbc.Driver");
	//获取数据库连接
	Connection con=DriverManager.getConnection(
			"jdbc:mysql://localhost:3306/javaee","root","password"
	);
	//创建Statement
	Statement stmt=conn.createStatement();
	//执行查询
	ResultSet rs = stmt.executeQuery("select * from news_id");
	//
%>
<%
//遍历结果集
while(rs.next())
{	
%>
	<tr>
		<!-- 输出结果集 -->
		<td><%=rs.getString(1) %></td>
		<td><%=rs.getString(2) %></td>
	</tr>
<%
}
%>
</body>
</html>