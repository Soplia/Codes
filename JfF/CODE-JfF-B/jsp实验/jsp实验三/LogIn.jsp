<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@ page import="java.sql.*" %>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'LogIn.jsp' starting page</title>
    
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
<form action="" method="post">
<table border="2">
<tr><th colspan="2">用户登录</th></tr>
<tr><td>用户名</td><td><input type="text" name="userName"></input></td></tr>
<tr><td>密码</td><td><input type="password" name="userPassword"></input></td></tr>
<tr><td><input type="submit" value="提交"></input></td><td align="center"><input type="reset" value="重置"></input></td></tr>
</table>
</form>
</center>
<%!
int count=0;
String password="";
 Connection con;
  Statement sta;
  ResultSet res;

%>

<%

    try
        {
      
        	Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
                
              
        	con=DriverManager.getConnection("jdbc:sqlserver://localhost:1433;databaseName=BookDJ","sa","123321");
               
            sta=con.createStatement();
            String sql="select password from admin where name='xiejiarui' ";
            res=sta.executeQuery(sql);
           
         
            while(res.next())
            {
            //out.print(res.getString(1));
            password=res.getString(1);
            }
            
        }
        catch(Exception e)
        {
        	e.printStackTrace();
        }
        
%>

<%
session.setAttribute("count",new Integer(count));
count++;

String str1=request.getParameter("userName");
if(str1==null)
	str1="";
String str2=request.getParameter("userPassword");
if(str2==null)
	str2="";
if(str1.equals("xiejiarui")&&str2.equals(password))
	response.sendRedirect("goodsList.jsp");
else if(((Integer)session.getAttribute("count")).intValue()!=0)
	out.println("第 "+((Integer)session.getAttribute("count")).intValue()+" 次密码输入错误，请重新填写!");
session.setAttribute("count",new Integer(count));
%>



</body>
</html>
