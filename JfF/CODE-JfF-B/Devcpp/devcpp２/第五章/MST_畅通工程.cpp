/*
	Subject:MST_畅通工程_自己臆造 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:5-3-1
	Date_Begin:17/01/17 11:50
	Date_End:18/01/17 14:36
*/
#include <stdio.h>
#include <algorithm>
#define N 1000
using namespace std;

typedef struct node
{
	int head;
	int cost;
	int rear;
	bool operator <(const node &a)const
	{
		return cost<a.cost;
	}
	void output()
	{
		printf("%d_%d_%d\n",head,rear,cost);
	}
	
	
}Edge;


//void copy(node *a,node *b)
//{
//	a->cost=b->cost;
//	a->head=b->head;
//	a->rear=b->rear;
//}
	
void copy(node &a,node &b) 
{
	a.cost=b.cost;
	a.head=b.head;
	a.rear=b.rear;
}

Edge road[N/2];
Edge road1[N/2];

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
	while(scanf("%d",&size)!=EOF&&size!=0)
	{
		init();
		int len=size*(size-1)/2;
		for(int i=0;i<len;i++)
			scanf("%d%d%d",&road[i].head,&road[i].rear,&road[i].cost);
			
		sort(road,road+len);
		
		int ans=0;
		int j=0;
		for(int i=0;i<len;i++)
		{
			int a=findRoot(road[i].head);
			int b=findRoot(road[i].rear);
			if(a!=b)
			{
				table[b]=a;
				ans+=road[i].cost;
				copy(road1[j++],road[i]);
			}
		}
		
		printf("%d\n",ans);
		for(int i=0;i<j;i++)
			road1[i].output();
		printf("\n");
	}
	return 0;
}


/*
测试数据
样例输入
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
样例输出
3
5
*/























