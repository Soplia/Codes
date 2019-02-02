#include <stdio.h>
#include <vector>
using namespace std;

for(int i=0;i<n;i++)
	edge[i].clear();
	
Edge temp;
temp.nextNode=3;
temp.cost=38;
edge[1].push_back(temp);

for(int i=0;i<edge[2].size();i++)
{
	int nextNode=edge[2][i].nextNode;
	int cost=edge[2][i].cost;
}

edge[1].earse(edge[1].begin()+i,edge[1].begin()+i+1);

int Tree[N];

int findRoot(int x)
{
	if(Tree[x]==-1)
		return x;
	else
		return findRoot(Tree[x]);
}

int findRoot(int x)
{
	while(Tree[x]!=-1)
	{
		x=Tree[x];
	}
	return x;
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


int findRoot(int x)
{
	int temp=x;
	
	while(Tree[x]!=-1)
		x=Tree[x];
		
	int ret=x;
	x=temp;
	
	while(Tree[x]!=-1)
	{
		int t=Tree[x];
		Tree[x]=ret;
		x=t;
	}
	
	return ret;
}












