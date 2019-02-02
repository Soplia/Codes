/*
Subject:マトリックス 
ID:2012_2
Complier:Devcpp
Author:JiaruiXie
StartTime:06/02/17 16:49
Result:Accepted
EndTime:06/02/17 19:28
*/
#include <stdio.h>
#define row 2
#define col 3

int main()
{
	int front[row][col],rear[col][row];
	int ans;
	
	while(~scanf("%d",&front[0][0]))
	{
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
			{
				if(i==0&&j==0)
					continue;
				scanf("%d",&front[i][j]);	
			}
				
				
		
		for(int i=0;i<col;i++)
			for(int j=0;j<row;j++)
				scanf("%d",&rear[i][j]);
		
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<row;j++)
			{
				ans=0;
				for(int k=0;k<col;k++)
					ans+=front[i][k]*rear[k][j];
				printf("%d ",ans);
			}
			printf("\n");
		}	
	}	
	
	return 0;
}
/*
InputData:
1 2 3
3 4 5
6 7
8 9
10 11
OutputData:
52 58
100 112
*/

