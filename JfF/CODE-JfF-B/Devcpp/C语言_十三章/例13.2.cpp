/*
Subject:��0-127 ���ַ���ASCIIд���ļ��У����ҽ�������ʾ����Ļ�ϡ� 
ID:��13.2 
Complier:Devcpp
Author:JiaruiXie
StartTime:19/01/17 10:25
EndTime:19/01/17 12:08
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
	FILE *f;
	if((f=fopen("deme.txt","wb+"))==NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(0);
	}
	for(int i=0;i<=127;i++)
	{
		fputc(i,f);
	}
	
	
	rewind(f);
	int i=0;
	char ch;
	while((ch=fgetc(f))!=EOF)
	{
		if(isprint(ch))
			printf("%c%c",ch,i&1==0?'\n':'\t');
		else	
			printf("%c%c",'.',i&1==0?'\n':'\t');
		
	}
	fclose(f);
	return 0;
}




















