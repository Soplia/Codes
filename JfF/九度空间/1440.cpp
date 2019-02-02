/*
Subject:Goldbach's Conjecture
ID:1440
Complier:Devcpp
Author:JiaruiXie
StartTime:20/03/17 20:54
Result:
EndTime:
*/

#include <stdio.h>
#define N 10000

int arr[N];

void pre()
{
	arr[0]=arr[1]=0;
	for(int i=2;i<N;i++)
		arr[i]=1;
	for(int i=2;i<N;i++)
		if(arr[i])
			for(int j=2;i*j<N;j++)
				arr[i*j]=0;
}

int main()
{
	int n,temp;
	pre();
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		int cnt=0;
		for(int i=2;i<=n;i++)
			if(arr[i])
			{
				temp=n-i;
				if(arr[temp])
					cnt++;
			}
		printf("%d\n",cnt);
	}
	return 0;
}

/*
InputData:
6
10
12
0
OutputData:
1
2
1
*/

