/*
Subject:no0_1
ID:7.9
Complier:Devcpp
Author:JiaruiXie
StartTime:08/02/17 11:57
Result:Accepted
EndTime:08/02/17 12:20
*/
#include <stdio.h>

struct e
{
	int m,w,k;
}list[10001];
int dp[10001];

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int cas;
	while(scanf("%d",&cas)!=EOF)
	{
		while(cas--)
		{
			int m,n;
			scanf("%d%d",&m,&n);
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				int c=1,a,b,cc;
				scanf("%d%d%d",&a,&b,&cc);
				
				while(cc-c>0)
				{
					list[++cnt].m=c*a;
					list[cnt].w=c*b;
					cc-=c;
					c*=2;
				}
				list[++cnt].m=cc*a;
				list[cnt].w=cc*b;
				
			}
				
			for(int i=1;i<=m;i++)
				dp[i]=0;
				
			for(int i=1;i<=cnt;i++)
				for(int j=m;j>=list[i].m;j--)
					dp[j]=max(dp[j],dp[j-list[i].m]+list[i].w);
			printf("%d\n",dp[m]);
			
		}
	}
	return 0;
}
/*
InputData:
1
8 2
2 100 4
4 100 2
OutputData:
400
*/

