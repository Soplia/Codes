/*
Subject:×î¶ÌÂ·¾¶ 
ID:1447
Complier:Devcpp
Author:JiaruiXie
StartTime:24/03/17 07:50
Result:Accepted
EndTime:24/03/17 07:59
*/

#include <stdio.h>
#define N 101

int ans[N][N];

void pre()
{
	for(int i=1;i<N;i++)
	{
		for(int j=1;j<N;j++)
			ans[i][j]=-1;
		ans[i][i]=0;
	}	
}

int main()
{
	int n,m;
	int a,b,c;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		pre();
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			ans[b][a]=ans[a][b]=c;
		}
		
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
				{
					if(ans[i][k]==-1||ans[k][j]==-1)
						continue;
					if(ans[i][j]==-1||ans[i][k]+ans[k][j]<ans[i][j])
						ans[i][j]=ans[i][k]+ans[k][j];
				}
		printf("%d\n",ans[1][n]);
	}
	return 0;
}

/*
InputData:
2 1
1 2 3
3 3
1 2 5
2 3 5
3 1 2
0 0
OutputData:
3
2
*/

