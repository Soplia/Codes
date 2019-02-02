/*
Subject:¹þ¸¥ÂüÊ÷ 
ID:1172
Complier:Devcpp
Author:JiaruiXie
StartTime:17/03/17 09:32
Result:Accepted
EndTime:17/03/17 09:47
*/

#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<int ,vector<int>,greater<int> > myQ;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		while(!myQ.empty())
			myQ.pop();
			
		int x;
		int ans=0;
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
		printf("%d\n",ans);
	}
	return 0;
}

/*
InputData:
5  
1 2 2 5 9
OutputData:
37
*/

