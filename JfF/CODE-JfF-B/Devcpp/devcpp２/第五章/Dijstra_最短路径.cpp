/*
	Subject:Dijstra_最短路径 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:5-4-2
	Date_Begin:18/01/17 11:07
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
}Edge;

bool flag[N];
int dis[N];
vector<Edge> myEdge[N];

void init()
{
	for(int i=0;i<N;i++)
	{
		flag[i]=false;
		dis[i]=-1;
		myEdge[i].clear();
	}
}

int main()
{
	//n代表总共的节点数
	//m代表边数 
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		init();
		//读入数据 
		while(m--)
		{
			int head,rear,c;
			Edge t;
			scanf("%d%d%d",&head,&rear,&c);
			t.cost=c;
			t.next=rear;
			myEdge[head].push_back(t);
			t.next=head;
			myEdge[rear].push_back(t);
		}
		
		//将1加入集合K中 
		int newP=1;
		flag[newP]=true;
		dis[newP]=0;
		
		//进行n-1次循环，确定最短路径
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<myEdge[newP].size();j++)
			{
				int next=myEdge[newP][j].next;
				int c=myEdge[newP][j].cost;
				if(flag[next])
					continue;
				//节点1不可达next 
				if(dis[next]==-1||dis[next]>dis[newP]+c)
					dis[next]=dis[newP]+c;
			}	
			//遍历所有点的距离,选出要加入到集合K中的节点 
			int min=99999999;
			for(int j=1;j<=n;j++)
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
		printf("%d\n",dis[n]);
	}
	return 0;
}

/*
测试数据
样例输入
2 1
1 2 3
3 3 
1 2 5
2 3 5
3 1 2
0 0
样例输出
3 
2
*/






















