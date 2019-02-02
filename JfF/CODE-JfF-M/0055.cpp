#include <stdio.h>
#include <stdlib.h>

typedef struct a
{
	int i;
	float j;
	double k;
}type_stu,*type_pstu;

///*/**/*/
int main()
{
	//type_pstu 是一体的。没毛病 
	//type_pstu const p = (type_pstu)malloc(sizeof(type_stu));
	type_pstu p = (type_pstu)malloc(sizeof(type_stu));
	p->i = 19;
	p->j = 20.0;
	printf("%d,%.2f\n", p->i, p->j);
	free(p);
	p = NULL;
	return 0;
}
