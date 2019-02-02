/*
	Subject:BFS_寻找油井 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:6-4-2
	Date_Begin:20/01/17 10:05
	Date_End:20/01/17 11:22
*/
#include <stdio.h>
#include <queue> 
#define N 100
using namespace std;

//存放油田数目 
int ans;
//存放地图的边界，从零开始与否，都不中哟啊 
int row,col;
//队列
queue<int> qX,qY;
 
//标记当前位置是否被探测过 
bool hash[N][N];
//保存油田地图 
char maze[N][N];
//当前位置的坐标转移 
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

//初始化
void init()
{
	ans=0;
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			hash[i][j]=false;
	while(!qX.empty())
		qX.pop();
	while(!qY.empty())
		qY.pop();
} 

int main()
{
	while(scanf("%d%d",&row,&col)!=EOF)
	{	
		if(row==0||col==0)
			break;
		//首先进行初始化 
		init();
		for(int i=0;i<row;i++)
			scanf("%s",maze[i]); 
		
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				if(!hash[i][j]&&maze[i][j]=='@')	
				{
					ans++;
					qX.push(i);
					qY.push(j);
					while(!qX.empty())
					{
						int rX=qX.front();
						int rY=qY.front();
						qX.pop();
						qY.pop();
						
						for(int i=0;i<8;i++)
						{
							int tX=rX+go[i][0];
							int tY=rY+go[i][1];
							
							if(maze[tX][tY]=='*'||hash[tX][tY]||tX<0||tX>=row||tY<0||tY>=col)
								continue;
								
							hash[tX][tY]=true;
							qX.push(tX);
							qY.push(tY);
						}
					}
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
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
