/*
	Subject:二维数组中_行指针_传递参数 
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
	printf("传统_传递二维数组名_成功\n");
}

void f2(int a[][3])
{
	printf("传统_传递a[0][0]的地址_成功\n");
}

void f3(int (*p)[3])
{
	printf("行指针_传递二维数组名_成功\n");
}

void f4(int (*p)[3])
{
	printf("行指针_传递a[0][0]的地址_成功\n");
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
