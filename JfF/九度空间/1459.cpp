/*
Subject:Prime ring problem 
ID:1459
Complier:Devcpp
Author:JiaruiXie
StartTime:26/03/17 20:25
Result:Accepted
EndTime:26/03/17 20:51
*/

#include <stdio.h>
#include <string.h>
#define N  22
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41};
int ans[N];
bool hash[N];
int n;

int judge(int x)
{
	for(int i=0;i<13;i++)
		if(prime[i]==x)
			return 1;
	return 0;
}

void check()
{
	if(!judge(ans[1]+ans[n]))
		return ;
	for(int i=1;i<=n;i++)
	{
		if(i!=1)
			printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
}

void DFS(int num)
{
	if(num>1)
		if(!judge(ans[num]+ans[num-1]))
			return ;
	if(num==n)
	{
		check();
		return ;
	}
		
	for(int i=2;i<=n;i++)
		if(!hash[i])
		{
			hash[i]=true;
			ans[num+1]=i;
			DFS(num+1);
			hash[i]=false;
		}
}

int main()
{
	int cas=0;
	while(scanf("%d",&n)!=EOF)
	{
		cas++;
		ans[1]=1;
		hash[1]=true;
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
OutputData:
Case 1:
1 4 3 2 5 6
1 6 5 2 3 4

Case 2:
1 2 3 8 5 6 7 4
1 2 5 8 3 4 7 6
1 4 7 6 5 8 3 2
1 6 7 4 3 8 5 2
*/

