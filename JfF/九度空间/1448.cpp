/*
Subject:Õÿ∆À≈≈–Ú 
ID:1448
Complier:Devcpp
Author:JiaruiXie
StartTime:24/03/17 09:13
Result:Accepted
EndTime:24/03/17 09:33
*/

#include <stdio.h>
#include <vector>
#include <queue>
#define N 501
using namespace std;

vector<int> edge[N];
int cnt;
int inDeg[N];
queue<int> myQ;

void pre()
{
	while(!myQ.empty())
		myQ.pop();
	for(int i=0;i<N;i++)
	{
		inDeg[i]=0;
		edge[i].clear();
	}	
	cnt=0;
}

int main()
{
	int n,m;
	int a,b;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		pre();
		while(m--)
		{
			scanf("%d%d",&a,&b);
			inDeg[b]++;
			edge[a].push_back(b);
		}
		for(int i=0;i<n;i++)
			if(inDeg[i]==0)
				myQ.push(i);
				
		while(!myQ.empty())
		{
			int a=myQ.front();
			myQ.pop();
			cnt++;
			for(int i=0;i<edge[a].size();i++)
			{
				inDeg[edge[a][i]]--;
				if(inDeg[edge[a][i]]==0)
					myQ.push(edge[a][i]);
			}
		}
		
		if(cnt==n)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
/*
InputData:
3 2
0 1
1 2
2 2
0 1
1 0
0 0
OutputData:
YES
NO
*/

