//������a[M][N]�е�ÿ��Ԫ��������һ��, ���һ�л�������һ��
//Ҫ�󣺱�����ָ��ʵ��

#include <stdio.h>
 
int main()
{
	int row=6,col=8;
	int a[row][col];
	//��Ŷ�ά���������ұߵ�һ��Ԫ�� 
	int b[row];
	//����ά���鸳��ʼֵ 
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			a[i][j]=i*col+j;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			printf("%-3d",a[i][j]);
		printf("\n");
	}
	printf("\n");
	//ָ���ά�����ָ�� 
	int (*p)[col];
	p=a;
	//�����һ��Ԫ�ؽ��и��� 
	for(int i=0;i<row;i++)
		b[i]=p[i][col-1];
	//��ǰcol-1�н��и����ƶ� 
	for(int j=0;j<row;j++)
		for(int i=col-2;i>=0;i--)
			p[j][i+1]=p[j][i];
	for(int i=0;i<row;i++)
		p[i][0]=b[i];
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			printf("%-3d",p[i][j]);
		printf("\n");
	}
	return 0;
}

