<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'goodList.jsp' starting page</title>
    
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->

  </head>
 <body>
<center>
<table border="2" align="center" width="300" height="200">
<tr><td colspan="3">欢迎来到购物中心</td></tr>
<tr><td>名称</td><td>单价</td><td>购物</td></tr>
<tr><td>水杯</td><td>5.4</td><td><a href="buy.jsp?id=1">购物</a></td></tr>
<tr><td>手机</td><td>1300</td><td><a href="buy.jsp?id=2">购物</a></td></tr>
</table>
</ceneter>
</body>
</html>
