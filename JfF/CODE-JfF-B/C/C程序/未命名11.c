#include <stdio.h>

char* GetStr(void)
{
	char p[]="Hello World";
	return p;
}

int main()
{
	//puts(GetStr());
	char *str=NULL;
	str=GetStr();
	puts(str);
	return 0;
}
