<%@ page contentType="text/html;charset=gb2312"%>
<html>
<head><title>fifth</title></head>
<body>
<h1>Please select your goods!</h1>
<form action="" method="post">
<input type="checkbox" name="fruit" value="apple">apple</input>
<input type="checkbox" name="fruit" value="orange">orange</input>
<input type="checkbox" name="fruit" value="banana">banana</input>
<input type="checkbox" name="fruit" value="waterwell">waterwell</input>
</p>
<input type="submit"  value="fasong"/>
</form>
<%
String arr[]=request.getParameterValues("fruit");
for(int i=0;i<arr.length;i++)
out.println(arr[i]);
%>

</body>
</html>
