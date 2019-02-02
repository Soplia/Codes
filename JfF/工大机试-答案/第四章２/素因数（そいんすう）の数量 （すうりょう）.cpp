/*
Subject:素因数（そいんすう）の数量 （すうりょう） 
ID:
Complier:Devcpp
Author:JiaruiXie
StartTime:04/02/17 20:11
Result:Accept
EndTime:04/02/17 21:09
*/
#include <stdio.h>
#define N 100001

int prime[N];

void init()
{
	prime[0]=prime[1]=0;
	for(int i=2;i<N;i++)
		prime[i]=1;
		
	for(int i=2;i<N;i++)
		if(prime[i])
			for(int j=2;i*j<N;j++)
				prime[i*j]=0;
}

int main()
{
	int a;
	init();
	
	while(scanf("%d",&a)!=EOF&&a>1)
	{
		int ans=0;
		
		for(int i=2;i<N;i++)
		{
			if(a==1)
				break;
			if(prime[i])
				while(a%i==0)
				{
					ans++;
					a/=i;
				}
		}	
			
		if(a!=1)
			ans++;
		
		printf("%d\n",ans);
	}
	
	return 0;
}

/*
InputData:
120
OutputData:
5
*/








