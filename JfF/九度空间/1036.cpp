/*
Subject:Old Bill
ID:1036
Complier:Devcpp
Author:JiaruiXie
StartTime:26/03/17 08:24
Result:Accepted
EndTime:26/03/17 08:54
*/

#include <stdio.h>

int main()
{
	int n,x,y,z;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d%d%d",&x,&y,&z);
		int flag=true;
		int i,j,temp;
		//因为题目要求最大的单价
		//所以从大向小开始枚举 
		for(i=9;i>=0;i--)
		{
            for(j=9;j>=0;j--)
			{
				temp=i*10000+x*1000+y*100+z*10+j;
				//利用课本上的技术 
				if((float)temp/n==temp/n)
				{
					flag=false;
					break;
				}
			}
			//要是进行中断，需要在i,j进行操作之前进行中断 
			if(!flag)
                break;
		}

		if(flag)
			puts("0");
		else
			printf("%d %d %d\n",i,j,temp/n);
	}
	return 0;
}

/*
InputData:
72
6 7 9
5
2 3 7
78
0 0 5
OutputData:
3 2 511
9 5 18475
0
*/

