/*
	Subject:×éºÏÊý 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:
	Date_Begin:19/01/17 20:44
	Date_End:
*/
#include <stdio.h>
#define N 20

bool hash[N];
int ans[N];
int n;

void print()
{
	for(int i=1;i<=n;i++)
		printf("%d ");
	printf("\n");
}

void DFS(int num)
{
	if(num==n)
		print();
	for(int i=1;i<=n;i++)
		if(!hash[i])
		{
			hash[i]=true;
			ans[num]=i;
			hash[i]=false;
		}
}



















