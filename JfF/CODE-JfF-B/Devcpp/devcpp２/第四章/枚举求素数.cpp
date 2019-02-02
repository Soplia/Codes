/*
	Subject:枚举求素数 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:4-6-2 
	Date_Begin:11/01/17 21:14
	Date_End:11/01/17 21:58
*/
#include <stdio.h>
bool a[10001];
int main()
{	
	int n;
	bool isOutput; 
	while(scanf("%d",&n)!=EOF)
	{
		//当没有合适的数据时，输出-1 
		isOutput=false;
		for(int i=1;i<=n;i++)
			a[i]=true;
		a[1]=false;
		
		//如果写成for(int i=2;i<=n&&a[i];i++)
		//是错的，应为一旦!a[i]成立，循环就终止了 
		for(int i=2;i<=n;i++)
		{
			if(a[i])
				for(int j=2;i*j<=n;j++)
					a[i*j]=false;
		}
		
		for(int i=2;i<=n;i++)
		//注意不要使用a[i]%10==1来进行判断 
			if(a[i]&&i%10==1)
			{
				if(!isOutput)
				{
					isOutput=true;
					printf("%d",i);
				}
				else
					printf(" %d",i);
			}
		if(!isOutput)
			printf("-1\n");		
		else
			printf("\n");
	}
	return 0;
}
/*
测试数据
样例输入
100
5
样例输出
11 31 41 61 71
-1
*/

