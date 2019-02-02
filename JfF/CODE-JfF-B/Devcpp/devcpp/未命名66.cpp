//����������� ��list.dat���ļ����ڸ��ļ����ԡ�����, ��������ʽ���
//��ĳ�̳�����Ʒ����(��Ʒ�ĵ��ۺ������ֱ���������һά������)������
//�����������Ʒ���ܽ�����������ڡ�list.dat���ļ������һ�С�

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size=10;
	float price[size]={1,2,3,4,5,6,7,8,9,10};
	int num[size]={1,2,3,4,5,6,7,8,9,10};
	FILE *f;
	float sum=0;
	if((f=fopen("list.dat","w"))==NULL)
	{
		printf("Open list.dat fail!\n");
		exit(0);
	}
	for(int i=0;i<size;i++)
	{
		fprintf(f,"%.2f,%4d\n",price[i],num[i]);
		sum+=price[i]*num[i];
	}
	fwrite(&sum,sizeof(float),1,f);
	fclose(f);
	printf("Save price and num finished!\n");
	
	
	
	if((f=fopen("list.dat","r"))==NULL)
	{
		printf("Open list.dat fail!\n");
		exit(0);
	}
	float a;
	int b;
	for(int i=0;i<size;i++)
	{
		fscanf(f,"%f,%4d\n",&a,&b);
		printf("%.2f,%4d\n",a,b);
	}
	fread(&sum,sizeof(float),1,f);
	printf("%f\n",sum);
	fclose(f);
	printf("Save total price finished!\n");
	
	return 0;
}
