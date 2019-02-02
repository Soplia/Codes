/*
Subject:2010_4
ID:2010_4
Complier:Devcpp
Author:JiaruiXie
StartTime:06/02/17 22:00
Result:Accepted
EndTime:06/02/17 22:05
*/
#include <stdio.h>
#include <string.h>
#define N 1000

char aim[N];

int main()
{
	while(scanf("%s",aim)!=EOF)
	{
		char temp;
		int len=strlen(aim);
		
		for(int i=0;i<len-1;i++)
			for(int j=0;j<len-1-i;j++)
				if(aim[j]>aim[j+1])
				{
					temp=aim[j];
					aim[j]=aim[j+1];
					aim[j+1]=temp;
				}
		printf("%s\n",aim);
	}
	return 0;
}
/*
InputData:
bacd
OutputData:
abcd
*/

