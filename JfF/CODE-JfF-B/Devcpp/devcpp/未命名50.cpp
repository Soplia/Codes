#include <stdio.h>

struct student
{
	int num;
	char name[10];
};

int main()
{
	printf("%d",sizeof(struct student));
	return 0;
}
