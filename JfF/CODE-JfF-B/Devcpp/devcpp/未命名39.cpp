//用extern声明外部变量，扩展全局变量的作用域
#include <stdio.h>

int max(int ,int );

int main()
{
	extern int a,b;
	printf("%d\n",max(a,b));
}

int a=1,b=2;

int max(int a,int b)
{
	return a>b?a:b;
}
