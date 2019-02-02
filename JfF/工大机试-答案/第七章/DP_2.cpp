/*
Subject:DP_2 
ID:7.6
Complier:Devcpp
Author:JiaruiXie
StartTime:08/02/17 09:23
Result:Accepted
EndTime:08/02/17 10:01
*/
#include <stdio.h>
#define offset 2000

int dp[101][4001];
int list[101];

#define INF 0x7fffffff

int main()
{
	int T;
	int cas=0;
	scanf("%d",&T);
	while(T--)
	{
		int flag=0;
		int cnt=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&list[++cnt]);
			if(list[cnt]==0)
			{
				cnt--;
				flag=1;
			}
		}	
		
		n=cnt;
		
		for(int i=-2000;i<=2000;i++)
			dp[0][i+offset]=-INF;
			
		dp[0][0+offset]=0;
		
		for(int i=1;i<=n;i++)
		{
			for(int j=-2000;j<=2000;j++)
			{
				int temp1=-INF,temp2=-INF;
				
				if(j+list[i]<=2000&&dp[i-1][j+list[i]+offset]!=-INF)
					temp1=dp[i-1][j+list[i]+offset]+list[i];
				if(j-list[i]>=-2000&&dp[i-1][j-list[i]+offset]!=-INF)
					temp2=dp[i-1][j-list[i]+offset]+list[i];
				if(temp1<temp2)
					temp1=temp2;
				if(temp1<dp[i-1][j+offset])
					temp1=dp[i-1][j+offset];
				dp[i][offset+j]=temp1;
			}
			
		}
		printf("Case %d: ",++cas);
		if(dp[n][0+offset]==0)
			puts(flag?"0":"-1");
		else
			printf("%d\n",dp[n][0+offset]/2);
	}
	return 0;
	
}
/*
InputData:
1
5
1 2 3 4 5
OutputData:
Case1:7
*/

