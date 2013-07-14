<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="s" uri="/struts-tags" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>JSON测试</title>
<script type="text/javascript" src="${pageContext.request.contextPath}/js/prototype/prototype.js"></script>
<script type="text/javascript">
/* //使用javascript语法创建对象
function Person(name,sex){
	this.name=name;
	this.sex=sex;
}
//创建一个Person对象
var p=new Person('liubin','male');
//输出Person实例
alert(p.name);

//JSON语法创建对象
person={
	name:'liubin',
	gender:'male',
	age:25,
	son:{
		name:'jim',
		grade:'1'
	},
	//使用json语法为person直接分配一个方法
	info:function(){
		document.writeln("姓名："+this.name+"性别:"+this.sex);
	}
}


//创建数据对象
var a=new Array();
//为数组元素赋值
a[0]='liubin';
a[1]='jim';
//创建数组对象时直接复制
var b=new Array('yellow','green');
//使用JSON语法创建数组
var c=['one','two']; */

function goClick(){
	//请求URL的地址
	var url="JSONExample.action";
	//favorite 表单域的值转换为请求参数
	var params=Form.serialize('form1');
	alert(params);
	//创建Ajax.Requst对象，对应于发送请求
	var myAjax=new Ajax.Request(
	url,
	{
		//请求方向，POST
		method:'POST',
		//请求参数
		parameters:params,
		//指定回调函数
		onComplete:processResponse,
		//是否异步发送请求
		asynchronous:true
	});
}

function processResponse(request){
	//使用JSON对象将服务器响应解析为JSON对象
	var res=request.responseText.evalJSON();
	alert(res);
	//遍历JSON对象的每个属性
	for(var propName in res){
		$("show").innerHTML +=propName+"----->" + res[propName] + "</br>";
	}
}
</script>
</head>
<body>
<s:form id="form1">
	<s:textfield name="field1" label="Field 1"/>
	<s:textfield name="field2" label="Field 2"/>
	<s:textfield name="field3" label="Field 3"/>
	<tr>
		<td colspan="2">
		<input type="button" value="提交" onclick="goClick();" />
		</td>
	</tr>   
</s:form>
<div id="show">

</div>
</body>
</html>