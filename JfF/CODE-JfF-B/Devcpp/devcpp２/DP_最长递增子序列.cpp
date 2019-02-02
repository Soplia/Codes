/*
	Subject:DP_最长递增子序列 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:7-2-1 
	Date_Begin:21/01/17 16:00
	Date_End:21/01/17 16:25
*/
#include  <stdio.h>
#define N 100

int list[N];
int dp[N];

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int size;
	while(scanf("%d",&size)!=EOF)
	{
		for(int i=0;i<size;i++)	
			scanf("%d",&list[i]);
		 
		for(int i=0;i<size;i++)
		{
			int tmax=1;
			for(int j=0;j<i;j++)
				if(list[j]>=list[i])
					tmax=(tmax,dp[j]+1);
			dp[i]=tmax;
		}
		int ans=1;
		for(int i=0;i<size;i++)
			ans=max(ans,dp[i]);
		printf("%d\n",ans);
	}
	return 0;
}

/*
测试数据
样例输入
8
300 27 155 300 299 170 158 65
样例输出
6
*/

