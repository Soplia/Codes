#include <stdio.h>
#include <stdlib.h>
/*
int main()
{
	const int MAX_COL = 3;
	const int MAX_ROW = 4;
	int *p = (int *)malloc(sizeof(int) * (MAX_COL * MAX_ROW));
	int (*aim)[MAX_COL] = (int (*)[MAX_COL])p;
	for (int i = 0; i < MAX_ROW; i++)
		for (int j = 0; j < MAX_COL; j++)
			aim[i][j] = MAX_COL * i + j + 1;
	for (int i = 0; i < MAX_ROW; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
			printf("%-4d", aim[i][j]);
		printf("\n");
	}
	free(p);
	system("pause");
	return 0;
}*/