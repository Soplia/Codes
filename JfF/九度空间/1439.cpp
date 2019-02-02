/*
Subject:Least Common Multiple
ID:1439
Complier:Devcpp
Author:JiaruiXie
StartTime:20/03/17 20:17
Result:Wrong Answer
EndTime:31/03/17 09:30
*/

#include <stdio.h>
#include <queue>
using namespace std;
//注意题目中给出的输入数据的要求是在32位之内
//所以应该使用longlong类型的变量进行存储。 
queue<long long>myQ;

long long lcm(long long a,long long b)
{
	long long temp=a*b;
	while(a!=b)
		if(a>b)
			a-=b;
		else 
			b-=a;
	return temp/a;
}

int main()
{
	int size,m;
	long long temp,a,b;
	while(scanf("%d",&size)!=EOF)
	{
		while(size--)
		{
			while(!myQ.empty())
				myQ.pop();
				
			scanf("%d",&m);
			while(m--)
			{
				scanf("%lld",&temp);
				myQ.push(temp);
			}
			while(myQ.size()!=1)
			{
				a=myQ.front();
				myQ.pop();
				b=myQ.front();
				myQ.pop();
				temp=lcm(a,b);
				//printf("a=%d,b=%d,temp=%d\n",a,b,temp);
				myQ.push(temp);
			}
			printf("%lld\n",myQ.front());
		}
	}
	return 0;
}

/*
InputData:
2
3 5 7 15
6 4 10296 936 1287 792 1
OutputData:
105
10296
*/

