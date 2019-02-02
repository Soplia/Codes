/*
Subject:确定比赛名次 
ID:1149
Complier:Devcpp
Author:JiaruiXie
StartTime:24/03/17 09:57
Result:Accepted
EndTime:24/03/17 10:22
*/

#include <stdio.h>
#include <queue>
#include <vector>
#define N 501
using namespace std;

int ret[N];
int pos;
int inDeg[N];
priority_queue< int,vector<int>,greater<int> > myQ;
vector<int> edge[N];

void pre()
{
	pos=0;
	while(!myQ.empty())
		myQ.pop();
	for(int i=1;i<N;i++)
	{
		edge[i].clear();
		inDeg[i]=0;
	}	
}

int main()
{
	int n,m;
	int a,b;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		pre();
		while(m--)
		{
			scanf("%d%d",&a,&b);
			inDeg[b]++;
			edge[a].push_back(b);
		}
		
		for(int i=1;i<=n;i++)
			if(inDeg[i]==0)
				myQ.push(i);
		
		while(!myQ.empty())
		{
			int a=myQ.top();
			myQ.pop();
			ret[pos++]=a;
			for(int i=0;i<edge[a].size();i++)
			{
				inDeg[edge[a][i]]--;
				if(inDeg[edge[a][i]]==0)
					myQ.push(edge[a][i]);
			}
		}
		
		for(int i=0;i<pos;i++)
			if(i==0)
				printf("%d",ret[i]);
			else
				printf(" %d",ret[i]);
		printf("\n");
	}
	return 0;
}
/*
InputData:
4 3
1 2
2 3
4 3
OutputData:
1 2 4 3
*/

