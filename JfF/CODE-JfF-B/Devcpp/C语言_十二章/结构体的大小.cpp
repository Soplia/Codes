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
	//ϵͳ��������ڴ���룬����洢�� 
	printf("n1=%d\n",sizeof(struct n1)); 
	printf("n2=%d\n",sizeof(struct n2));
	return 0;
}
