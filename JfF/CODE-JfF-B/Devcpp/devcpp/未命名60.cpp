//��������һ���ı��ļ������ݸ��Ƶ���һ���ļ��С�

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f1,*f2;
	if((f1=fopen("string.txt","r"))==NULL)
	{
		printf("Open f1 fail!\n");
		exit(0);
	}
	if((f2=fopen("cstring.txt","w"))==NULL)
	{
		printf("Open f2 fail!\n");
		exit(0);
	}
	char a;
	while((a=fgetc(f1))!=EOF)//����ط�����Ҫ�����š� 
		fputc(a,f2);
	fclose(f2);
	fclose(f1);
	printf("Cope finish!");
	return 0;
}
