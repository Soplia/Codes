#include<stdio.h>
#define N 100

int main()
{
	char a[N]="Hello World",b[N];
	char *t1=a,*t2=b;
	
	while(gets(b))
	{
		//��a���꘢�헺���ݑ�?��?��C���\?�s?�s�\?�s�ʁB 
		//a="Hello World"
		//t1���꘢?�ʁC��"Hello World"�A�����I��n���C��?�s?���B 
	
		while((*t2++=*t1++)!=0);
		puts(b);
	}
	return 0;
} 
