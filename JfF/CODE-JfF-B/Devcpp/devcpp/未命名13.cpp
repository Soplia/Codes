#include <stdio.h>
int main()
{
	int line=9;
	for(int i=1;i<=line;i++)
	{
		for(int j=1;j<=i;j++)
		//总共使用三个空，并且要向左对齐 
			printf("%d＊%d=%-3d",j,i,i*j);  
		printf("\n");
	}
	return 0;
}
