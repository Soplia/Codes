/*
Subject:search
ID:2.9
Complier:Devcpp
Author:JiaruiXie
StartTime:06/02/17 11:38
Result:Accepted
EndTime:06/02/17 11:41
*/
#include <stdio.h>
#define N 300

int array[N];

int main()
{
	int n,x,temp;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&array[i]);
		scanf("%d",&x);
		int pos=-1;
		for(int i=0;i<n;i++)
			if(array[i]==x)
			{
				pos=i;
				break;
			}
		
		printf("%d\n",pos);
	}
	return 0;
}
/*
InputData:
2 
1 3
0
OutputData:
-1
*/

