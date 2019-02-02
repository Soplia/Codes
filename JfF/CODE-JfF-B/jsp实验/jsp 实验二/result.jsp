<%@ page contentType="text/html;charset=gb2312"%>
<html>
<head><title>result</title></head>
<body>
<%
String str=request.getParameter("input");
int num=0;
if(str!=null)
	num=Integer.parseInt(str);
if(num<0)
	response.setContentType("text/plain");
else if(num>0&&num<100)
{
	response.setContentType("application/msword");
	System.out.println(num*num);
}
else if(num>=100)
	response.setStatus(404);
else 
	response.sendRedirect("input.jsp");
%>
<%="hello"%>
</body>
