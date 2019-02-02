#include<stdio.h>
#include <math.h>
#define EPS 1e-1

int main()
{
	float a,b,c;
	while(scanf("%f%f%f",&a,&b,&c)!=EOF)
	{
		int flag=1;
		if(a+b>=c&&a+c>=b&&b+c>=a)
		{
			if(fabs(a-b)<=EPS&&fabs(a-c)<=EPS&&fabs(b-c)<=EPS)
			{
				printf("“™—Í");
				flag=0;
			}
			else if(fabs(a-b)<=EPS||fabs(a-c)<=EPS||fabs(b-c)<=EPS)
			{
				printf("“™˜");
				flag=0;
			}
			if(fabs(a*a+b*b-c*c)<=EPS||fabs(a*a+c*c-b*b)<=EPS||fabs(b*b+c*c-a*a)<=EPS)
			{
				printf("’¼Šp");
				flag=0;
			}
			if(flag)
				printf("ˆê”Ê");
			printf("ŽOŠpŒ`\n");
		}
		else
			printf("•s¥ŽOŠpŒ`\n");
	}
	return 0;	
} 

/*
Subject:
ID:
Complier:Devcpp
Author:JiaruiXie
StartTime:
Result:
EndTime:
*/

/*
InputData:
3 4 5
4 4 5
3 4 6
3 4 9
10 10 14.14
4 4 4
OutputData:

*/

