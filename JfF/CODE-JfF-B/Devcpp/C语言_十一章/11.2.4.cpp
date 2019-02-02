/*
	Subject:
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:
	Date_Begin:
	Date_End:
*/
#include <stdio.h>

typedef struct n
{
	int a;
	int b;
	float c;
}N;

int main()
{
	int *a[4];
	float *b[4];
	char *c[4];
	long *d[4];
	long long *e[4];
	printf("sizeof(int)=%d,sizeof(int*)=%d,sizeof(d)=%d\n",sizeof(int),sizeof(int *),sizeof(d));
	printf("sizeof(char)=%d,sizeof(char*)=%d\n",sizeof(char),sizeof(char *));
	printf("sizeof(float)=%d,sizeof(float*)=%d\n",sizeof(float),sizeof(float *));
	printf("sizeof(long=%d,sizeof(long*)=%d\n",sizeof(long),sizeof(long *));
	printf("sizeof(long long)=%d,sizeof(long long*)=%d\n",sizeof(long long),sizeof(long long *));
	printf("sizeof(N)=%d,sizeof(N*)=%d\n",sizeof(N),sizeof(N *));
	
	return 0;
}
