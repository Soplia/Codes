/*
Subject:Hash
ID:2.5
Complier:Devcpp
Author:JiaruiXie
StartTime:06/02/17 09:57
Result:Accepted
EndTime:06/02/17 10:02
*/
#include <stdio.h>
#define N 101

int main()
{
	int n,temp;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		
		int hash[N]={0};
		while(n--)
		{
			scanf("%d",&temp);
			hash[temp]++;
		}
		scanf("%d",&temp);
		printf("%d\n",hash[temp]);
	}
	return 0;
}
/*
InputData:
3 
80 60 90
60
2 
85 66
0
5
60 75 90 55 75
75
0
OutputData:
1
0
2
*/

