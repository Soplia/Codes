/*
Subject:0-1_1
ID:7.7.1
Complier:Devcpp
Author:JiaruiXie
StartTime:08/02/17 10:56
Result:Accepted
EndTime:08/02/17 11:06
*/
#include <stdio.h>

struct e
{
	int t,m;
}list[101];
int dp[1001];

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int t,n;
	
	while(scanf("%d%d",&t,&n)!=EOF)
	{
		//printf("%d_%d\n",t,n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&list[i].t,&list[i].m);
			
		for(int i=0;i<=t;i++)
			dp[i]=0;
			
		for(int i=1;i<=n;i++)
			for(int j=t;j>=list[i].t;j--)
				dp[j]=max(dp[j],dp[j-list[i].t]+list[i].m);
		
		printf("%d\n",dp[t]);
	}
}
/*
InputData:
71 3
70 100
69 1
1 2
OutputData:
3
*/

