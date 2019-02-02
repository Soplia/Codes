#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	char name[10];
	while(1)
	{
		fgets(name,sizeof(name),stdin);
		printf("*%s*",name);
	}
	
	return 0;
}
