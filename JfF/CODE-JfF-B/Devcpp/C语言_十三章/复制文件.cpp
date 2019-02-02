/*
Subject:复制文件 
ID:13.4
Complier:Devcpp
Author:JiaruiXie
StartTime:19/01/17 11:28
EndTime:19/01/17 12:09
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
	if((s=fopen(src,"r"))==NULL||(d=fopen(des,"w"))==NULL)
	{
		printf("打开文件失败\n");
		exit(0);
	}
	
	char ch;
	while(!feof(s))
	{
		ch=fgetc(s);
		fputc(ch,d);
	}
	printf("复制文件完成");
	fclose(s);
	fclose(d);
	return 0;
}
/*
输入数据
demo.txt
deme.txt 
*/



















