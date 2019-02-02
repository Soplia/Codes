#include <stdio.h>
#define N 100

char maze[N][N];
bool hash[N][N];
int ans,row,col;

int go[][2]={
				1,0,
				-1,0,
				0,1,
				0,-1,
				1,1,
				-1,1,
				-1,-1,
				1,-1
			};
			
void init()
{
	ans=0;
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			hash[i][j]=false;
}

void DFS(int x,int y)
{
	for(int i=0;i<8;i++)
	{
		int tx=x+go[i][0];
		int ty=y+go[i][1];
		if(tx<0||tx>=row||ty<0||ty>=col||hash[tx][ty]||maze[tx][ty]=='*')
			continue;
		hash[tx][ty]=true;
		DFS(tx,ty);
	} 
}

int main()
{
	while(scanf("%d%d",&row,&col)!=EOF)
	{
		if(row==0||col==0)
			break;
		init();
		for(int i=0;i<row;i++)
			scanf("%s",maze[i]);
			
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				if(maze[i][j]=='@'&&!hash[i][j])
				{
					ans++;
					DFS(i,j);
				}
		printf("%d\n",ans);
	}
	return 0;
}

			
			/*
测试数据
样例输入
1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
0 0
样例输出
0
1
2
2
*/
