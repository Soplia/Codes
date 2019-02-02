//将一个矩阵进行转置(即原来的行变为列)
#include <stdio.h>
int main()
{
	int row=3,col=4;
	int array[row][col];
	int array_r[col][row];
	//初始化 
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			array[i][j]=i*3+j;
	//进行转置		
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			array_r[j][i]=array[i][j];
	//进行数组打印		
	for(int i=0;i<col;i++)
	{
		for(int j=0;j<row;j++)
			printf("%-3d",array_r[i][j]);
		printf("\n");
	}
	return 0;
}
