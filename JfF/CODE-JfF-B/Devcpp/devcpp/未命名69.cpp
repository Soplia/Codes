//ͳ���ı��ļ����ַ��ĸ���
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size=30;
	FILE *f;
	if((f=fopen("count.dat","wb+"))==NULL)
	{
		printf("Open count.txt fail!\n");
		exit(0);
	}
	char *a=(char *)malloc(sizeof(char)*size);
	printf("Input a string:\n");
	gets(a);
	//������д�뵽�ļ��� 
	fputs(a,f);
	//���ʼ�ָ������ָ�����ļ��Ŀ�ͷ 
	rewind(f);
	int count=0;
	char c;
	while(!feof(f))
	{
		c=fgetc(f);
		if(c>='a'&&c<='z'||c>='A'&&c<='Z')
			count++;
		printf("%c",c);
	}
	printf("\nThe number of the char in the file is:%d\n",count);
	return 0;
}
