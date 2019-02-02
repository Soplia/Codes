/*
Subject:DP_1
ID:7.5
Complier:Devcpp
Author:JiaruiXie
StartTime:07/02/17 09:53
Result:Accepted
EndTime:07/02/17 10:07
*/
#include <stdio.h>
#include <algorithm> 
#define INF 0x7fffffff
using namespace std;

int dp[1001][2001];
int list[2001];

int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&list[i]);
			
		sort(list+1,list+1+n);
		
		for(int i=1;i<=n;i++)
			dp[0][i]=0;
		
		for(int i=1;i<=k;i++)
			for(int j=i*2;j<=n;j++)
			{
				if(j>2*i)
					dp[i][j]=dp[i][j-1];
				else
					dp[i][j]=INF;
					
				if(dp[i][j]>dp[i-1][j-2]+(list[j]-list[j-1])*(list[j]-list[j-1]))
					dp[i][j]=dp[i-1][j-2]+(list[j]-list[j-1])*(list[j]-list[j-1]);
							
			}
		printf("%d\n",dp[k][n]);
	}
	return 0;
}
/*
InputData:
2 1
1 3
OutputData:
4
*/

