//将磁盘上一个文本文件的内容复制到另一个文件中。

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f1,*f2;
	if((f1=fopen("string.txt","r"))==NULL)
	{
		printf("Open f1 fail!\n");
		exit(0);
	}
	if((f2=fopen("cstring.txt","w"))==NULL)
	{
		printf("Open f2 fail!\n");
		exit(0);
	}
	char a;
	while((a=fgetc(f1))!=EOF)//这个地方必须要加括号。 
		fputc(a,f2);
	fclose(f2);
	fclose(f1);
	printf("Cope finish!");
	return 0;
}
