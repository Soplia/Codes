/*
Subject: ëfêî 
ID:4.7
Complier:Devcpp
Author:JiaruiXie
StartTime:04/02/17 18:27
Result:Accepted
EndTime:04/02/17 20:07
*/
#include <stdio.h>
#define N 10001

int ans[N];

//void dis(int x)
//{
//	for(int i=2;i<=x;i++)
//		if(ans[i])
//			printf("%d ",i);
//}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int flag=1;
		ans[0]=ans[1]=0;
		for(int i=2;i<n;i++)
			ans[i]=1;
		
		for(int i=2;i<n;i++)
			if(ans[i])
				for(int j=2;j*i<n;j++)
					ans[j*i]=0;
		
		//dis(n);
		
		for(int i=2;i<n;i++)
			if(i%10==1&&ans[i])
			{
				if(flag)
					printf("%d",i);
				else
					printf(" %d",i);
				flag=0;
			}
			
		if(flag)
			printf("-1");
		printf("\n");
	}
	return 0;
}
/*
InputData:
100
OutputData:
11 31 41 61 71
*/






























