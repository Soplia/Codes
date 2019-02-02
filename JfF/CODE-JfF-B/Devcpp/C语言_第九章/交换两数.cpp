/*
Subject:交换两数 
ID:9.1
Complier:Devcpp
Author:JiaruiXie
StartTime:23/01/17 10:22
EndTime:23/01/17 10:36
*/

#include <stdio.h>

void swap1(int *a,int *b)
{
	//函数中要进行变量值得赋值，
	//但指针变量本身没有指向
	//也就是没有一个存储单元接受将要进行赋值的数值。 
	int *temp;
	*temp=*a;
	*a=*b;
	*b=*temp;
}

void swap2(int *a,int *b)
{
	//函数中涉及的只是指针变量之间的赋值
	//指针变量的大小是8个字节，不管是什么类型的指针变量。 
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
