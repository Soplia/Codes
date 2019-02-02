/*
Subject:≤È’“ 
ID:1173
Complier:Devcpp
Author:JiaruiXie
StartTime:16/03/17 10:22
Result:Accepted
EndTime:16/03/17 10:30
*/

#include <stdio.h>
#define N 200

int arr[N];
int aim[N];

int main()
{
	int n,m;
	int flag;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&arr[i]);
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
			scanf("%d",&aim[i]);
			
		for(int i=1;i<=m;i++)
		{
			flag=0;
			for(int j=1;j<=n;j++)
				if(arr[j]==aim[i])
				{
					printf("YES\n");
					flag=1;
					break;
				}
			if(!flag)
				printf("NO\n");
		}	
	}
	return 0;
}

/*
InputData:
5
1 5 2 4 3
3
2 5 6
OutputData:
YES
YES
NO
*/

