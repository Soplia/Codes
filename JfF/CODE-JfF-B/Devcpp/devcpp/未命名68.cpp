//�Ӽ�������10��ѧ������Ϣ��ѧ����Ϣ����������ѧ�ź�
//�ɼ���������Ϣ�����ڶ������ļ���student.dat����,  Ȼ���ٴ��ļ���
//��ȡ���Ϊ������ѧ����Ϣ������Щ��Ϣ�������ʾ���ϡ�
#include <stdio.h>
#include <stdlib.h>
//������������� 
int main()
{
	FILE *f;
	int size=20;
	if((f=fopen("student.dat","w+"))==NULL)
	{
		printf("Open the file fail\n");
		exit(0);
	}
	int *a=(int *)malloc(sizeof(int)*size);
	for(int i=0;i<20;i++)
		a[i]=i+1;
		
	fwrite(a,sizeof(int),size,f);
	rewind(f);
	int temp;
	printf("*%d*\n",ftell(f));
	for(int i=1;i<=size/2;i++)
	{
		fread(&temp,sizeof(int),1,f);
		printf("%-3d",temp);
		printf("*%d*\n",ftell(f)); 
		fseek(f,sizeof(int),SEEK_CUR);
	}
	fclose(f);
	return 0;
}
