/*
Subject:”r”Å 
ID:2.7
Complier:Devcpp
Author:JiaruiXie
StartTime:06/02/17 10:29
Result:Accepted
EndTime:
*/
#include <stdio.h>

int main()
{
	int size;
	while(scanf("%d",&size)!=EOF)	
	{
		for(int i=1;i<=size;i++)		
		{
			for(int j=1;j<=(size-i)*2;j++)
				printf(" ");
			for(int k=1;k<=size+(i-1)*2;k++)
				printf("*");
			printf("\n");
		}
	}
	return 0;
} 

/*
InputData:
4
OutputData:
      ****
    ******
  ********
********** 
*/

