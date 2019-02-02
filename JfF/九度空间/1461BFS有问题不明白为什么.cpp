/*
Subject:Tempter
ID:1461
Complier:Devcpp
Author:JiaruiXie
StartTime:27/03/17 08:46
Result:Wrong Answer
EndTime:31/03/17 10:12
*/

#include <stdio.h>
#include <queue>
#define N 8
using namespace std;

int go[][2]={
				0,1,
				0,-1,
				1,0,
				-1,0
			};
char str[N][N];
int time;

typedef struct stu
{
	int x,y;
	int t;
}Stu;

queue<Stu> myQ;
void pre()
{
	while(!myQ.empty())
		myQ.pop();
}

int BFS(int a,int b)
{
	while(!myQ.empty())
	{
		Stu temp=myQ.front();
		myQ.pop();
		for(int i=0;i<4;i++)
		{
			int nx=temp.x+go[i][0];
			int ny=temp.y+go[i][1];
			if(nx<0||nx>=a||ny<0||ny>=b)
				continue;
			if(str[nx][ny]=='X')
				continue;
				
			if(str[nx][ny]=='D')
				if(temp.t+1==time)
					return 1;
				else
					continue;
				
			Stu tt;
			tt.x=nx;
			tt.y=ny;
			tt.t=temp.t+1;
			str[nx][ny]='X';
			myQ.push(tt);
		}
	}
	return 0;
}

int main()
{
	int a,b;
	while(scanf("%d%d%d",&a,&b,&time)!=EOF)
	{
		if(a==0&&b==0&&time==0)
			break;
		for(int i=0;i<a;i++)
			scanf("%s",str[i]);
		
		int i,j;
		//要想跳出双层循环
		//使用一个break
		//是不够的，需要使用两个break；或者使用goto语句。 
		for(i=0;i<a;i++)
			for(j=0;j<b;j++)
				if(str[i][j]=='S')
					goto END;
		END:	
		pre();
		Stu temp;
		temp.x=i;
		temp.y=j;
		temp.t=0;
		str[i][j]='X';
		myQ.push(temp);
		if(BFS(a,b))
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

