/*
Subject:hash_sort
ID:2.6
Complier:Devcpp
Author:JiaruiXie
StartTime:06/02/17 10:05
Result:Accepted 4820 kb	360 ms
EndTime:06/02/17 10:24
*/
#include <stdio.h>
#define N 1000001
#define n 500000

int hash[N];


int main()
{
	int nn,m,temp;
	while(scanf("%d%d",&nn,&m)!=EOF)
	{
		for(int i=0;i<N;i++)
			hash[i]=0;
			
		while(nn--)
		{
			scanf("%d",&temp);
			hash[temp+n]=1;
		}
		
		for(int i=N-1;i>=0;i--)
			if(hash[i])
			{
				printf("%d",i-n);
				m--;
				if(m!=0)
					printf(" ");
				else
				{
					printf("\n");
					break;
				}	
			}
			
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

