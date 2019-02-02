/*
	Subject:MST_点_自己臆造 
    Compiler:Devcpp
	Description:用线连接第一象限中的点，要求所用的线段的长度最小 
	Author:JiaruiXie
	Id:5-3-2
	Date_Begin:17/01/17 19:00
	Date_End:17/01/17 19:18
*/
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define N 1000
using namespace std;

typedef struct node
{
	float x;
	float y;
	
	float getRD(node &b)
	{
		float xv=x-b.x;
		float yv=y-b.y;
		return sqrt(xv*xv+yv*yv);
	}
	void init(float a,float b)
	{
		x=a;
		y=b;
	}
}Node;

typedef struct edge
{
	int head;
	int rear;
	float cost;
	bool operator < (edge const &a) const
	{
		return cost<a.cost;
	}
}Edge;

Node dot[N];
Edge e[N];
int table[N];

void init()
{
	for(int i=0;i<N;i++)
		table[i]=-1;
}

int findRoot(int x)
{
	if(table[x]==-1)
		return x;
	else
	{
		int temp=findRoot(table[x]);
		table[x]=temp;
		return temp;
	}
}

int main()
{
	int size;
	while(scanf("%d",&size)!=EOF)
	{
		init();
		float ans=0;
		float a,b;
		
		for(int i=0;i<size;i++)
		{
			scanf("%f%f",&a,&b);
			dot[i].init(a,b);
		}	
		
		for(int i=0;i<size;i++)
			for(int j=i+1;j<size;j++)
			{
				e[i].head=i;
				e[i].rear=j;
				e[i].cost=dot[i].getRD(dot[i+1]);
			}
			
		sort(e,e+size);
		
		for(int i=0;i<size;i++)
		{
			int a=findRoot(e[i].head);
			int b=findRoot(e[i].rear);
			if(a!=b)
			{
				table[b]=a;
				ans+=e[i].cost;
			}	
		}
		printf("%.2f\n",ans);
	}
	return 0;
}

/*
测试数据
样例输入
3
1.0 1.0
2.0 2.0
2.0 4.0
样例输出
3.41
*/




















