/*
Subject:∞·«ﬁ “ 
ID:1452
Complier:Devcpp
Author:JiaruiXie
StartTime:27/03/17 20:26
Result:
EndTime:
*/

#include <stdio.h>
#include <algorithm>
#define N 3000
using namespace std;

int arr[N];

int cmp(int a,int b)
{
	return a<b;
}

int dp[N][N];

int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&arr[i]);
			dp[0][i]=0;
		}
			
		sort(arr+1,arr+n+1,cmp);
		
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k;j++)
				dp[j][i]=min(dp[i-1][j-2]+(arr[j]-arr[j-1])*(arr[j]-arr[j-1]),dp[i][j-1]);
				
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

