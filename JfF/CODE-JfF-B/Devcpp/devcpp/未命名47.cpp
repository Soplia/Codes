//将数组a[M][N]中的每个元素向右移一列, 最后一列换到最左一列
//要求：必须用指针实现

#include <stdio.h>
 
int main()
{
	int row=6,col=8;
	int a[row][col];
	//存放二维数组中最右边的一列元素 
	int b[row];
	//给二维数组赋初始值 
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
	//指向二维数组的指针 
	int (*p)[col];
	p=a;
	//将最后一列元素进行复制 
	for(int i=0;i<row;i++)
		b[i]=p[i][col-1];
	//将前col-1列进行复制移动 
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

