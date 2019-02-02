/*
Subject:sort
ID:2.2
Complier:Devcpp
Author:JiaruiXie
StartTime:05/02/17 19:54
Result:Accepted
EndTime:05/02/17 20:36
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define N 2000
using namespace std;

typedef struct stu
{
	char name[101];
	int age;
	int score;
	bool operator < (const stu &a)const
	{
		int tem= strcmp(name,a.name);
		if(score!=a.score)	
			return score<a.score;
		else if(tem!=0)
			return tem<0;
		else
			return age<a.age;
	}
}Stu;

Stu array[N];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%s%d%d",array[i].name,&array[i].age,&array[i].score);
		
		sort(array,array+n);
		
		for(int i=0;i<n;i++)
			printf("%s %d %d\n",array[i].name,array[i].age,array[i].score);
		
		
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

