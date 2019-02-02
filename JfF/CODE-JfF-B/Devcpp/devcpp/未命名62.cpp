//用fputs函数在文本文件“string.txt”末尾添加若干行字符

#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *f;
	char *str=(char *)malloc(sizeof(char)*20);
	str="我好想你...";
	if((f=fopen("string.txt","a"))==NULL)
	{
		printf("Opent string.txt fail!\n");
		exit(0);
	}
	else
	{
		fputs(str,f);
		fclose(f);	
	} 
	printf("追加完毕!\n");
	return 0;
}
