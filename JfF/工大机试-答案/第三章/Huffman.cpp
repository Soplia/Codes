/*
Subject:Huffman
ID:3.3
Complier:Devcpp
Author:JiaruiXie
StartTime:05/02/17 15:19
Result:Accepted
EndTime:05/02/17 15:37
*/
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int ,vector<int>,greater<int> > myQ;

int main()
{
	int size;
	while(scanf("%d",&size)!=EOF&&size!=0)
	{
		int ans=0;
		while(!myQ.empty())
			myQ.pop();
			
		while(size--)
		{
			int temp;
			scanf("%d",&temp);
			myQ.push(temp);
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

