/*
	Subject:Floyd_最短路径 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:4-4-1 
	Date_Begin:17/01/17 20:38
	Date_End:18/01/17 14:36
*/
#include <stdio.h>
#define N 200

int ans[N][N];

void init()
{
	for(int i=1;i<N;i++)
	{
		for(int j=1;j<N;j++)
			ans[i][j]=-1;
		ans[i][i]=0;
	}
}

int floyd(int x)
{
	for(int k=1;k<=x;k++)
		for(int i=1;i<=x;i++)	
			for(int j=1;j<=x;j++)
			{
				int t=ans[i][k]+ans[k][j];
				if(ans[i][k]==-1||ans[k][j]==-1)
					continue;
				if(ans[i][j]==-1||ans[i][j]>t)
					ans[i][j]=t;
			}
	return ans[1][x];
}

int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		init();
		if(a==0&&b==0)
			break;
		while(b--)
		{
			int i,j,k;
			scanf("%d%d%d",&i,&j,&k);
			ans[i][j]=ans[j][i]=k;
		}
		
		printf("%d\n",floyd(a));
	}
	return 0;
}

/*
测试数据
样例输入
2 1
1 2 3
3 3 
1 2 5
2 3 5
3 1 2
0 0
样例输出
3
2
*/















