/*
Subject:
ID:
Complier:Devcpp
Author:JiaruiXie
StartTime:
Result:
EndTime:
*/
#include <stdio.h>
#include <string.h>

int main()
{
	char country[150][10];
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%s",country+i);
		char temp[10];
		for(int i=0;i<n-1;i++)
			for(int j=0;j<n-1-i;j++)
				if(strcmp(country[j],country[j+1])>0)
				{
					strcpy(temp,country[j]);
					strcpy(country[j],country[j+1]);
					strcpy(country[j+1],temp);
				}
		for(int i=0;i<n;i++)
			puts(*(country+i));
	}
	return 0;
}
/*
InputData:
5
America
England
Australia
Sweden
Finland
OutputData:

*/

