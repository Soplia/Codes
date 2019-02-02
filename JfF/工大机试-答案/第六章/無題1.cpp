#include <stdio.h>
#include <queue>
#define N 50
using namespace std;
typedef struct s
{
	int x,y,z;
	int t;
}S;

int maze[N][N][N];
queue<S> myQ;

int go[][3]=
		{
			1,0,0,
			-1,0,0,
			0,1,0,
			0,-1,0,
			0,0,1,
			0,0,-1	
		};
		
int BFS(int cz,int cx,int cy)		
{
	while(!myQ.empty())
	{
		S te=myQ.front();
		myQ.pop();
		for(int i=0;i<6;i++)
		{
			int nx=te.x+go[i][0];
			int ny=te.y+go[i][1];
			int nz=te.z+go[i][2];
			if(nx<0||nx>=cx||ny<0||ny>=cy||nz<0||nz>=cz)
				continue;
			if(maze[nz][nx][ny])
				continue;
			S ne;
			ne.x=nx;
			ne.y=ny;
			ne.z=nz;
			ne.t=te.t+1;
			maze[nz][nx][ny]=1;
			myQ.push(ne);
			if(nx==cx-1&&ny==cy-1&&nz==cz-1)
				return ne.t;
		}
	}
	return -1;
}
		
int main()
{
	int size;
	scanf("%d",&size);
	while(size--)
	{
		int x,y,z,t;
		scanf("%d%d%d%d",&z,&x,&y,&t);
		for(int i=0;i<z;i++)
			for(int j=0;j<x;j++)
				for(int k=0;k<y;k++)
					scanf("%d",&maze[i][j][k]);
		S te;
		te.x=te.y=te.z=te.t=0;
		maze[0][0][0]=1;
		
		myQ.push(te);
		int ret=BFS(z,x,y);
		if(ret<=t)
			printf("%d\n",ret);
		else
			printf("-1\n");
	}
	return 0;
}		
		
/*
InputData:
1
3 3 4 20

0 1 1 1
0 0 1 1 
0 1 1 1

1 1 1 1
1 0 0 1
0 1 1 1

0 0 0 0
0 1 1 0
0 1 1 0
outputData:
11
*/		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
