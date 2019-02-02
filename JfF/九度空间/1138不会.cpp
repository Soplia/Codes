/*
Subject:½øÖÆ×ª»» 
ID:1138
Complier:Devcpp
Author:JiaruiXie
StartTime:20/03/17 09:46
Result:
EndTime:
*/

#include <stdio.h>
#define N 100

int arr[N];
char a[N];
int size;

void pre()
{
	size=0;
	for(int i=0;a[i]!=0;i++)
		arr[size++]=a[i]-'0';
}

int main()
{
	while(gets(a))
	{
		pre();
		
	}
	return 0;
}

/*
InputData:
0
1
3
8
OutputData:
0
1
11
1000
*/

