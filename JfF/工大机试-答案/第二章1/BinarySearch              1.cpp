/*
Subject:BinarySearch
ID:2.10
Complier:Devcpp
Author:JiaruiXie
StartTime:06/02/17 11:42
Result:Wrong Answer
EndTime:
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define N 2000
using namespace std;

typedef struct node
{
	char num[10000];
	char name[20];
	char sex[20];
	int age;
	bool operator < (const node &a)const
	{
		return strcmp(num,a.num)<0;
	}
}node;

node array[N];

int main()
{
	int n,m;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%s%s%s%d",array[i].num,array[i].name,array[i].sex,
					&array[i].age);
		
		sort(array,array+n);
		
		scanf("%d",&m);
		
		while(m--)
		{
			int ans=0;
			char temp[10000];
			scanf("%s",temp);
			
			int low=0,high=n-1;
			while(low<=high)
			{
				int mid=(low+high)/2;
				if(!strcmp(array[mid].num,temp))
				{
					printf("%s %s %s %d\n",array[mid].num,array[mid].name,
					array[mid].sex,array[mid].age);
					ans=1;
					break;
				}
				else if(strcmp(array[mid].num,temp)>0)
					high=mid-1;
				else
					low=mid+1;
			}
			if(!ans)
				printf("No Answer!\n");
		}
		
	}
	return 0;
}
/*
InputData:
4
01 a m 21
02 b m 23
03 c m 19
04 d f 19
5
02
03
01
04
03
OutputData:
02 b m 23
03 c m 19
01 a m 21
04 d f 19
03 c m 19
*/

