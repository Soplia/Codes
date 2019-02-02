/*
  	Subject:魔术师 
	ID:7.10
	Complier:Devcpp
	Author:JiaruiXie
	StartTime:31/01/17 17:10
	EndTime:31/01/17 17:17
*/
#include <stdio.h>
#define N 1000

int array[N];

void pre()
{
	for(int i=100;i<=999;i++)
	{
		int abc=i;
		int c=abc%10;
		abc/=10;
		int b=abc%10;
		abc/=10;
		int a=abc;
		array[i]=100*(a+b+b+c+c)+10*(c+a+c+a+b)+(b+c+a+b+a);
	}
}

int search(int a)
{
	for(int i=100;i<=999;i++)
		if(array[i]==a)
			return i;
	return -1;
}

int main()
{
	pre();
	int a;
	scanf("%d",&a);
	printf("%d\n",search(a));
	return 0;
}

/*
测试数据
样例输入
1999
1998
样例输出
443
-1
*/




















