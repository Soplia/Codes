/*
Subject:×Ö·û´®ÄÚÅÅĞò 
ID:1054
Complier:Devcpp
Author:JiaruiXie
StartTime:15/03/17 10:19
Result:Accepted
EndTime:15/03/17 10:24
*/

#include <stdio.h>
#include <string.h>
#include <algorithm>
#define N 300
using namespace std;

char arr[N];

bool cmp(char a,char b)
{
	return a<b;
}

int main()
{
	while(gets(arr))
	{
		int len=strlen(arr);
		sort(arr,arr+len,cmp);
		puts(arr);
	}
	return 0; 
} 

/*
InputData:
bacd
OutputData:
abcd 
*/

