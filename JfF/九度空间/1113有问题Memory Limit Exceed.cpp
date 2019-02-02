/*
Subject:¶þ²æÊ÷ 
ID:1113
Complier:Devcpp
Author:JiaruiXie
StartTime:18/03/17 08:45
Result:Memory Limit Exceed
EndTime:18/03/17 09:00
*/

#include <stdio.h>
#include <queue>
using namespace std;

int ans;
queue<unsigned long>myQ;

void pre()
{
	ans=0;
	while(!myQ.empty())
		myQ.pop();
}

int main()
{
	 long m,n;
	long long a,b,c;
	while(scanf("%lu%lu",&m,&n)!=EOF)
	{
		if(m==0&&n==0)
			break;
		pre();
		myQ.push(m);
		while(!myQ.empty())
		{
			int temp=myQ.front();
			myQ.pop();
			if(temp<=n)
			{
				ans++;
				myQ.push(temp*2);
				myQ.push(temp*2+1);
			}	
		}
		printf("%d\n",ans);
	}
	return 0;
}

/*
InputData:
3 12
0 0
OutputData:
4
*/

