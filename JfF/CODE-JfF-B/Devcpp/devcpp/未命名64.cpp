//�Ӽ�������10������, �����Ǳ��浽�ļ���int_file.dat���У�
// Ȼ����ļ��ж�ȡ��10�������������ʾ����

//ʹ��fwrite���ļ��д�ŵ�ʱ���ǰ��ա��顱���д�ŵģ����������int�ͻᰴ��4���ֽ�һ�ν��д��
//����fgetcÿ��ֻȡһ���ֽڣ��������ʹ������������д�ȡ����ô���ض���������룬����������ַ��أ�/hx 
//ͨ��ʵ�鷢�֣��������в�ͨ�ģ���Ϊ�������ļ�ָ���ʱ���Ѿ��涨���Ƕ����ƵĶ�д��ʽ�����Ҿ�������ָ��
//��д��ʽ���Ƿ����д�����ַ��͵Ķ�д��ʽ������ֻҪ��ʹ��fread��fwrite ���������ͻ��Զ�ʹ�ö����ƶ�д��ʽ��
//�������ֶ�д��ʽ���ܹ����л��á� 

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f;
	if((f=fopen("int_file.dat","w"))==NULL)
	{
		printf("Open the file fail!\n");
		exit(0);
	}
	int size=10;
	char *a=(char *)malloc(sizeof(char)*10);
	for(int i=0;i<10;i++)
		scanf("%c",(a+i));
	fwrite(a,sizeof(char),size,f);
	fclose(f);
	printf("Save Successfully!\n");
//	if((f=fopen("int_file.dat","rb"))==NULL)
//	{
//		printf("Open the file fail\n");
//		exit(0);
//	}
//	int *b=(int *)malloc(sizeof(int )*10);
//	fread(b,sizeof(int),size,f);
//	fclose(f);
//	for(int i=0;i<size;i++)
//			printf("%-3d",*(b+i));
	if((f=fopen("int_file.dat","r"))==NULL)
	{
		printf("Open the file fail!\n");
		exit(0);
	}
	char aa;
	while((aa=fgetc(f))!=EOF)
		printf("%c",aa);
	
	return 0;
}
                
