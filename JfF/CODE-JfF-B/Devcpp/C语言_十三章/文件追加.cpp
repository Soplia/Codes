/*
Subject:�ļ�׷�� 
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
		printf("���ļ�ʧ��\n");
		exit(0);
	}
	
	char ch;
	while(!feof(d))
	{
		ch=fgetc(d);
		fputc(ch,s);
	}
	
	printf("׷���ļ��ɹ���\n");
	fclose(s);
	fclose(d);
	return 0;
}

/*
��������
demo.txt
deme.txt
*/


















