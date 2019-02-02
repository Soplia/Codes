/*
Subject:complete_0_1
ID:7.8
Complier:Devcpp
Author:JiaruiXie
StartTime:08/02/17 11:14
Result:Accepted
EndTime:08/02/17 11:42
*/
#include <stdio.h>
#define inf 0x7fffffff

struct e
{
	int w,v;
}list[1001];
int dp[10001];

int min(int a,int b) 
{
	return a<b?a:b;
}

int main()
{
	int cas;
	while(scanf("%d",&cas)!=EOF)
	{
		while(cas--)
		{	
			int empty,full,n;
			scanf("%d%d",&empty,&full);
			full-=empty;
			
			scanf("%d",&n);
			for(int i=1;i<=n;i++)
				scanf("%d%d",&list[i].v,&list[i].w);
			
			for(int i=0;i<=full;i++)
				dp[i]=inf;
			dp[0]=0;
			
			for(int i=1;i<=n;i++)
				for(int j=list[i].w;j<=full;j++)	
					if(dp[j-list[i].w]!=inf)
						dp[j]=min(dp[j],dp[j-list[i].w]+list[i].v);
			
			if(dp[full]!=inf)
				printf("The minimum amount of money in the piggy-bank is %d.\n",dp[full]);
			else
				printf("This is impossible.\n");
		
		}
	}
	return 0;
}
/*
InputData:
3
10 110
2
1 1
30 50
10 110
2
1 1
50 30
1 6
2
10 3
20 4
OutputData:
The minimum amount of money in the piggy-bank is 60.
The minimum amount of money in the piggy-bank is 100.
This is impossible.
*/

