//已知一个文本文件“file8_1.c”存储在“E:\test”目录中，
//将该文件的信息输出到显示器上

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f;
	if((f=fopen("1.txt","r"))==NULL)
	{
		printf("Open the file fail!\n");
		exit(0);
	}
	char a;
	a=fgetc(f);
	while(a!=EOF)
	{
		printf("%c",a);
		a=fgetc(f);
	}
	fclose(f);
	return 0;
}
