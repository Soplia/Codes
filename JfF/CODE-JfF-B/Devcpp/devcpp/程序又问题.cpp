//编程找出二维数组中的鞍点，二维数组的
//鞍点是指在该位置上的元素在该行上最大，
//在该列上最小，也可能没有鞍点。
#include <stdio.h>

//这个程序有问题 
int main()
{
	int row=3,col=3;
	int pos_x,pos_y[col];
	int array[row][col]={{1,3,3},{1,4,5},{1,5,6}};
	
//	for(int i=0;i<row;i++)
//		for(int j=0;j<col;j++)
//			printf("%-3d",array[i][j]);
	
	//进行数组初始化 
//	for(int i=0;i<row;i++)
//		for(int j=0;j<col;j++)
//			array[i][j]=i*col+j;
			
			
			
	//定义指向二维数组的指针 
	int (*p)[col];
	p=array;
	//求解鞍点 
	for(int i=0;i<row;i++)
	{
		int max=p[i][0];
		int pos=0;
		//记录改行中最大元素的位置，最大元素有可能是相同的 
		for(int i1=0;i1<col;i1++)
			pos_y[i1]=-1;
		for(int j=1;j<col;j++)
			if(array[i][j]>max)//首先找到该行中最大的元素 
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
