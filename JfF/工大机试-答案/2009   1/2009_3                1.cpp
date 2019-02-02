/*
Subject:2009_3
ID:2009_3
Complier:Devcpp
Author:JiaruiXie
StartTime:06/02/17 22:34
Result:Wrong Answer
EndTime:
*/
#include <stdio.h>
#define EPS 1e-4

float fabs(float x)
{
	return x>0?x:-x;
}

int main()
{
	float a,b,c;
	while(scanf("%f%f%f",&a,&b,&c)!=EOF)
	{
		if(fabs(a*a+b*b-c*c)<=EPS||fabs(a*a+c*c-b*b)<=EPS||fabs(b*b+c*c-a*a)<=EPS)
			
			printf("直角三角形\n");
		else if((a*a+b*b<c*c)||(a*a+c*c<b*b)||(b*b+c*c<a*a))
			printf("锐角三角形\n");
		else
			printf("钝角三角形\n");
	}
	return 0;
}
/*
InputData:
3 4 5
OutputData:
直角三角形
*/

//
//#include <stdio.h>
//#define EPS 1e-4
//
//float fabs(float x)
//{
//	return x>0?x:-x;
//}
//
//int main()
//{
//	float a,b,c;
//	scanf("%f%f%f",&a,&b,&c);
//	int flag=1;
//	if(a+b>c&&a+c>b&&b+c>a)
//	{
//		if(fabs(a-b)<=EPS&&fabs(a-c)<=EPS)
//		{
//			printf("摍椡");
//			flag=0;
//		}
//			
//		else if(fabs(a-b)<=EPS||fabs(a-c)<=EPS||fabs(b-c)<=EPS)
//		{
//			printf("摍崢");
//			flag=0;
//		} 
//			
//			
//		if(fabs(a*a+b*b-c*c)<=EPS||fabs(a*a+c*c-b*b)<=EPS||fabs(b*b+c*c-a*a)<=EPS)
//			printf("捈妏");
//		if(flag)
//			printf("堦斒");
//		printf("嶰妏宍\n");
//	}
//	
//	else
//		printf("晄惀嶰妏宍\n");
//		
//	return 0;
//}
