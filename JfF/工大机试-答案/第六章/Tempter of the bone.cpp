/*
	Subject:Tempter of the bone
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:6.7
	Date_Begin:03/02/17 13:22
	Result:Accepted
	Date_End:05/02/17 11:40
*/
#include <stdio.h>
#define N 100

char maze[N][N];
int dx,dy;
int row,col,time;
int flag;

int go[][2]=
			{
				0,1,
				0,-1,
				1,0,
				-1,0	
			};

void DFS(int x,int y,int t)
{
	for(int i=0;i<4;i++)
	{
		int nx=x+go[i][0];
		int ny=y+go[i][1];
		if(nx<0||nx>=row||ny<0||ny>=col)
			continue;
			
		if(maze[nx][ny]=='X')
			continue;
			
		if(maze[nx][ny]=='D')
			if(t+1==time)
			{
				flag=1;
				return ;
			}
			else
				continue;
				
		maze[nx][ny]='X';
		DFS(nx,ny,t+1);
		maze[nx][ny]='.';
		
		if(flag)
			return ;
	}
}

int main()
{
	while(scanf("%d%d%d",&row,&col,&time)!=EOF)
	{
		if(row==0||col==0)
			break;
		
		flag=0;
		
		for(int i=0;i<row;i++)	
			scanf("%s",maze[i]);
			
		for(int i=0;i<row;i++)	
			for(int j=0;j<col;j++)
				if(maze[i][j]=='D')
				{
					dx=i;
					dy=j;
					break;
				}
				
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				if(maze[i][j]=='S'&&(i+j)%2==((dx+dy)%2+time%2)%2)
				{
					maze[i][j]='X';
					DFS(i,j,0);
				}
		puts(flag?"YES":"NO");
	}
	return 0;
}
/*
InputData:
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
outputData:
NO
YES
*/























