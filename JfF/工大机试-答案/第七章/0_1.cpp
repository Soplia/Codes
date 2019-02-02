/*
Subject:0_1
ID:7.7
Complier:Devcpp
Author:JiaruiXie
StartTime:08/02/17 10:39
Result:Accepted
EndTime:08/02/17 10:48
*/
#include <stdio.h>
#define inf 0x7fffffff

struct node
{
	int t,m;
}list[101];
int dp[101][1001];

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int t,n;
	while(scanf("%d%d",&t,&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%d%d",&list[i].t,&list[i].m);
		
		for(int i=1;i<=t;i++)
			dp[0][i]=0;
		
		for(int i=1;i<=n;i++)
		{
			for(int j=t;j>=list[i].t;j--)
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-list[i].t]+list[i].m);
		
			for(int j=list[i].t-1;j>=0;j--)
				dp[i][j]=dp[i-1][j];
		}
		printf("%d\n",dp[n][t]);
		
	}
	return 0;
}
/*
InputData:
70 3
71 100
69 1
1 2
OutputData:
3
*/

