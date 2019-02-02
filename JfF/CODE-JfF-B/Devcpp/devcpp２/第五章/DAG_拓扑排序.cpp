/*
	Subject:DAG_拓扑排序 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:5-5-1
	Date_Begin:18/01/17 14:35
	Date_End:
*/
#include <stdio.h>
#include <vector>
#include <queue>
#define N 100
using namespace std;

queue<int>myQ;
vector<int>myV[N];
int inD[N];
int count;

void init()
{
	count=0;
	while(!myQ.empty())
		myQ.pop();
	for(int i=0;i<N;i++)
	{
		myV[i].clear();
		inD[i]=0;
	}
}

int main()
{
	int dot ,edge;
	while(scanf("%d%d",&dot,&edge)!=EOF)
	{
		if(dot==0&&edge==0)
			break;
		init();
		int head,rear;
		while(edge--)
		{
			scanf("%d%d",&head,&rear);
			inD[rear]++;
			myV[head].push_back(rear);
		}
		
		for(int i=0;i<dot;i++)
			if(inD[i]==0)
				myQ.push(i);
		
		while(!myQ.empty())
		{
			count++;
			int t=myQ.front();
			myQ.pop();
			for(int i=0;i<myV[t].size();i++)
			{
				inD[myV[t][i]]--;
				if(inD[myV[t][i]]==0)
					myQ.push(myV[t][i]);
			}
		}
		if(count==dot)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

/*
测试数据
样例输入
3 2
0 1 
1 2 
2 2
0 1
1 0
0 0
样例输出
YES
NO
*/



























