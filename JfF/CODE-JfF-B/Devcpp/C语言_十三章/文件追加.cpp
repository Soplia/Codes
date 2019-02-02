/*
Subject:文件追加 
ID:13.5
Complier:Devcpp
Author:JiaruiXie
StartTime:19/01/17 11:36
EndTime:19/01/17 12:08
*/
#include <stdio.h>
#include <stdlib.h>
#define N 20

int main()
{
	char src[N],des[N];
	gets(src);
	gets(des);
	FILE *s,*d;
	
	if((s=fopen(src,"a"))==NULL||(d=fopen(des,"r"))==NULL)
	{
		printf("打开文件失败\n");
		exit(0);
	}
	
	char ch;
	while(!feof(d))
	{
		ch=fgetc(d);
		fputc(ch,s);
	}
	
	printf("追加文件成功！\n");
	fclose(s);
	fclose(d);
	return 0;
}

/*
输入数据
demo.txt
deme.txt
*/


















