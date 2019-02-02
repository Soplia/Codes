/*
Subject:Sort 
ID:1431
Complier:Devcpp
Author:JiaruiXie
StartTime:16/03/17 08:36
Result:Accepted
EndTime:30/03/17 10:21
*/

#include <stdio.h>
#define offset 500000

int hash[offset*2+1];

int main()
{
	int m,n,flag;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		//注意要想个int类型的数组进行全部赋值
		//int arr[N]={0}是不行的，这个只能给
		//数组的第一个元素进行赋值。所以还是
		//需要使用循环来给数组进行传统的赋值。 
		for(int i=0;i<offset*2+1;i++) 
			hash[i]=0;
			
		int temp;
		flag=true;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&temp);
			hash[temp+offset]=1;
		}
		for(int i=offset*2;i>=0&&m;i--)
			if(hash[i])
			{
				m--;
				if(!flag)
					printf(" ");
				printf("%d",i-offset);
				flag=0;
			}
		printf("\n");
	}
	return 0;
}

/*
InputData:
5 3
3 -35 92 213 -644
OutputData:
213 92 3
*/

