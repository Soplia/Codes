/*
	Subject:Prime_Ring_回溯枚举 
    Compiler:Devcpp
	Description: 
	Author:JiaruiXie
	Id:6-4-1
	Date_Begin:19/01/17 19:28
	Date_End:19/01/17 20:16
*/
#include <stdio.h>
#include <math.h>
#define N 20

bool hash[N];
int ans[N];
int n;
int prime[11]={ 2
			 ,3
			 ,5
			 ,7
			 ,11
			 ,13
			 ,17
			 ,19
			 ,23
			 ,29
			 ,31
			};
			
bool isPrime(int x)
{
	for(int i=0;i<11;i++)
		if(prime[i]==x)
			return true;
	return false;
}

void print()
{
	if(!isPrime(ans[n]+ans[1]))
		return ;
	for(int i=1;i<=n;i++)
	{
		if(i==1)
			printf(" ");
		printf("%d ",ans[i]);
	}
	printf("\n");
}

void DFS(int num)
{
	if(num>1&&!isPrime(ans[num-1]+ans[num]))
		return ;
	if(num==n)
	{
		print();
		return;
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
		printf("Case %d:\n",cas);
		for(int i=0;i<=n;i++)	
			hash[i]=false;
		ans[1]=1;
		hash[1]=true;
		DFS(1);
	}
	return 0;
}
/*
测试数据
样例输入
6 
8
样例输出
Case 1:
1 4 3 2 5 6
1 6 5 2 3 4 
Case 2:
1 2 3 8 5 6 7 4
1 2 5 8 3 4 7 6
1 4 7 6 5 8 3 2
1 6 7 4 3 8 5 2
*/





























