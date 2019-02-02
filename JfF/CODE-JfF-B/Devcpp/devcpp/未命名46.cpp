#include <stdio.h>

int main()
{
	int  a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	//定义指向二维数组的指针 
	int (*p)[4];
	int *q=*a; 
	p=a;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
			printf("%-3d",*(q+i)+j);
		printf("\n");
	}
	return 0;
}
