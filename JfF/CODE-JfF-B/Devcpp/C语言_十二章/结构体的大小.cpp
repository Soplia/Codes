#include <stdio.h>

struct n1
{
	char a;
	int b;
	char c;
};

struct n2
{
	char a;
	char b;
	int c;
};

int main()
{
	//系统自身进行内存对齐，方便存储。 
	printf("n1=%d\n",sizeof(struct n1)); 
	printf("n2=%d\n",sizeof(struct n2));
	return 0;
}
