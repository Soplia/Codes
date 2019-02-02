#include <stdio.h>
#define inf 0x7fffffff
#define offset 2000

int list[101];
int dp[101][4001];

int main()
{
	int t;
	int cas=0;
	while(t--)
	{
		int n;
		int flag=0;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&list[++cnt]);
			if(!list[cnt])
			{
				cnt--;
				flag=1;
			}
		}
		
		n=cnt;
		for(int i=-2000;i<=2000;i++)
			dp[0][i+offset]=-inf;
			
		dp[0][offset]=0;
		
		for(int i=1;i<=n;i++)
		{
			for(int j=-2000;j<=2000;j++)
			{
				int temp1=-inf,temp2=-inf;
				if(list[i]+j<=2000&&dp[i-1][j+list[i]+offset]+list[i]!=-inf)
					temp1=dp[i-1][j+list[i]+offset]+list[i];
				if(j-list[i]>=-2000&&dp[i-1][j-list[i]+offset]+list[i]!=-inf)
					temp2=dp[i-1][j-list[i]+offset]+list[i];
				if(temp1<temp2)
					temp1=temp2;
				if(temp1<dp[i-1][j+offset])
					temp1=dp[i-1][j+offset];
				dp[i][j+offset]=temp1;
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
