/*
Subject:How Many Table
ID:1445
Complier:Devcpp
Author:JiaruiXie
StartTime:22/03/17 08:44
Result:Accepted
EndTime:22/03/17 09:00
*/

#include <stdio.h>
#define N 1001

int tree[N];
int ans;

void pre()
{
	ans=0;
	for(int i=1;i<N;i++)
		tree[i]=-1;
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

int main()
{
	int cas;
	int n,m,a,b;
	while(scanf("%d",&cas)!=EOF)
	{
		while(cas--)
		{
			pre();
			scanf("%d%d",&n,&m);
			while(m--)
			{
				scanf("%d%d",&a,&b);
				a=findRoot(a);
				b=findRoot(b);
				if(a!=b)
					tree[b]=a;
			} 
			for(int i=1;i<=n;i++)
				if(tree[i]==-1)
					ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}

/*
InputData:
2
5 3
1 2
2 3
4 5

5 1
2 5
OutputData:
2
4
*/

