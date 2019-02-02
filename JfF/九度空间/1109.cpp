/*
Subject:Á¬Í¨Í¼ 
ID:1109
Complier:Devcpp
Author:JiaruiXie
StartTime:22/03/17 08:28
Result:Accepted
EndTime:22/03/17 08:39
*/

#include <stdio.h>
#define N 1001

int tree[N];

void pre()
{
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
	int n,m;
	int a,b;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		pre();
		if(n==0)
			break;
		while(m--)
		{
			scanf("%d%d",&a,&b);
			a=findRoot(a);
			b=findRoot(b);
			if(a!=b)
				tree[b]=a;
		}
		int flag=0;
		for(int i=1;i<=n;i++)
			if(tree[i]==-1)
				flag++;
		if(flag>1)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}

/*
InputData:
4 3
1 2
2 3
3 2
3 2
1 2
2 3
0 0
OutputData:
NO
YES
*/

