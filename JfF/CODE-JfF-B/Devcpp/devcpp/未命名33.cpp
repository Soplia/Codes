//编程实现两个字符串的连接, 但不能使用strcat函数
#include<stdio.h>
#include<string.h>

//编程连接实现连接两个字符串 
int main()
{
	char a[50],b[50],a_b[100];
	printf("Input the first array:\n");
	gets(a);
	printf("Input the second array:\n");
	gets(b);
	int i=0;
	for(;i<strlen(a);i++)
		a_b[i]=a[i];
	for(;i<strlen(b)+strlen(a);i++)
		a_b[i]=b[i-strlen(a)];
	puts(a_b);
	return 0;
}
