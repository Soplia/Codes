/*
Subject:to 2
ID:4.3
Complier:Devcpp
Author:JiaruiXie
StartTime:04/02/17 17:36
EndTime:04/02/17 17:50
Result:Accept
*/

#include <stdio.h>
#include <string.h>
#define N 20

char ans[N];

int main()
{
	int a,b;
	char s[N];
	while(scanf("%d%s%d",&a,s,&b)!=EOF)
	{
		int temp=0;
		int pow=1;
		for(int i=strlen(s)-1;i>=0;i--)
		{
			if(s[i]>='0'&&s[i]<='9')
				temp+=(s[i]-'0')*pow;
			else if(s[i]>='a'&&s[i]<='z')
				temp+=(s[i]-'a'+10)*pow;
			else 
				temp+=(s[i]-'A'+10)*pow;
			pow*=a;
		}
		
		int size=0;
		int term;
		do
		{
			term=temp%b;
			ans[size++]=(term<10)?term+'0':term-10+'A';
			temp/=b;
		}while(temp);
		for(int i=size-1;i>=0;i--)
			printf("%c",ans[i]);
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





















