/*
Subject:成绩排序 
ID:1061
Complier:Devcpp
Author:JiaruiXie
StartTime:15/03/17 09:08
Result:Accepted
EndTime:15/03/17 09:19
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define N 2000
using namespace std;

typedef struct node
{
	char name[100];
	int age;
	double score;
	
	//这个地方因为是要重写函数，所以如果不加上const的话，在oj上
	//编译就会通不过；但是在自己的编译器中还是能够正常运行的。 
	bool operator < (const node &temp) const 
	{
		if(score<temp.score)
			return true;
		else if(score==temp.score)
		{
			if(strcmp(name,temp.name)<0)
				return true;
			else if(!strcmp(name,temp.name))
			{
				return age<temp.age;
			}
			else
				return false;
		}
		else
			return false;
	}
	
}Node;

Node arr[N];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%s%d%lf",arr[i].name,&arr[i].age,&arr[i].score);
		
		sort(arr,arr+n);
		
		for(int i=0;i<n;i++)
			printf("%s %d %.lf\n",arr[i].name,arr[i].age,arr[i].score);
	}
	return 0;
}
/*
InputData:
3
abc 20 99
bcd 19 97
bed 20 97
OutputData:
bcd 19 97
bed 20 97
abc 20 99
*/

