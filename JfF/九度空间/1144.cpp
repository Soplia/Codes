/*
Subject:Freckles
ID:1144
Complier:Devcpp
Author:JiaruiXie
StartTime:23/03/17 08:22
Result:Accepted
EndTime:29/03/17 09:41
*/

#include <stdio.h>
#include <math.h>
#include <algorithm>
#define N 101
#define NN 6000
using namespace std;

struct dot
{
	double x,y;
	double getDis(struct dot a)
	{
		double c=x-a.x;
		double d=y-a.y;
		double t=sqrt(c*c+d*d);
		return t;
	}
}Dot[N];

struct node
{
	int s,e;
	double dis;
	bool operator <(const struct node &a)const
	{
		return dis<a.dis;
	}
}Node[NN];

int tree[N];
double ans;
int size;

void pre()
{
	for(int i=1;i<N;i++)
		tree[i]=-1;
	ans=0;
	size=0;
}

int findRoot(int x)
{
	if(tree[x]==-1)
		return x;
	else
	{
		//错误在与这个地方被写成了int ret=findRoot(tree[x]);
		//以后写程序要注意，关键地方一定不能出错。 
		int ret=findRoot(tree[x]);
		tree[x]=ret;
		return ret;
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		pre();
		for(int i=1;i<=n;i++)
            scanf("%lf%lf",&Dot[i].x,&Dot[i].y);


		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				Node[size].s=i;
				Node[size].e=j;
				double temp=Dot[i].getDis(Dot[j]);
				Node[size++].dis=temp;
			}

		sort(Node,Node+size);

		for(int i=0;i<size;i++)
		{
			int a=findRoot(Node[i].s);
			int b=findRoot(Node[i].e);
			if(a!=b)
			{
				tree[b]=a;
				ans+=Node[i].dis;
			}
		}
		printf("%.2lf\n",ans);

	}
}
/*
InputData:
3
1.0 1.0
2.0 2.0
2.0 4.0
OutputData:
3.41
*/

