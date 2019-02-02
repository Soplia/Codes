/*
Subject:N½×ÉÏÂ¥ÎÊÌâ 
ID:1205
Complier:Devcpp
Author:JiaruiXie
StartTime:27/03/17 18:31
Result:Accepted
EndTime:27/03/17 18:38
*/

#include <stdio.h>
#define N 91

long long arr[N];


int main()
{
	arr[1]=1;
	arr[2]=2;
	
	for(int i=3;i<N;i++)
		arr[i]=arr[i-1]+arr[i-2];
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%lld\n",arr[n]);
	}
	return 0;
}
/*
InputData:
4
OutputData:
5
*/

