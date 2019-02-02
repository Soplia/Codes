/*
	Subject:Least Common Multiple 
    Compiler:Devcpp
	Description:求两个数的最小公倍数 
	Author:JiaruiXie
	Id:4-5-1
	Date_Begin:11/01/17 21:00
	Date_End:
*/
#include <stdio.h>
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		int ta=a;
		int tb=b;
		while(a!=b)
			if(a>b)	
				a-=b;
			else
				b-=a;
		printf("%d\n",ta*tb/a);
	}
	return 0;
} 
/*
测试数据
样例输入
10 14
样例输出
70
*/

