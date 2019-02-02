#include <stdio.h>
int main()
{
	//因为"Hello"本身就代表了其本身的存储地址。
	//"Hello"是一个常量。 
	char *p="Hello";
	p[2]='w';
	
	return 0;
}
