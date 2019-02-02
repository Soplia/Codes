/*
	Subject:Oil Deposit
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:6.6
	Date_Begin:03/02/17 12:11
	Result:Accepted
	Date_End:03/02/17 13:15
*/
#include <stdio.h>
#define N 100

int row,col;
int array[N][N];
char maze[N][N];
int go[][2]=
		{
			1,0,
			-1,0,
			0,-1,
			0,1,
			1,1,
			1,-1,
			-1,1,
			-1,-1
		};
		
void DFS(int x,int y)
{
	for(int i=0;i<8;i++)
	{
		int nx=x+go[i][0];
		int ny=y+go[i][1];
		if(nx<0||nx>=row||ny<0||ny>=col)
			continue;
		if(maze[nx][ny]=='*')
			continue;
			
		maze[nx][ny]='*';
		DFS(nx,ny);
	}
}

int main()
{
	while(scanf("%d%d*%c",&row,&col)!=EOF)
	{
		//getchar();
		if(row==0||col==0)
			break;
		for(int i=0;i<row;i++)
			scanf("%s",maze[i]);
				
		int ans=0;
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				if(maze[i][j]=='@')
				{
					ans++;
					DFS(i,j);
				}
		printf("%d\n",ans);
	}
	return 0;
}

/*
InputData:
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
outputData:
0
1
2
2
*/



