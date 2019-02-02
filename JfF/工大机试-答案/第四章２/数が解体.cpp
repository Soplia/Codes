/*
Subject:”‚ª‰ğ‘Ì 
ID:4.1
Complier:Devcpp
Author:JiaruiXie
StartTime:04/02/17 16:04
EndTime:04/02/17 16:11
*/
#include <stdio.h>
#define N 10

int a[N],b[N];

int main()
{
	long aa,bb;
	while(scanf("%ld%ld",&aa,&bb)!=EOF)
	{
		int size1=0,size2=0;
		do
		{
			a[size1++]=aa%10;
			aa/=10;
		}while(aa);
		do
		{
			b[size2++]=bb%10;
			bb/=10;
		}while(bb);
		
		int ans=0;
		for(int i=0;i<size1;i++)
			for(int j=0;j<size2;j++)
				ans+=a[i]*b[j];
		printf("%d\n",ans);
	}
	return 0;
}

/*
InputData:
123 45
OutputData:
54
*/

