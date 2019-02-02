/*
Subject:À¹½Øµ¼µ¯ 
ID:1112
Complier:Devcpp
Author:JiaruiXie
StartTime:27/03/17 18:56
Result:Accepted
EndTime:27/03/17 19:20
*/

#include <stdio.h>
#define N 30

int ret[N];
int arr[N];

int main()
{
	int n;
	int max;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			ret[i]=1;
			scanf("%d",&arr[i]);
		}	
		for(int i=1;i<n;i++)
		{
			max=1;
			for(int j=0;j<i;j++)
				if(arr[j]>=arr[i]&&ret[j]+1>max)
					max=ret[j]+1;
			ret[i]=max;
		}
		
		max=ret[0];
		for(int i=1;i<n;i++)	
			if(ret[i]>max)
				max=ret[i];
		printf("%d\n",max);
	}
	return 0;
}

/*
InputData:
8
300 207 155 300 299 170 158 65
OutputData:
6
*/

