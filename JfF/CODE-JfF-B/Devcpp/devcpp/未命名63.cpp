//�Ӽ�������10������, �����Ǳ��浽�ļ���int_file.dat���У�
// Ȼ����ļ��ж�ȡ��10�������������ʾ���ϡ�
//�д��ڽ�һ��������
 
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f;
	char *a=(char *)malloc(sizeof(char)*10);
	if((f=fopen("int_file.dat","wb"))==NULL)
	{
		printf("Open int_file.dat fail!\n");
		exit(0);
	}
	else
	{
		//int *a=(int *)malloc(sizeof(int)*10);
		printf("Input ten num:\n");
		gets(a);
		fputs(a,f);
		fclose(f);
	}
	if((f=fopen("int_file.dat","rb"))==NULL)
	{
		printf("Open int_file.dat fail!\n");
		exit(0);
	}
	else
	{
		fgets(a,100,f);
		puts(a);
		fclose(f);
	} 
	return 0;
}


