/*
	Subject:‚Ü‚½ H’ö 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:5.3
	Date_Begin:01/02/17 20:11
	Result:Accepted
	Date_End:01/02/17 20:30
*/

#include <stdio.h>
#include <algorithm>
#define N 100000
using namespace std;

typedef struct node
{
	int head;
	int rear;
	int cost;
	bool operator < (const node a)const
	{
		return cost<a.cost;
	}
}Node;

int Tree[N];
Node Array[N];
int ans;
int size;

void init()
{
	ans=0;
	size=0;
	for(int i=0;i<N;i++)
		Tree[i]=-1;
}

int findRoot(int x)
{
	if(Tree[x]==-1)
		return x;
	else
	{
		int temp=findRoot(Tree[x]);
		Tree[x]=temp;
		return temp;
	}
}

int main()
{
	int a;
	while(scanf("%d",&a)!=EOF&&a!=0)
	{
		init();
		size=a*(a-1)/2;
		for(int i=0;i<size;i++)
		{
			int h,r,c;
			scanf("%d%d%d",&h,&r,&c);
			Array[i].head=h;
			Array[i].rear=r;
			Array[i].cost=c;
		}
		
		sort(Array,Array+size);
		
		for(int i=0;i<size;i++)
		{
			int aa=findRoot(Array[i].head);
			int bb=findRoot(Array[i].rear);
			if(aa!=bb)
			{
				Tree[bb]=aa;
				ans+=Array[i].cost;
			}
		}
		
		printf("%d\n",ans);
	}
	return 0;
}

/*
InputData:
3
1 2 1
1 3 2
2 3 4
4
1 2 1
1 3 4
1 4 1
2 3 3
2 4 2
3 4 5
0
outputData:
3
5
*/





