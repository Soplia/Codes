/*
	Subject:输入一个名字字符串，将其姓和名的首字母大写 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:10
	Date_Begin:16/01/17 20:52
	Date_End:
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 20
int main()
{
	char name[N];
	gets(name);
	int i=0;
	while(!isalpha(name[i]))
		i++;
	
	name[i]=toupper(name[i]);
	
	while(!isspace(name[i]))
		i++;
	while(!isalpha(name[i]))
		i++;
		
	name[i]=toupper(name[i]);
	
	puts(name);
	return 0;
}
/*
测试数据
样例输入
jiarui xie
    jiarui xie
样例输出
Jiarui Xie
    Jiarui xie
*/

