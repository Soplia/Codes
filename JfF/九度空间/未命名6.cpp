#include <stdio.h>
#include <vector>
#include <queue>
#define N 501
using namespace std;

int cnt;
int inDeg[N];
queue<int> myQ;
vector<int> edge[N];

void pre()
{
	cnt=0;
	for(int i=0;i<N;i++)
	{
		inDeg[i]=0;
		edge[i].clear();
	}
	while(!myQ.empty())
		myQ.pop();
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		pre();
		
		int a,b;
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















