/*
Subject:还是畅通工程 
ID:1017
Complier:Devcpp
Author:JiaruiXie
StartTime:23/03/17 07:43
Result:Accepted
EndTime:23/03/17 07:53
*/

#include <stdio.h>
#include <algorithm>
#define N 101
#define NN 6000
using namespace std;

int tree[N];
int ans;

void pre()
{
	for(int i=1;i<N;i++)
		tree[i]=-1;
	ans=0;
}

int findRoot(int x)
{
	if(tree[x]==-1)
		return x;
	else
	{
		int ret=findRoot(tree[x]);
		tree[x]=ret;
		return ret;
	}
}

struct node
{
	int s,e;
	int cost;
	bool operator < (const struct node &a)const
	{
		return cost<a.cost;
	}
}arr[NN];

int main()
{
	int size;
	while(scanf("%d",&size)!=EOF)
	{
		pre();
		int len=size*(size-1)/2;
		if(size==0)
			break;
		for(int i=0;i<len;i++)
			scanf("%d%d%d",&arr[i].s,&arr[i].e,&arr[i].cost);
		sort(arr,arr+len);
	
		for(int i=0;i<len;i++)
		{
			int a=findRoot(arr[i].s);
			int b=findRoot(arr[i].e);
			if(a!=b)
			{
				tree[b]=a;
				ans+=arr[i].cost;
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
OutputData:
3
5
*/

