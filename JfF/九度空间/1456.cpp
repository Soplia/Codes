/*
Subject:胜利大逃亡 
ID:1456
Complier:Devcpp
Author:JiaruiXie
StartTime:26/03/17 19:55
Result:Accepted
EndTime:26/03/17 20:13
*/

#include <stdio.h>
#include <queue>
#define N 51
using namespace std;

typedef struct stu
{
	int x,y,z;
	int t;
}Stu;

queue<Stu> myQ;

int go[][3]={
				0,0,1,
				0,0,-1,
				0,1,0,
				0,-1,0,
				1,0,0,
				-1,0,0
			};
			
int maze[N][N][N];

void pre()
{
	while(!myQ.empty())	
		myQ.pop();
}
//构建一个队列，将所有符合的状态都存入队列中
//这样就将状态进行了扩展
//只要一旦发现了相应的状态就返回相应的时间
//也就实现了发现最有的解 
int BFS(int a,int b,int c)
{
	while(!myQ.empty())
	{
		Stu temp=myQ.front();
		myQ.pop();
		for(int i=0;i<6;i++)
		{
			int nx=temp.x+go[i][0];
			int ny=temp.y+go[i][1];
			int nz=temp.z+go[i][2];
			if(nx<0||nx>=a||ny<0||ny>=b||nz<0||nz>=c)
				continue;
			if(maze[nx][ny][nz])
				continue;
			Stu t;
			t.x=nx;
			t.y=ny;
			t.z=nz;
			t.t=temp.t+1;
			maze[nx][ny][nz]=1;
			myQ.push(t);
			if(nx==a-1&&ny==b-1&&nz==c-1)
				return t.t;
		}
	}
	return -1;
}

int main()
{
	int cas;
	int a,b,c,te;
	scanf("%d",&cas);
	while(cas--)
	{
		pre();
		scanf("%d%d%d%d",&a,&b,&c,&te);
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				for(int k=0;k<c;k++)
					scanf("%d",&maze[i][j][k]);
		
		Stu t;
		t.x=t.y=t.z=t.t=0;
		maze[0][0][0]=1;
		myQ.push(t);
		
		int ret=BFS(a,b,c);
		if(ret<=te)
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
OutputData:
11
*/

