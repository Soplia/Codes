//����ҳ���ά�����еİ��㣬��ά�����
//������ָ�ڸ�λ���ϵ�Ԫ���ڸ��������
//�ڸ�������С��Ҳ����û�а��㡣
#include <stdio.h>

//������������� 
int main()
{
	int row=3,col=3;
	int pos_x,pos_y[col];
	int array[row][col]={{1,3,3},{1,4,5},{1,5,6}};
	
//	for(int i=0;i<row;i++)
//		for(int j=0;j<col;j++)
//			printf("%-3d",array[i][j]);
	
	//���������ʼ�� 
//	for(int i=0;i<row;i++)
//		for(int j=0;j<col;j++)
//			array[i][j]=i*col+j;
			
			
			
	//����ָ���ά�����ָ�� 
	int (*p)[col];
	p=array;
	//��ⰰ�� 
	for(int i=0;i<row;i++)
	{
		int max=p[i][0];
		int pos=0;
		//��¼���������Ԫ�ص�λ�ã����Ԫ���п�������ͬ�� 
		for(int i1=0;i1<col;i1++)
			pos_y[i1]=-1;
		for(int j=1;j<col;j++)
			if(array[i][j]>max)//�����ҵ�����������Ԫ�� 
			{
				max=array[i][j];
				pos_y[pos]=j;
			}
		for(int h=1;h<col;h++)
			if(array[i][h]==max)
				pos_y[++pos]=h;
		for(int g=0;g<=pos;g++)
		{
			int k=0;
			for(;k<row;k++)
				if(array[k][pos_y[g]]<array[i][pos_y[g]])
					pos_x=k;
			if(k==i)
			printf("pos_x=%d,pos_y=%d\n",pos_x,pos_y[g]);
		}
	}	
}
