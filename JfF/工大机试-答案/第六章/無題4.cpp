#include <stdio.h>
#define N 100

int size;
bool hash[N];
int ans[N];
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41};

bool judge(int x)
{
	for(int i=0;i<13;i++)
		if(prime[i]==x)
			return true;
	return false;
}

void check()
{
	if(!judge(ans[size]+ans[1]))
		return ;
	for(int i=1;i<=size;i++)
	{
		if(i!=1)
			printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
}

void DFS(int x)
{
	if(x>1&&!judge(ans[x]+ans[x-1]))
		return ;
	if(x==size)	
	{
		check();
		return ;
	}
	for(int i=2;i<=size;i++)
		if(!hash[i])
		{
			ans[x+1]=i;
			hash[i]=true;
			DFS(x+1);
			hash[i]=false;
		}
}

int main()
{
	int cas=0;
	while(scanf("%d",&size)!=EOF)
	{
		cas++;
		for(int i=0;i<N;i++)
			hash[i]=false;
		ans[1]=1;
		hash[1]=true;
		printf("Case %d:\n",cas);
		DFS(1);
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
















