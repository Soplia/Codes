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
			
			printf("ֱ��������\n");
		else if((a*a+b*b<c*c)||(a*a+c*c<b*b)||(b*b+c*c<a*a))
			printf("���������\n");
		else
			printf("�۽�������\n");
	}
	return 0;
}
/*
InputData:
3 4 5
OutputData:
ֱ��������
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
//			printf("����");
//			flag=0;
//		}
//			
//		else if(fabs(a-b)<=EPS||fabs(a-c)<=EPS||fabs(b-c)<=EPS)
//		{
//			printf("����");
//			flag=0;
//		} 
//			
//			
//		if(fabs(a*a+b*b-c*c)<=EPS||fabs(a*a+c*c-b*b)<=EPS||fabs(b*b+c*c-a*a)<=EPS)
//			printf("���p");
//		if(flag)
//			printf("���");
//		printf("�O�p�`\n");
//	}
//	
//	else
//		printf("�s���O�p�`\n");
//		
//	return 0;
//}
