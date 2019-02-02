/*
	Subject:递归回溯_Temple_of_the_bone
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:6-5-2 
	Date_Begin:20/01/17 17:18
	Date_End:
*/
#include <stdio.h>
#define N 100

char maze[N][N];
bool success;
int row,col,time;

int go[][2]=
			{
				1,0,
				-1,0,
				0,1,
				0,-1,
			};
			
void DFS(int x,int y,int t)
{
	for(int i=0;i<4;i++)
	{
		int tx=x+go[i][0];
		int ty=y+go[i][1];
		if(maze[tx][ty]=='X'||tx<0||tx>=row||ty<0||ty>=col)
				continue;
				
		if(maze[tx][ty]=='D'&&t+1==time)
		{
			success=true;
			return ;
		}
		
		maze[tx][ty]='X';
		DFS(tx,ty,t+1);
		maze[tx][ty]='.';
		
		if(success)
			return ;
	}
}

int main()
{
	while(scanf("%d%d%d",&row,&col,&time))
	{
		success=false;
		if(row==0||col==0||time==0)
			break;
		for(int i=0;i<row;i++)
			scanf("%s",maze[i]);
		
		int sx,sy,dx,dy;
		for(int i=0;i<row;i++)	
			for(int j=0;j<col;j++)
				if(maze[i][j]=='S')
				{
					sx=i;
					sy=j;
					//printf("sx=%d,sy=%d\n",sx,sy);
				}
				else if(maze[i][j]=='D')
				{
					dx=i;
					dy=j;
				//	printf("dx=%d,dy=%d\n",dx,dy);
				}
				
		int f1=(sx+sy)&1;
		int f2=(dx+dy)&1;
		int f3=time&1;
		if(f1==0&&f2==0&&f3==1)
		{
			printf("NO\n");
			break;
		}
		else
		{
			maze[sx][sy]='X';
			DFS(sx,sy,0);
		}
		printf("%s\n",success?"YES":"NO");
	}
	
	return 0;
}
/*
测试数据
样例输入
4 4 5
S.X.
..X.
..XD
....
3 4 5
S.X.
..X.
...D
0 0 0 
样例输出
NO
YES
*/



























