/*
	Subject:goto��� 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:
	Date_Begin:15/01/17 10:11
	Date_End:
*/
#include <stdio.h>
#include <stdlib.h>
const int len=1000;
int main()
{
	char *a=(char *)malloc(sizeof(char)*len);
	if(a==NULL)
	{
		printf("�ڴ����ʧ�ܣ�\n");
		goto Solve;
	}
	else if(a!=NULL)
		printf("�ڴ�a����ɹ�\n");
		
	char *b=(char *)malloc(sizeof(char)*len);
	if(b==NULL)
	{
		printf("�ڴ����ʧ�ܣ�\n");
		goto Solve;
	}
	else if(b!=NULL)
		printf("�ڴ�b����ɹ�\n");
		
	
	goto Solve;
	 
	Solve://ֻҪ�ڴ�δ�ɹ����䣬������ʹ��malloc������ڴ�ռ䶼�ͷŵ��� 
		if(a!=NULL)
		{
			free(a);
			printf("�Ѿ��ͷ�a\n");
		}
		if(b!=NULL)
		{
			free(b);
			printf("�Ѿ��ͷ�b\n");
		}
			
			
	return 0;
}
