/*
Subject:Copy_File
ID:13.4
Complier:Devcpp
Author:JiaruiXie
StartTime:19/01/17 12:08
EndTime:
*/
#include <stdio.h>
#define N 20

bool copy(char *src,char *des);

int main()
{
	char src[N],des[N];
	gets(src);
	gets(des);
	if(copy(src,des))
		printf("复制文件成功\n");
	else
		printf("复制文件失败\n");
		
	return 0;
}

bool copy(char *src,char *des)
{
	FILE *s,*d;
	bool flag=true;
	
	if((s=fopen(src,"a"))==NULL)
		goto ERROR;
	if((d=fopen(des,"r"))==NULL)
		goto ERROR;
		
	char ch;	
	while(!feof(d))	
	{
		ch=fgetc(d);
		if(fputc(ch,s)==NULL)
			goto ERROR;
	}
	
	fflush(d);
	goto EXIT;
	
	ERROR:
		flag=false;
	EXIT:
		if(s!=NULL)
			fclose(s);
		if(d!=NULL)	
			fclose(d);
		return flag;
}
/*
输入数据
demo.txt
deme.txt
*/


























