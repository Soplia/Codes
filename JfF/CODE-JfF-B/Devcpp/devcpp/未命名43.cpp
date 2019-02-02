//将数组a中全部元素加1, 再输出a
#include <stdio.h>

//总而言之，言而总之，使用指向函数的指针的时候需要含有函数的返回值类型。 
void add(int *,int );

int main()
{
	void (*p)(int *,int);
	p=add;
	
	int a[10];
	for(int i=0;i<10;i++)
		a[i]=i+1;
	(*p)(a,10);
	
	for(int i=0;i<10;i++)
		printf("%-3d",a[i]);
	return 0;
}

void add(int *a,int b)
{
	for(int *p=a;p<a+b;p++)
		(*p)++;
}
