/*
Subject:Tempter 
ID:1461
Complier:Devcpp
Author:JiaruiXie
StartTime:27/03/17 09:34
Result:Accepted
EndTime:31/03/17 10:14
*/

#include <stdio.h>

int go[][2]={
				0,1,
				0,-1,
				1,0,
				-1,0
			};

char maze[8][8];
bool success;
int r,c,t;

void DFS(int x,int y,int time)
{
	for(int i=0;i<4;i++)
	{
		int nx=x+go[i][0];
		int ny=y+go[i][1];
		if(nx<0||nx>=r||ny<0||ny>=c)
			continue;
		if(maze[nx][ny]=='X')
			continue;
		if(maze[nx][ny]=='D')
			if(time+1==t)
			{
				success=true;
				return ;
			}
			else
				continue;
				
		maze[nx][ny]='X';
		DFS(nx,ny,time+1);
		maze[nx][ny]='.';
		
		if(success)
			return ;
	}
}

int main()
{
	while(scanf("%d%d%d",&r,&c,&t)!=EOF)
	{
		if(r==0&&c==0&&t==0)
			break;
			
		for(int i=0;i<r;i++)
			scanf("%s",maze[i]);
		success=false;
		
		int i,j;
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				if(maze[i][j]=='S')
					goto END;
		END:
		maze[i][j]='X';
		DFS(i,j,0);
		if(success)
			puts("YES");
		else
			puts("NO");
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
OutputData:
NO
YES
*/

