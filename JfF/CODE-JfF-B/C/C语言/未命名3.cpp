#include <stdio.h>
#include <string.h>

#define STR(A)  #A

int main()
{
	int a;
	scanf("%d",&a); 
	int len=0;
	printf("the length of the str=%d\n",strlen(STR(a)));
	putchar(STR(a)[0]);
	return 0;
}
