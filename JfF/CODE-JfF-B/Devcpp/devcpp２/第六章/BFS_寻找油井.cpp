/*
	Subject:BFS_Ѱ���;� 
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

//���������Ŀ 
int ans;
//��ŵ�ͼ�ı߽磬���㿪ʼ��񣬶�����Ӵ�� 
int row,col;
//����
queue<int> qX,qY;
 
//��ǵ�ǰλ���Ƿ�̽��� 
bool hash[N][N];
//���������ͼ 
char maze[N][N];
//��ǰλ�õ�����ת�� 
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

//��ʼ��
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
		//���Ƚ��г�ʼ�� 
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
��������
��������
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
�������
0
1
2
2
*/
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
