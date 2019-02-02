/*
Subject:greak
ID:2.11
Complier:Devcpp
Author:JiaruiXie
StartTime:06/02/17 12:07
Result:Accepted
EndTime:06/02/17 12:21
*/
#include <stdio.h>
#include <algorithm>
#define  N 1000
using namespace std;

typedef struct node
{
	int w,m;
	float awm;
	bool operator < (const node &a)const
	{
		return awm>a.awm;
	}
}node;

node array[N];

int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(n==-1&&m==-1)
			break;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&array[i].w,&array[i].m);
			array[i].awm=(float)array[i].w/array[i].m;
		}
		
		sort(array,array+n);
		
		float ans=0;
		
		for(int i=0;i<n;i++)
		{
			if(m>=array[i].m)
			{
				m-=array[i].m;
				ans+=array[i].w;
			}
			else
			{
				ans+=array[i].awm*m;
				m=0;
				break;
			}
		}
		printf("%.3f\n",ans);
	}
	return 0;
}
/*
InputData:
5 3
7 2
4 3
5 2
20 3
25 18
24 15
15 10
-1 -1
OutputData:
13.333
31.500
*/


