/*
Subject:Ac
ID:
Complier:Devcpp
Author:JiaruiXie
StartTime:06/02/17 12:23
Result:Accepted
EndTime:06/02/17 12:29
*/
#include <stdio.h>
#include <algorithm>
#define N 200
using namespace std;

typedef struct node
{
	int startT;
	int endT;
	bool operator < (const node &a)const
	{
		return endT<=a.endT; 
	}
}node;

node array[N];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		for(int i=0;i<n;i++)
			scanf("%d%d",&array[i].startT,&array[i].endT);
		
		sort(array,array+n);
		
		int ans=1;
		int nowT=array[0].endT;
		for(int i=1;i<n;i++)
		{
			if(array[i].startT>=nowT)
			{
				ans++;
				nowT=array[i].endT;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
InputData:
12
1 3
3 4
0 7
3 8
15 19
15 20
10 15
8 18
6 12
5 10
4 14
2 9
0
OutputData:
5
*/

