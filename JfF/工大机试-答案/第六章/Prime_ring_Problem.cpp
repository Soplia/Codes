/*
	Subject:Prime_ring_Problem
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:6.5
	Date_Begin:03/02/17 11:25
	Result:Accepted
	Date_End:03/02/17 11:56
*/
#include <stdio.h>
#define N 100

int ans[N];
int hash[N];
int size;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41};


int judge(int x)
{
	for(int i=0;i<13;i++)
		if(prime[i]==x)
			return 1;
	return 0;
}

void check()
{
	if(judge(ans[size]+ans[1]))
	{
		for(int i=1;i<=size;i++)
		{
			if(i!=1)
				printf(" ");
			printf("%d",ans[i]);
		}	
		printf("\n");
	}
}

void DFS(int x)
{
	if(x>1)
		if(!judge(ans[x]+ans[x-1]))
			return ;
	if(x==size)
	{
		check();
		return ;
	}
	for(int i=2;i<=size;i++)
	{
		if(!hash[i])
		{
			ans[x+1]=i;
			hash[i]=1;
			DFS(x+1);
			hash[i]=0;
		}
	}
}

int main()
{
	int cas=0;
	while(scanf("%d",&size)!=EOF)
	{
		cas++;
		for(int i=0;i<N;i++)
			hash[i]=0;
		ans[1]=1;
		hash[1]=1;
		printf("Case %d:\n",cas);
		DFS(1);
		printf("\n");
	}
	return 0;
}

/*
InputData:
6
8
outputData:
Case 1:
1 4 3 2 5 6
1 6 5 2 3 4
Case 2:
1 2 3 8 5 6 7 4
1 2 5 8 3 4 7 6
1 4 7 6 5 8 3 2
1 6 7 4 3 8 5 2
*/

















