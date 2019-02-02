/*
	Subject:Dijstra_Å’Z‹——£ 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:5.6
	Date_Begin:02/02/17 09:17
	Date_End:05/02/17 13:33
*/
#include <stdio.h>
#include <vector>
#define N 1000
using namespace std;

typedef struct node
{
	int nextNode;
	int cost;
}Node;

vector<Node>List[N];
int dis[N];
int mark[N];

void init()
{
	for(int i=0;i<N;i++)
	{
		dis[i]=-1;
		mark[i]=0;
		List[i].clear();
	}
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0||m==0)
			break;
		init();
		while(m--)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			Node temp;
			temp.cost=c;
			temp.nextNode=b;
			List[a].push_back(temp); 
			temp.nextNode=a;
			List[b].push_back(temp);
		}
		
		int newP=1;
		mark[newP]=1;
		dis[newP]=0;
		
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<List[newP].size();j++)	
			{
				int r=List[newP][j].nextNode;
				int c=List[newP][j].cost;
				if(mark[r])
					continue;
				if(dis[r]==-1||dis[r]<dis[newP]+c)
					dis[r]=dis[newP]+c;
			}
			int min=99999;
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
		printf("%d\n",dis[n]);
	}
	return 0;
}
/*
InputData:
2 1
1 2 3
3 3
1 2 5
2 3 5
3 1 2
0 0
outputData:
3
2
*/




















