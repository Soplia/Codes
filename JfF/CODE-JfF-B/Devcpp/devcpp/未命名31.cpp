//��һ���������ת��(��ԭ�����б�Ϊ��)
#include <stdio.h>
int main()
{
	int row=3,col=4;
	int array[row][col];
	int array_r[col][row];
	//��ʼ�� 
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			array[i][j]=i*3+j;
	//����ת��		
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			array_r[j][i]=array[i][j];
	//���������ӡ		
	for(int i=0;i<col;i++)
	{
		for(int j=0;j<row;j++)
			printf("%-3d",array_r[i][j]);
		printf("\n");
	}
	return 0;
}
