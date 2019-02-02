/*
	Subject:Freckles
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:5.4
	Date_Begin:01/02/17 20:31
	Result:Wrong Answer
	Date_End:05/02/17 13:29
*/
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define N 1000
using namespace std;

typedef struct dot
{
	double y,x;
	double getDis(dot d)
	{
		double temp=(x-d.x)*(x-d.y)+(y-d.y)*(y-d.y);
		return sqrt(temp);
	}
}Dot;

typedef struct edge
{
	int head;
	int rear;
	float cost;
	bool operator < (const edge &e)const
	{
		return cost<e.cost;
	}
}Edge;

int Tree[N];
Dot List[N];
Edge Array[N*7];
double ans;
int size;

void init(int n)
{
	for(int i=0;i<=n;i++)
		Tree[i]=-1;
	ans=0;
	size=0;
}

int findRoot(int x)
{
	if(Tree[x]==-1)
		return x;
	else
	{
		int ret=findRoot(Tree[x]);
		Tree[x]=ret;
		return ret;
	}
}

int main()
{
	int a;
	while(scanf("%d",&a)!=EOF)
	{
		init(a);
		for(int i=1;i<=a;i++)
			scanf("%lf%lf",&List[i].x,&List[i].y);
			
		for(int i=1;i<=a;i++)
			for(int j=i+1;j<=a;j++)
			{
				Array[size].head=i;
				Array[size].rear=j;
				Array[size].cost=List[i].getDis(List[j]);
				size++;
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
		printf("%.2lf\n",ans);
	}
	return 0;
}

/*
InputData:
3 
1.0 1.0
2.0 2.0
2.0 4.0
outputData:
3.41
*/



