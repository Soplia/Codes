/*
	Subject:Floyd_Å’Z‹——£i‚³‚¢‚½‚ñ‚«‚å‚èj 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:5.5 
	Date_Begin:02/02/17 08:51
	Result:Accepted
	Date_End:02/02/17 09:08
*/

#include <stdio.h>
#define N 200

int Array[N][N];

void init()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			Array[i][j]=-1;
		Array[i][i]=0;
	}
		
}

int main()
{
	int n,m;
	init();
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0&&m!=0)
	{
		int a,b,c;
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			Array[a][b]=c;
			Array[b][a]=c;
		}
		
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
				{
					if(Array[i][k]==-1||Array[k][j]==-1)
						continue;
					else if(Array[i][j]==-1||Array[i][j]>Array[i][k]+Array[k][j])
						Array[i][j]=Array[i][k]+Array[k][j];
				}
		printf("%d\n",Array[1][n]);
	}
	
	return 0;
}

/*
InputData:
2 1
1 2 3
3 3
1 2 5
2 3 5
3 1 2
0 0
outputData:
3
2
*/



