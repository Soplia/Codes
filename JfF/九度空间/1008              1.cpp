/*
Subject:最短路径问题 
ID:1008
Complier:Devcpp
Author:JiaruiXie
StartTime:24/03/17 08:02
Result:Accepted
EndTime:28/03/17 21:14
*/

#include <stdio.h>
#include <vector>
#define N 1001
using namespace std;

bool Mark[N];
int Dis[N];
int Cost[N];

typedef struct s
{
	int next;
	int dis;
	int cost;
}Node;

vector<Node> Edge[N];

void pre()
{
	for(int i=1;i<N;i++)
	{
		Mark[i]=false;
		Dis[i]=-1;
		Edge[i].clear();
	}
}

int main()
{
	int n,m,s,e;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		pre();
		Node temp;
		while(m--)
		{
			int a,b;
			scanf("%d%d%d%d",&a,&b,&temp.dis,&temp.cost);
			temp.next=b;
			Edge[a].push_back(temp);
			temp.next=a;
			Edge[b].push_back(temp);
		}
		
		scanf("%d%d",&s,&e);
		
		int newP=s;
		Dis[newP]=0;
		Mark[newP]=true;
		
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<Edge[newP].size();j++)
			{
				int t=Edge[newP][j].next;
				int d=Edge[newP][j].dis;
				int c=Edge[newP][j].cost;
				
				if(Mark[t])
					continue;
				//仅仅是在这个地方改变了更新条件而已。
				//注意错误就是因为这个地方的最后一个条件的小于号写错了 
				if(Dis[t]==-1||Dis[t]>Dis[newP]+d||Dis[t]==Dis[newP]+d&&Cost[t]>Cost[newP]+c)
				{
					Dis[t]=Dis[newP]+d;
					Cost[t]=Cost[newP]+c;
				}
			}
			
			int min=12121212;
			for(int j=1;j<=n;j++)
			{
				if(Mark[j])
					continue;
				if(Dis[j]==-1)
					continue;
				if(Dis[j]<min)	
				{
					min=Dis[j];
					newP=j;
				}
			}
			
			Mark[newP]=true;
		}
		printf("%d %d\n",Dis[e],Cost[e]);
	}
	return 0;
}

/*
InputData:
3 2
1 2 5 6
2 3 4 5
1 3
0 0
OutputData:
9 11
*/

