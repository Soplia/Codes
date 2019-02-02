/*
Subject:ç≈é∆êî (Ç≥Ç¢ÇµÇŒÇµÇŒÇ©Ç∏)
ID:2011_2
Complier:Devcpp
Author:JiaruiXie
StartTime:06/02/17 20:02
Result:Accepted
EndTime:06/02/17 20:19
*/
#include <stdio.h>
#define N 20

int hash[N];

void init()
{
	for(int i=0;i<N;i++)
		hash[i]=0;
}

void dis()
{
	for (int i=1;i<=10;i++) 
		printf("%d ",hash[i]);
	printf("\n");
}

int main()
{
	int temp;
	while(scanf("%d",&temp)!=EOF)
	{
		init();
		hash[temp]++;
		int n=19;
		while(n--)
		{
			scanf("%d",&temp);	
			hash[temp]++;
		}
		int min=hash[1],pos=1;
		for(int i=2;i<=10;i++)
			if(hash[i]>min)
			{
				min=hash[i];
				pos=i;
			}
		printf("%d\n",pos);
	}
}
/*
InputData:
5 1 5 10 3 5 3 4 8 6 8 3 6 5 10 7 10 2 6 2 
OutputData:
5
*/

