#include<stdio.h>
#define N 100

int main()
{
	char a[N]="Hello World",b[N];
	char *t1=a,*t2=b;
	
	while(gets(b))
	{
		//öa¥ê¢íº¶Ýü?¶?æCü\?s?s\?sÊB 
		//a="Hello World"
		//t1¥ê¢?ÊCó"Hello World"A¥¼Iñn¬CÂÈ?s?§B 
	
		while((*t2++=*t1++)!=0);
		puts(b);
	}
	return 0;
} 
