/*
	Subject:找油田_递归回溯 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:6-4-3 
	Date_Begin:20/01/17 11:24
	Date_End:
*/
#include <stdio.h>
#define N 100

char maze[N][N];
bool hash[N][N];
int row;
int col;
int ans;
int count=0; 
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
			
void init()
{
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			hash[i][j]=false;
	ans=0;
}

void print_M()
{
	printf("row=%d,col=%d\n",row,col);
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			printf("$%c$",maze[i][j]);
		printf("\n");
	}
		
	printf("\n");
}

void print_H(int x,int y)
{
//	for(int j=1;j<count;j++)
//			printf("\t");
//		
//	printf("由(%d,%d)向外扩展_Hash 如下:\n",x+1,y+1);
	for(int i=0;i<row;i++)
	{
//		for(int j=1;j<count;j++)
//			printf("\t");
			
		for(int j=0;j<col;j++)
			printf("%d ",(int)hash[i][j]);
		printf("\n");
	}
	printf("\n");	
}

void DFS(int x,int y)
{
	count++;
	for(int i=0;i<8;i++)
	{
		int tx=x+go[i][0];
		int ty=y+go[i][1];
		
//		for(int j=1;j<count;j++)
//			printf("\t");
//		printf("%d_%d\n",tx+1,ty+1);
		
		if(tx<0||tx>=row||ty<0||ty>=col)
			continue;
		if(hash[tx][ty])
			continue;
		if(maze[tx][ty]=='*')
			continue;
		hash[tx][ty]=true;
		
		//print_H(x,y);
		DFS(tx,ty);
		count--;
//		for(int j=1;j<count;j++)
//			printf("\t");
//		printf("回到(%d,%d)\n",x+1,y+1);
	}
	return ;
}

int main()
{
	while(scanf("%d%d",&row,&col)!=EOF)
	{
		init();
		if(row==0||col==0)
			break;
		for(int i=0;i<row;i++)
			scanf("%s",maze[i]);
		
		//print_M();	
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
			{
				//printf("当前i=%d,j=%d,hash[i][j]=%d,maze[i][j]=%c\n",i,j,(int)hash[i][j],maze[i][j]);
				if(!hash[i][j]&&maze[i][j]=='@')
				{
					hash[i][j]=true;
					ans++;
					DFS(i,j);
				}
//				if(hash[i][j]||maze[i][j]=='*')
//					continue;
//				//hash[i][j]=true;
//				DFS(i,j);
//				ans++;
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





















