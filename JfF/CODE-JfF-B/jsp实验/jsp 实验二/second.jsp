<%@ page contentType="text/html;charset=gb2312"%>
<html>
<head><title>second</title></head>
<body>
<%
String name;
name=request.getParameter("text_first");
String sex;
sex=request.getParameter("radio_first");
String sport;
sport=request.getParameter("select_first");
String fruit[];
fruit=request.getParameterValues("check_first");
%>

<%="����:"+name+"<br>"%>
<%="�˶�:"+sport+"<br>"%>
<%="�Ա�:"+sex+"<br>"%>
<%="ˮ��:"%>
<%
for(int i=0;i<fruit.length;i++)
	if(fruit[i]!=null)
		out.println(fruit[i]);
%>
</body>
</html>
