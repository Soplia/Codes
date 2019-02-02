#include <stdio.h>

typedef union stu
{
	int num;
	char *name;
}Stu;

int main()
{
	Stu myStu;
	myStu.num=1;
	printf("%d\n",myStu.num);
	myStu.name="xiejiarui";
	printf("%s\n",myStu.name);
	return 0;
}
