/*
Subject:êlå©êlà§ 
ID:4.10
Complier:Devcpp
Author:JiaruiXie
StartTime:04/02/17 21:09
Result:
EndTime:
*/

#include <stdio.h>

int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if(a==0||b==0)
			break;
		int ans=1;
		int is;
		int pow=1;
		do
		{
			is=b&1;
			if(is)
				ans=(ans*a)%1000;
				
			b>>=1;
			a=((a%1000)*(a%1000))%1000;
		}while(b);
		printf("%d\n",ans);
	}
	return 0;
}

/*
InputData:
2 3
12 6
6789 10000
0 0
OutputData:
8
984
1
*/
































