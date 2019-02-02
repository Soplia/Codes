/*
	SubjectŸ—˜‘å“¦–Sy‚Æ‚¤‚Ú‚¤z 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:6.2
	Date_Begin:03/02/17 08:45
	Result:Accepted
	Date_End:03/02/17 10:25
*/

#include <stdio.h>
#include <queue>
#define N 50
using namespace std;

typedef struct s
{
	int x,y,z;
	int t;
}S;

int go[][3]=
		{
			1,0,0,
			-1,0,0,
			0,1,0,
			0,-1,0,
			0,0,1,
			0,0,-1	
		};

int maze[N][N][N];
queue<S> myQ;
int cnt=0;

void disM(int nz,int nx,int ny)
{
	for(int i=0;i<nz;i++)
	{
		for(int j=0;j<nx;j++)
		{
			for(int k=0;k<ny;k++)
				printf("%-2d",maze[i][j][k]);
			printf("\n");
		}
		printf("\n");
	}
}
int BFS(int a,int b,int c)
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
			
			if(nx<0||nx>=b||ny<0||ny>=c||nz<0||nz>=a)
				continue;
			//Ÿˆ‚Å–â‘è‚ª—L‚è‚Ü‚·
			if(maze[nz][nx][ny])
			//if(maze[nx][ny][nz])
				continue;
			
			maze[nz][nx][ny]=1;
			//maze[nx][ny][nz]=1;
			
			S nte;
			nte.x=nx;
			nte.y=ny;
			nte.z=nz;
			nte.t=te.t+1;
			myQ.push(nte);
			//printf("‘æ%dŸ\n",++cnt);
			//disM(3,3,4);
			//printf("x=%d,y=%d,z=%d,t=%d\n",nx,ny,nz,nte.t);
			//if(nx==a-1&&ny==b-1&&nz==c-1)
			if(nz==a-1&&nx==b-1&&ny==c-1)
				return nte.t;
			
		}
	}
	return -1;
}


int main()
{
	int size;
	scanf("%d",&size);
	int x,y,z,t;
	while(size--)
	{
		scanf("%d%d%d%d",&z,&x,&y,&t);
		for(int i=0;i<z;i++)
			for(int j=0;j<x;j++)
				for(int k=0;k<y;k++)
					scanf("%d",&maze[i][j][k]);
		//disM(z,x,y);
		while(!myQ.empty())
			myQ.pop();
		S temp;
		temp.x=0;
		temp.y=0;
		temp.z=0;
		temp.t=0;
		maze[0][0][0]=1;
		myQ.push(temp);
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



