/*
Subject:int fgetc(FILE *f);
ID:��13.1 
Complier:Devcpp
Author:JiaruiXie
StartTime:19/01/17 10:15
EndTime:19/01/17 12:09
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f;
	if((f=fopen("demo.txt","a"))==NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(0);
	}
	char ch;
	ch=getchar();
	while(ch!='\n')
	{
		fputc(ch,f);
		ch=getchar();
	}
	fclose(f);
	return 0;
}
/*
��������
i love you do you miss me
*/





















