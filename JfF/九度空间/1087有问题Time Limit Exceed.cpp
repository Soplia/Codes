/*
Subject:约数的个数 
ID:1087
Complier:Devcpp
Author:JiaruiXie
StartTime:20/03/17 21:23
Result:Time Limit Exceed
EndTime:21/03/17 07:40
*/

#include <stdio.h>
#define N 1001

long long arr[N];

int main()
{
	int size;
	while(scanf("%d",&size)!=EOF)
	{
		if(size==0)
			break;
		for(int i=0;i<size;i++)
			scanf("%lld",&arr[i]);
		int ans;
		for(int i=size-1;i>=0;i--)
		{
			ans=0;
			for(long long j=1;j<=arr[i];j++)
				if(arr[i]%j==0)
					ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}

/*
InputData:
5
1 3 4 6 12
OutputData:
1
2
3
4
6
*/

