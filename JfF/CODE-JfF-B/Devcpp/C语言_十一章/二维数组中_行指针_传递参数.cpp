/*
	Subject:��ά������_��ָ��_���ݲ��� 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:
	Date_Begin:
	Date_End:
*/
#include <stdio.h>

void f1(int a[][3])
{
	printf("��ͳ_���ݶ�ά������_�ɹ�\n");
}

void f2(int a[][3])
{
	printf("��ͳ_����a[0][0]�ĵ�ַ_�ɹ�\n");
}

void f3(int (*p)[3])
{
	printf("��ָ��_���ݶ�ά������_�ɹ�\n");
}

void f4(int (*p)[3])
{
	printf("��ָ��_����a[0][0]�ĵ�ַ_�ɹ�\n");
}

int main()
{
	int a[2][3];
	f1(a);
	//f2(*a);
	f3(a);
	//f4(*a);
	return 0;
} 
