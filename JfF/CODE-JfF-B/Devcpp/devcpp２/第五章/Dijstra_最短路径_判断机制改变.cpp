/*
	Subject:Dijstra_最短路径_判断机制改变 
    Compiler:Devcpp
	Description:C语言中的整形数组如果不赋值初始值是多少??????????
	Author:JiaruiXie
	Id:5-4-3
	Date_Begin:18/01/17 13:38
	Date_End:18/01/17 14:36
*/
#include <stdio.h>
#include <vector>
#define N 100
using namespace std;

typedef struct edge
{	
	int next;
	int cost;
	int dis;
}Edge;

bool flag[N];
int dis[N];
int cost[N];
vector<Edge> myEdge[N];

void init()
{
	for(int i=0;i<N;i++)
	{
		flag[i]=false;
		dis[i]=-1;
		//cost需要进行初始化
		myEdge[i].clear();
		//cost[i]=99999;
	}
}

int main()
{
	int dot,edge,start,end;
	while(scanf("%d%d",&dot,&edge)!=EOF)
	{
		if(dot==0&&edge==0)
			break;
		init();
		while(edge--)
		{
			Edge t;
			int head,rear;
			scanf("%d%d%d%d",&head,&rear,&t.dis,&t.cost);
			t.next=rear;
			myEdge[head].push_back(t);
			t.next=head;
			myEdge[rear].push_back(t);
		}
		scanf("%d%d",&start,&end);
		
		
		int newP=start;
		flag[newP]=true;
		dis[newP]=0;
		//这个地方是我自己加上的 
		//cost[newP]=0;
		
		for(int i=1;i<dot;i++)
		{
			for(int j=0;j<myEdge[newP].size();j++)
			{
				int ndot=myEdge[newP][j].next;
				int ncost=myEdge[newP][j].cost;
				int ndis=myEdge[newP][j].dis;
				if(flag[ndot])
					continue; 
				if(dis[ndot]==-1||dis[ndot]>dis[newP]+ndis||dis[ndot]==dis[newP]+ndis&&cost[ndot]>cost[newP]+ncost)
				{
					dis[ndot]=dis[newP]+ndis;
					cost[ndot]=cost[newP]+ncost;
				}	
			}
			int min=999999;
			for(int j=1;j<=dot;j++)
			{
				if(flag[j])
					continue;
				if(dis[j]==-1)
					continue;
				if(dis[j]<min)
				{
					min=dis[j];
					newP=j;
				}
			}
			flag[newP]=true;	
		}
		printf("%d %d\n",dis[end],cost[end]);	
	}
	return 0;
}

/*
测试数据
样例输入
3 2
1 2 5 6
2 3 4 5
1 3
0 0
样例输出
9 11
*/


























