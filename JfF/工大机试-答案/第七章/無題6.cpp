#include<stdio.h>
#define inf 0x7fffffff

int min(int a,int b)
{
	return a<b?a:b;
}

struct e
{
	int w,v;
}list[1001];
int dp[10001];

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
