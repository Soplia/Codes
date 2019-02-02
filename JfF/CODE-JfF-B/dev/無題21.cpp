#include<stdio.h>
#define N 100

int main()
{
	char a[N]="Hello World",b[N];
	char *t1=a,*t2=b;
	
	while(gets(b))
	{
		//因a是一个常亮存在只?存?区，只能?行?不能?行写。 
		//a="Hello World"
		//t1是一个?量，并且"Hello World"就是他的首地址，可以?行?制。 
	
		while((*t2++=*t1++)!=0);
		puts(b);
	}
	return 0;
} 
