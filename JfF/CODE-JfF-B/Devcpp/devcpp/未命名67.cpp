#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size=20;
	FILE *f;
	if((f=fopen("new.txt","r+"))==NULL)
	{
		printf("Open new.text fail!\n");
		exit(0);
	}
	char *a=(char *)malloc(sizeof(char)*size);
	char *b=(char *)malloc(sizeof(char)*size);
	printf("Input a string :\n");
	gets(a);
	fputs(a,f);
	rewind(f);
	fgets(b,size,f);
	fclose(f);
	puts(b);
	return 0;
}
