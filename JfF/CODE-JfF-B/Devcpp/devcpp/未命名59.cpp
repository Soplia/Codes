//从键盘输入一行字符，写入到文本文件“string.txt”中。

#include<stdlib.h>
#include<stdio.h>

int main()
{
	char a[100];
	printf("Input a string:\n");
	gets(a);
	FILE *f;
	if((f=fopen("string.txt","w"))==NULL)
	{
		printf("Open the file fail!\n");
		exit(0);
	}
	else
	{
		for(int i=0;;i++)
		{
			if(a[i]!='\0')
				fputc(a[i],f);
			else
				break;
		}
		fclose(f);
	}
	
	return 0;
}
