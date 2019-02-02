/*
Subject:Oil Deposite 
ID:1460
Complier:Devcpp
Author:JiaruiXie
StartTime:27/03/17 08:15
Result:Accepted
EndTime:27/03/17 08:43
*/

#include <stdio.h>
#include <string.h>
#include <queue>
#define N 200
using namespace std;

char str[N][N];

typedef struct stu
{
	int x,y;
}Stu;
queue<Stu> myQ;

void pre()
{
	while(!myQ.empty())
		myQ.pop();
}

int go [][2]={
				0,1,
				0,-1,
				1,0,
				-1,0,
				1,1,
				1,-1,
				-1,1,
				-1,-1
			 };
			 
void BFS(int a,int b)
{
	while(!myQ.empty())
	{
		Stu temp;
		temp=myQ.front();
		myQ.pop();
		for(int i=0;i<8;i++)
		{
			int nx=temp.x+go[i][0];
			int ny=temp.y+go[i][1];
			if(nx<0||nx>=a||ny<0||ny>=b)
				continue;
			if(str[nx][ny]=='*')
				continue;
			Stu tt;
			tt.x=nx;
			tt.y=ny;
			str[nx][ny]='*';
			myQ.push(tt);
		}
	}
}

int main()
{
	int r,c;
	while(scanf("%d%d",&r,&c)!=EOF)
	{
		if(r==0&&c==0)
			break;
		for(int i=0;i<r;i++)
			scanf("%s",str[i]);
		
		int ans=0;
		pre();
		Stu temp;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				if(str[i][j]=='@')
				{
					temp.x=i;
					temp.y=j;
					str[i][j]='*';
					myQ.push(temp);
					BFS(r,c);
					ans++;
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
OutputData:
0
1
2
2
*/

