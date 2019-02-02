/*
Subject:ÊØÐÎÊý 
ID:1183
Complier:Devcpp
Author:JiaruiXie
StartTime:20/03/17 08:58
Result:Accepted
EndTime:20/03/17 09:02
*/

#include <stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int temp=n*n;
		int flag=1;
		int nn,tt;
		do
		{
			nn=n%10;
			n/=10;
			tt=temp%10;
			temp/=10;
			if(nn!=tt)
			{
				flag=0;
				break;
			}
		}while(n);
		
		if(flag)
			puts("Yes!");
		else
			puts("No!");
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

