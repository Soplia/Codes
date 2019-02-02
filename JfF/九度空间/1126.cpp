/*
Subject:打印极值点下标 
ID:1126
Complier:Devcpp
Author:JiaruiXie
StartTime:16/03/17 09:42
Result:Accepted
EndTime:16/03/17 10:22
*/

#include <stdio.h>
#define N 100

int arr[N];
int hash[N];

int main()
{
	int n;
	int size;
	int flag;
	
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			for(int i=0;i<N;i++)
				hash[i]=0;
			flag=1;
			scanf("%d",&size);
			for(int i=0;i<size;i++)
				scanf("%d",&arr[i]);
				
			for(int i=1;i<size-1;i++)
			{
				int pos1=i-1;
				int pos2=i+1;
				if(arr[i]>arr[pos1]&&arr[i]>arr[pos2])
					hash[i]=1;
				else if(arr[i]<arr[pos1]&&arr[i]<arr[pos2])
					hash[i]=1;
			}
			
			if(arr[0]!=arr[1])
				hash[0]=1;
			if(arr[size-1]!=arr[size-2])
				hash[size-1]=1;
				
			for(int i=0;i<size;i++)	
				if(hash[i])
					if(flag)
					{
						printf("%d",i);
						flag=0;
					}
					else
						printf(" %d",i);
						
			printf("\n");
		}
		
	}
	return 0;
}

/*
InputData:
3
10
10 12 12 11 11 12 23 24 12 12
15
12 12 122 112 222 211 222 221 76 36 31 234 256 76 76 
15
12 14 122 112 222 222 222 221 76 36 31 234 256 76 73
OutputData:
0 7
2 3 4 5 6 10 12
0 2 3 10 12 14
*/

