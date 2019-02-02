/*
	Subject:Dijstra_ç≈íZãóó£_TWO 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:5.6
	Date_Begin:02/02/17 18:17
	Result:Accepted
	Date_End:02/02/17 18:49
*/
#include <stdio.h>
#include <vector>
#define inf 0x7fffffff
#define N 100001

using namespace std;

typedef struct node
{
	int nextNode;
	int cost;
	int len;
}Node;

int dis[N];
int mon[N];
int mark[N];
vector<Node> Array[N];

void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=-1;
		Array[i].clear();
		mark[i]=0;
	}
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		
		init(n);
		int a,b,c,d;
		while(m--)
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			Node temp;
			temp.nextNode=b;
			temp.len=c;
			temp.cost=d;
			Array[a].push_back(temp);
			temp.nextNode=a;
			Array[b].push_back(temp);
		}
		int s,e;
		scanf("%d%d",&s,&e);
		
			
		int newP=s;
		mark[newP]=1;
		dis[newP]=0;
		
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<Array[newP].size();j++)
			{
				int no=Array[newP][j].nextNode;
				int co=Array[newP][j].cost;
				int lo=Array[newP][j].len;
				if(mark[no])
					continue;
				if(dis[no]==-1||dis[no]>dis[newP]+lo||dis[no]==dis[newP]+lo&&mon[no]>mon[newP]+co)
				{
					dis[no]=dis[newP]+lo;
					mon[no]=mon[newP]+co;
				}
			}
			int min=inf;
			for(int j=1;j<=n;j++)
			{
				if(mark[j])
					continue;
				if(dis[j]==-1)
					continue;
				if(dis[j]<min)
				{
					min=dis[j];
					newP=j;
				}
				
			}
			mark[newP]=1;
			
		}
		printf("%d %d\n",dis[e],mon[e]);
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
outputData:
9 11
*/


