/*
	Subject:递归回溯_Temple_of_the_bone 
    Compiler:Devcpp
	Description:有问题 
	Author:JiaruiXie
	Id:6-5-1
	Date_Begin:20/01/17 16:28
	Date_End:
*/
#include <stdio.h>
#define N 100

char maze[N][N];
bool hash[N][N];
int row,col,time;

int go[][2]=
			{
				1,0,
				-1,0,
				0,1,
				0,-1,
			};
			
void init()
{
	time=0;
	for(int i=0;i<row;i++)	
		for(int j=0;j<col;j++)
			hash[i][j]=false;
}

//返回条件不知道该如何写 
bool DFS(int x,int y,int aim)
{
	if(maze[x][y]=='D'&&time==aim)
		return true; 
	else if(time>aim)
		return false;
//	else//这里加不加else有没有关系 ?因为这三个应该是并列的关系 
//	{
		
		for(int i=0;i<4;i++)
		{
			int tx=x+go[i][0];
			int ty=y+go[i][1];
			if(maze[tx][ty]=='X'||tx<0||tx>=row||ty<0||ty>=col||hash[tx][ty])
				continue;
			//向下一个格走去 
			time++;
			hash[tx][ty]=true;
			//从下一个格子开始,向下走去 
			bool flag=DFS(tx,ty,time);
			//回到当前格子，另辟蹊径 
			time--;
			hash[tx][ty]=false;
			return flag;
		}
//	}
}

int main()
{
	int t;
	while(scanf("%d%d%d",&row,&col,&t)!=EOF)
	{
		init();
		int sx,sy,dx,dy;
		if(row==0||col==0||t==0)
			break;
		for(int i=0;i<row;i++)
			scanf("%s",maze[i]);
		
		for(int i=0;i<row;i++)	
			for(int j=0;j<col;j++)
				if(maze[i][j]=='S')
				{
					sx=i;
					sy=j;
					printf("sx=%d,sy=%d\n",sx,sy);
				}
				else if(maze[i][j]=='D')
				{
					dx=i;
					dy=j;
					printf("dx=%d,dy=%d\n",dx,dy);
				}
				
				
		int f1=(sx+sy)&1;
		int f2=(dx+dy)&1;
		int f3=t&1;
		if(f1==0&&f2==0&&f3==1)
		{
			printf("NO\n");
			break;
		}
		if(DFS(sx,sy,t))	
			printf("YES\n");
		else
			printf("NO\n");
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




























