//��֪һ���ı��ļ���file8_1.c���洢�ڡ�E:\test��Ŀ¼�У�
//�����ļ�����Ϣ�������ʾ����

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f;
	if((f=fopen("1.txt","r"))==NULL)
	{
		printf("Open the file fail!\n");
		exit(0);
	}
	char a;
	a=fgetc(f);
	while(a!=EOF)
	{
		printf("%c",a);
		a=fgetc(f);
	}
	fclose(f);
	return 0;
}
