/*
	Subject:BSF_MAZE 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:6-2-1
	Date_Begin:19/01/17 15:59
	Date_End:19/01/17 16:41
*/
#include <stdio.h>
#include <queue>
#define N 50
using namespace std;

//状态结构体
typedef struct state
{
	int x,y,z;
	int t;	
}Sta;


//记录当前状态是否被扩展过 
bool mark[N][N][N];
//存放待扩展的状态
queue<Sta> myQ;
//存放地图
int maze[N][N][N];
//存放转移方法 
int go[][3]={
				1,0,0,
				-1,0,0,
				0,1,0,
				0,-1,0,
				0,0,1,
				0,0,-1
			};

int bMaze(int a,int b,int c)
{
	//只要还有路可走，那就走 
	while(!myQ.empty())	
	{
		Sta t=myQ.front();
		myQ.pop();
		
		//对当前状态进行6个方向的扩展
		for(int i=0;i<6;i++) 
		{
			int x=t.x+go[i][0];
			int y=t.y+go[i][1];
			int z=t.z+go[i][2]; 
			if(x>=a||y>=b||z>=c||x<0||y<0||z<0)
				continue;
			if(mark[x][y][z])
				continue;
			if(maze[x][y][z])
				continue;
			if(x==a-1&&y==b-1&&z==c-1)
				return t.t+1;
			Sta temp;
			temp.x=x;
			temp.y=y;
			temp.z=z;
			temp.t=t.t+1;
			myQ.push(temp);
		}
	}
	return -1;
}			

int main()
{
	int a,b,c,t;
	int size;
	while(scanf("%d",&size)!=EOF)
	{
		scanf("%d%d%d%d",&a,&b,&c,&t);
		for(int i=0;i<a;i++) 
			for(int j=0;j<b;j++)	
				for(int k=0;k<c;k++)
				{
					scanf("%d",&maze[i][j][k]);
					mark[i][j][k]=false;
				}
					
		while(!myQ.empty())
			myQ.pop(); 
		mark[0][0][0]=true;
		Sta t1;
		t1.x=0;
		t1.y=0;
		t1.z=0;
		t1.t=0;
		myQ.push(t1);
		int ret=bMaze(a,b,c);
		if(ret<=t&&ret!=-1)
			printf("%d\n",ret);
		else
			printf("-1\n");
	}
	return 0;
}

/*
测试数据
样例输入
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
样例输出
11
*/























