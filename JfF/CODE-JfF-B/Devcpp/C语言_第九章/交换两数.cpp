/*
Subject:�������� 
ID:9.1
Complier:Devcpp
Author:JiaruiXie
StartTime:23/01/17 10:22
EndTime:23/01/17 10:36
*/

#include <stdio.h>

void swap1(int *a,int *b)
{
	//������Ҫ���б���ֵ�ø�ֵ��
	//��ָ���������û��ָ��
	//Ҳ����û��һ���洢��Ԫ���ܽ�Ҫ���и�ֵ����ֵ�� 
	int *temp;
	*temp=*a;
	*a=*b;
	*b=*temp;
}

void swap2(int *a,int *b)
{
	//�������漰��ֻ��ָ�����֮��ĸ�ֵ
	//ָ������Ĵ�С��8���ֽڣ�������ʲô���͵�ָ������� 
	int *temp;
	temp=a;
	a=b;
	b=temp;
}

int main()
{
	int a=1,b=2;
	swap1(&a,&b);
	printf("%d %d\n",a,b);
	a=1;
	b=2;
	swap2(&a,&b);
	printf("%d %d\n",a,b);
	return 0;
}
