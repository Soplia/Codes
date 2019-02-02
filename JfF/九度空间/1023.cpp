/*
Subject:Excel排序 
ID:1023
Complier:Devcpp
Author:JiaruiXie
StartTime:15/03/17 09:45
Result:Accept 请注意题目中给出的输出格式 
EndTime:28/03/17 21:28
*/
#include <stdio.h>
#include <string.h>
#include <algorithm> 
#define N 200000
using namespace std;

typedef struct node
{
	int num;
	char name[10];
	int score;
}Node;

Node arr[N];

bool cmp1(Node a,Node b) 
{
	return a.num<b.num;
}

bool cmp2(Node a,Node b)
{
	int ret=strcmp(a.name,b.name);
	//这个地方不能够使用if(!ret)
	//因为这个地方涉及到负数
	//如果是负数的话也会使之成立 
	if(ret!=0)
	{
		return ret<0;
	}
	else
		return a.num<b.num;
}

bool cmp3(Node a,Node b)
{
	if(a.score!=b.score)
		return a.score<b.score;
	else
		return a.num<b.num;
}

int main()
{
	int n,type,cas=0;
	while(scanf("%d%d",&n,&type)!=EOF)
	{
		cas++;
		if(n==0)
			break;
		else
		{
			for(int i=0;i<n;i++)
				scanf("%d %s %d",&arr[i].num,arr[i].name,&arr[i].score);
			switch(type)
			{
				case 1:sort(arr,arr+n,cmp1);break;
				case 2:sort(arr,arr+n,cmp2);break;
				case 3:sort(arr,arr+n,cmp3);break;
			}
			printf("Case %d:\n",cas);
			for(int i=0;i<n;i++)
				printf("%06d %s %d\n",arr[i].num,arr[i].name,arr[i].score);
		}
	}
	return 0;
}
/*
InputData:
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98
4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
0 0
OutputData:
Case 1:
000001 Zoe 60
000007 James 85
000010 Amy 90
Case 2:
000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60
Case 3:
000001 Zoe 60
000007 James 85
000002 James 90
000010 Amy 90
*/

