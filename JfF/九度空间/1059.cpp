/*
Subject:abc 
ID:1059
Complier:Devcpp
Author:JiaruiXie
StartTime:26/03/17 08:21
Result:Accepted
EndTime:26/03/17 08:24
*/

#include <stdio.h>

int main()
{
	for(int a=0;a<10;a++)
		for(int b=0;b<10;b++)
			for(int c=0;c<10;c++)
			{
				int abc=a*100+b*10+c;
				int bcc=b*100+c*10+c;
				if(abc+bcc==532)
					printf("%d %d %d\n",a,b,c);
			}
			
	return 0;
}

/*
InputData:

OutputData:

*/

