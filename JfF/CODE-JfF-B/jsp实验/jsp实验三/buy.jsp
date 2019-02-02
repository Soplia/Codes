<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'buy.jsp' starting page</title>
    
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
<%!
int count1=0;
int count2=0;
%>
<% 
String str=request.getParameter("id");
if(str==null)
	str="";
if(str.equals("1"))
{
	count1++;
	session.setAttribute("first",new Integer(count1));
}
else if(str.equals("2"))
{
	count2++;
	session.setAttribute("second",new Integer(count2));
}
int num1=((Integer)session.getAttribute("first")).intValue();


double totalMoney=num1*5.4;

out.print("水杯*"+num1);
out.print("总钱数="+totalMoney);




%>
</body>
</html>
