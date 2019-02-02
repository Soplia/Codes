/*
	Subject:Hash
    Compiler:Devcpp
	Description:给定N个整数，求等于aim的整数的个数，当N=0时程序终止。 
	Id:2-3-1
	Author:JiaruiXie
	Date_Begin:05/01/17 18:00
	Date_End:05/01/17 18:17
*/

#include <stdio.h>

int num[101]={0};

int main()
{
	int N;
	int aim,temp;
	scanf("%d",&N);
	while(N!=0)
	{
		for(int i=0;i<N;i++)
		{
			scanf("%d",&temp);
			num[temp%101]++;
		}
		scanf("%d",&aim);
		printf("%d\n",num[aim]);
		scanf("%d",&N);
	}
	return 0;
}



























