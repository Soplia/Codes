/*
	Subject:�����ļ��������ļ�������ʾ����Ļ�� 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:
	Date_Begin:19/01/17 12:09
	Date_End:19/01/17 12:09
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
	char name[20];
	gets(name);
	
	FILE *f;
	if((f=fopen(name,"rb+"))==NULL) 
	{
		printf("���ļ�ʧ��!\n");
		exit(0);
	}
	
	char ch;
	//��һ�ֶ�д���� 
//	while((ch=fgetc(f))!=EOF)
//		printf("%c",ch);

	//�ڶ��ֶ�д���� 
//	while(!feof(f))
//	{
//		printf("%c",fgetc(f));
//	}
	char n[100];
	//�����ֶ�д���� 
//	while(!feof(f))
//	{
//		printf("%s",fgets(n,100,f));
//	}
	
	printf("\n");
	fclose(f);
	return 0;
}
/*
��������
deme.txt
*/




























