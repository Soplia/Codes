/*
Subject:5.4
ID:
Complier:Devcpp
Author:JiaruiXie
StartTime:10/02/17 13:50
Result:
EndTime:
*/
#include<stdio.h>
#define EPS 1e-4
#include <math.h>

int main()
{
	float a,b,c;
	while(scanf("%f%f%f",&a,&b,&c)!=EOF)
	{
		if(fabs(a)<EPS)
			continue;
		else
		{
			float dis=b*b-4*a*c;
			float d=-b/(2*a);
			float e=sqrt(fabs(dis))/(2*a);
			if(fabs(dis)<EPS)
				printf("%.2f,%.2f\n",d,d);
			else if(dis>0)
				printf("%.2f,%.2f\n",d+e,d-e);
			else
				printf("%.2f+%.2fi,%.2f-%.fi\n",d,e,d,e);
		}
	}
	return 0;
} 
/*
InputData:
0 10 2
1 2 1
2 6 1
2 3 2
OutputData:

*/

