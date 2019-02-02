//找出矩阵中最大的数,并输出其行号和列号
#include <stdio.h>
int main()
{
	int col,row,max=-999;
	int array[3][3];
	for(int i=0;i<9;i++)
		array[i/3][i%3]=9-i;
	for(int i=0;i<9;i++)
		if(array[i/3][i%3]>max)
		{
			max=array[i/3][i%3];
			row=i/3+1;
			col=i%3+1;
		}
	printf("row=%d,col=%d",row,col);
	return 0;
}

