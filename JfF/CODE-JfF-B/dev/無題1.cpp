#include<stdio.h>
int main()
{
	int a=2,b=1;
	printf("a=%d,&a=%d,&b=%d\n",a,&a,&b);	
	printf("a=%d,&a=%o,&b=%o\n",a,&a,&b);
	printf("a=%d,&a=%x,&b=%x\n",a,&a,&b);
	printf("a=%p,&a=%p,&b=%p\n",16,&a,&b);
	return 0;
} 
