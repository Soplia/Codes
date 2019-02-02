/*
Subject:Prime Number 
ID:1040
Complier:Devcpp
Author:JiaruiXie
StartTime:20/03/17 20:33
Result:Accepted
EndTime:20/03/17 20:53
*/

#include <stdio.h>
#define N 1000000

//这个地方为什么不能将数组的值全部赋值为1？ 
int arr[N]={1};

void pre()
{
	for(int i=2;i<N;i++)
		arr[i]=1;
	for(int i=2;i<N;i++)
		if(arr[i])
			for(int j=2;i*j<N;j++)
				arr[i*j]=0;
}

int main()
{
	int cnt;
	
	pre();
	while(scanf("%d",&cnt)!=EOF)
	{
		int i;
		for(i=2;i<N&&cnt;i++)
			if(arr[i])
				cnt--;
		printf("%d\n",i-1);
	}
	return 0;
}
/*
InputData:
3
7
OutputData:
5
17
*/

