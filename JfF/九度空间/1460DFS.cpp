/*
Subject:Oil Deposite 
ID:1460
Complier:Devcpp
Author:JiaruiXie
StartTime:27/03/17 08:37
Result:Accepted
EndTime:27/03/17 08:42
*/

#include <stdio.h>

#define N 200
using namespace std;

char str[N][N];
int r,c;

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
			 
void DFS(int a,int b)
{
	for(int i=0;i<8;i++)
	{
		int nx=a+go[i][0];
		int ny=b+go[i][1];
		if(nx<0||nx>=r||ny<0||ny>=c)
			continue;
		if(str[nx][ny]=='*')
			continue;
		str[nx][ny]='*';
		DFS(nx,ny);
	}
	return ;
}

int main()
{
	while(scanf("%d%d",&r,&c)!=EOF)
	{
		if(r==0&&c==0)
			break;
		for(int i=0;i<r;i++)
			scanf("%s",str[i]);
		int ans=0;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				if(str[i][j]=='@')
				{
					DFS(i,j);
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

