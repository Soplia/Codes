/*
	Subject:Hash_求前m大数_可能相同
    Compiler:Devcpp
	Description:输入有可能相同，并且都是整数 
	Author:JiaruiXie
	Id:2-3-3
	Date_Begin:05/01/17 18:34
	Date_End:05/01/17 18:42
*/

#include <stdio.h>

int hash[1000001]={0};
int offset=500000;

int main()
{
	int n,m;
	int temp;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&temp);
			hash[(temp+offset)%1000001]++;
		}
		int count=0;
		for(int i=offset*2;i>=0;i--)
		{ 
			while(hash[i]!=0)//如果有多个相同值，修改这个地方就可以了 
			{
				hash[i]--;
				printf("%d ",i-offset);
				count++;
			}
			if(count==m)//另外这个地方也要更改 
				break;
		} 
		printf("\n");
	}
	return 0;
}









