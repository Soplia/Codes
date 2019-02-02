/*
	Subject:Leagal or Not
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:5.7
	Date_Begin:02/02/17 18:59
	Result:Accepted
	Date_End:05/02/17 13:34
*/
#include <stdio.h>
#include <queue>
#include <vector>
#define N 1000
using namespace std;

vector<int> Array[N];
queue<int> myQ;
int inD[N];
int cnt;

void init()
{
	for(int i=0;i<N;i++)
	{
		Array[i].clear();
		inD[i]=0;
	}
		
	if(!myQ.empty())
		myQ.pop();
	cnt=0;
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
			int h,r;
			scanf("%d%d",&h,&r);
			inD[r]++;
			Array[h].push_back(r);
		}
		
		for(int i=0;i<n;i++)
			if(!inD[i])
				myQ.push(i);
				
		
		while(!myQ.empty())
		{
			int h=myQ.front();
			myQ.pop();
			cnt++;
			for(int i=0;i<Array[h].size();i++)
			{
				inD[Array[h][i]]--;
				if(!inD[Array[h][i]])
					myQ.push(Array[h][i]);
			}
			
		}
		if(cnt==n)
			printf("YES\n");
		else
			printf("NO\n");
			
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
outputData:
YES
NO
*/

