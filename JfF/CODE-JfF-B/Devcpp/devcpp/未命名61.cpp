//��̽�һ���ı��ļ���ȫ����Ϣ��ʾ����Ļ��
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size=10;
	FILE *f;
	if((f=fopen("string.txt","r"))==NULL)
	{
		printf("Open string.txt fail!\n");
		exit(0);
	}
	char *a=(char *)malloc(sizeof(char)*size);
	fgets(a,9,f);
	fclose(f);
	puts(a);
	return 0;
} 
