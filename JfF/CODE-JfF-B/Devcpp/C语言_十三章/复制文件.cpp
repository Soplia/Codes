/*
Subject:�����ļ� 
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
		printf("���ļ�ʧ��\n");
		exit(0);
	}
	
	char ch;
	while(!feof(s))
	{
		ch=fgetc(s);
		fputc(ch,d);
	}
	printf("�����ļ����");
	fclose(s);
	fclose(d);
	return 0;
}
/*
��������
demo.txt
deme.txt 
*/



















