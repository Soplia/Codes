//��fputs�������ı��ļ���string.txt��ĩβ����������ַ�

#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *f;
	char *str=(char *)malloc(sizeof(char)*20);
	str="�Һ�����...";
	if((f=fopen("string.txt","a"))==NULL)
	{
		printf("Opent string.txt fail!\n");
		exit(0);
	}
	else
	{
		fputs(str,f);
		fclose(f);	
	} 
	printf("׷�����!\n");
	return 0;
}
