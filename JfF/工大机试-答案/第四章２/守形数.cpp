/*
Subject:��`�� 
ID:1183
Complier:Devcpp
Author:JiaruiXie
StartTime:04/02/17 13:10
EndTime:04/02/17 13:28
*/
#include <stdio.h>
#include <string.h>

int main()
{
	int a;
	while(scanf("%d",&a)!=EOF)	
	{
		int flag=1;
		int b=a*a;
		
		char tempa[100];
		char tempb[100];
		
		sprintf(tempa,"%d",a); 
		sprintf(tempb,"%d",b);
		
		for(int i=strlen(tempa)-1,j=strlen(tempb)-1;i>=0;i--,j--)
			if(tempa[i]!=tempb[j])
			{
				flag=0;
				break;
			}
		
		puts(flag?"Yes!":"No!");
	}
	return 0;
}

/*
InputData:
25
4
OutputData:
Yes!
No!
*/
                                                                                                                                                                            
