/*
Subject:to 
ID:4.3
Complier:Devcpp
Author:JiaruiXie
StartTime:04/02/17 16:50
EndTime:04/02/17 17:49
Result:Output Limit Exceed
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define N 20

int array[N];

char ans[]=
			{
			'0','1','2','3','4','5',
			'6','7','8','9','A','B','C','D','E','F'	
			};
			
int main()
{
	char n[N/2];
	int a,b;
	while(scanf("%d%s%d",&a,n,&b))
	{
		for(int i=0;i<strlen(n);i++)
			if(isalpha(n[i]))
				n[i]=tolower(n[i]);
		
		int temp=0;
		int pow=1;
		
		for(int i=strlen(n)-1;i>=0;i--)
		{
			
			if(isalpha(n[i]))
				temp+=(n[i]-87)*pow;
			else
				temp+=(n[i]-'0')*pow;
			pow*=a;
		}
		
		int size=0;
		
		do
		{
			array[size++]=temp%b;
			temp/=b;
		}while(temp);
		
		for(int i=size-1;i>=0;i--)
			printf("%c",ans[array[i]]);
			
		printf("\n"); 
	}
	return 0;
}

/*
InputData:
15 Aab3 7
OutputData: 
210306
*/




























