/*
Subject:不容易系列之一 
ID:1451
Complier:Devcpp
Author:JiaruiXie
StartTime:27/03/17 18:40
Result:Accepted
EndTime:27/03/17 18:43
*/

#include <stdio.h>
#define N 21

long long arr[N];

int main()
{
	arr[1]=0;
	arr[2]=1;
	for(int i=3;i<N;i++)
		arr[i]=(i-1)*arr[i-1]+(i-1)*arr[i-2];
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%lld\n",arr[n]);
	}
	return 0;
}

/*
InputData:

OutputData:

*/

