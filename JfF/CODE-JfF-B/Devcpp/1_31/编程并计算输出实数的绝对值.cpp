/*
Subjec:��̲��������ʵ���ľ���ֵ 
ID:5.1
Complier:Devcpp
Author:JiaruiXie
StartTime:28/01/17 16:14
EndTime:28/01/17 16:18
*/
#include <stdio.h>

int main()
{
	float a;
	int ret=scanf("%f",&a);
	if(ret!=1)
	{
		printf("�������ݴ���\n");
		fflush(stdin);
	}
	else
		printf("%.2f\n",a>0?a:-a);
	return 0;	
} 
