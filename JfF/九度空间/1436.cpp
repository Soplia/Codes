/*
Subject:Repair the Wall 
ID:1436
Complier:Devcpp
Author:JiaruiXie
StartTime:17/03/17 07:48
Result:Wrong Answer
EndTime:17/03/17 08:13
*/

#include <stdio.h>
#include <algorithm>
#define N 1000
using namespace std;

int arr[N];

int cmp(int a,int b)
{
	return a>b;
}

int main()
{
	unsigned long size;
	int n;
	while(scanf("%lu%d",&size,&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		sort(arr,arr+n,cmp);
		
		int flag=1;
		for(int i=0;i<n;i++)
		{
			if(size==0)
			{
				printf("%d\n",i);
				flag=0;
				break;
			}	
			if(size>=arr[i])
				size-=arr[i];
		}
		if(flag)
			printf("impossible\n");
	}
	
	return 0;	
} 

/*
InputData:
5 3
3 2 1
5 2
2 1
OutputData:
2
impossible
*/

