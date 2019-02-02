/*
Subject:≈≈–Ú 
ID:1202
Complier:Devcpp
Author:JiaruiXie
StartTime:15/03/17 08:58
Result:Accept
EndTime:15/03/17 09:06
*/
#include <stdio.h>
#include <algorithm>
#define N 200
using namespace std;

int arr[N];

bool cmp(int a,int b)
{
	return a<b;	
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		sort(arr,arr+n,cmp);
		for(int i=0;i<n;i++)
			printf("%d ",arr[i]);
		printf("\n");
	}
	return 0;
}
/*
InputData:
4
1 4 3 2
OutputData:
1 2 3 4
*/
 
