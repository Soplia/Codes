#include <stdio.h>

int main()
{
	FILE *f;
	f=fopen("1.txt","w");
	if(f==NULL)
		printf("Open the file fail!\n");
	else
	{
		char a='A';
		for(;a<'Z';a=a+2)
			fputc(a,f);
		fclose(f);
	}
	
	return 0;
}
