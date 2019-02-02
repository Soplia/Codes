/*
	Subject:数制转换_A+B 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:4-3-1 
	Date_Begin:11/01/17 19:32
	Date_End:
*/
#include <stdio.h>

int main()
{
	int m;
	//防止两个int相加溢出 
	long long a,b;
	int buf[50];
	while(scanf("%d",&m)!=EOF)
	{
		if(m==0)
			break;
		scanf("%lld%lld",&a,&b);
		long long temp=a+b;
		int size=0;
		while(temp/m!=0)	
		{
			buf[size++]=temp%m;
			temp/=m;
		}
		buf[size]=temp;
		for(int i=size;i>=0;i--)
			printf("%d",buf[i]);
		printf("\n");
	}
	return 0;
}
/*
测试数据
样例输入
8 1300 48
2 1 7
0 
样例输出
2504
1000
*/

