/*
	Subject:二分求阶乘 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:4-8-1 
	Date_Begin:14/01/17 20:33
	Date_End:14/01/17 20:39
*/
#include <stdio.h>

int main()
{
	int ans;
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if(a==0&&b==0)
			break;
		ans=1;
		while(b!=0)
		{
			if(b%2==1)
			{
				ans*=a;
				ans%=1000;
			}
			a*=a;
			a%=1000;
			b/=2;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}

/*
测试数据
样例输入
2 3
12 6
6789 10000
0 0
样例输出
8
984
1
*/
























