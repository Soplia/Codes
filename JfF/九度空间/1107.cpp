/*
Subject:°áÆ»¹û 
ID:1107
Complier:Devcpp
Author:JiaruiXie
StartTime:17/03/17 09:53
Result:Accepted
EndTime:17/03/17 10:02
*/

#include <stdio.h>
#include <queue> 
using namespace std;

priority_queue<int,vector<int> , greater<int> > myQ;
unsigned long ans;

void pre()
{
	while(!myQ.empty())
	{
		myQ.pop();
	}
	ans=0;
}

int main()
{
	int n;
	int x;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		pre();
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			myQ.push(x);
		}
		
		while(myQ.size()>1)
		{
			int a=myQ.top();
			myQ.pop();
			int b=myQ.top();
			myQ.pop();
			ans+=a+b;
			myQ.push(a+b);
		}
		
		printf("%lu\n",ans);
	}
	return 0;
} 

/*
InputData:
3
9 1 2
0
OutputData:
15
*/

