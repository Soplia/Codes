<%@ page contentType="text/html;charset=gb2312"%>
<html>
<head><title>first</title></head>
<body>
<form method="post" action="second.jsp">
<h2>个人兴趣爱好调查</h2>
<p>请输入你的姓名</p>
<input type="text" name="text_first"/>
</p>
<p>选择您喜欢的水果</p>
<input type="checkbox" name="check_first" value="apple">苹果</input>
<input type="checkbox" name="check_first" value="banana">香蕉</input>
<input type="checkbox" name="check_first" value="orange">橘子</input>
</p>
<p>选择您的性别</p>
<input type="radio" name="radio_first" value="boy">男</input>
<input type="radio" name="radio_first" value="girl">女</input>
</p>
<p>选择您喜欢的运动</p>

<select name="select_first" size="1">
<option value="swim">游泳
<option value="run">跑步
<option value="basketball">打篮球
<option value="pingpang">打乒乓球
</select>

</p>
<input type="submit" value="提交"/>
<input type="reset" value="重置"/>
</p>
</select>
</form>
</body>
</html>