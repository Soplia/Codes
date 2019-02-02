#include "Tool.h"

void Swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

void CreateMatrix(int *a, int size, int range)
{
	time_t t1;
	time(&t1);
	srand(t1);

	for (int i = 0; i < size; i++)
		a[i] = rand() % range;
}

void DisMatrix(int *a, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i != 0 && 0 == i % 10)
			printf("\n");
		printf("%6d", a[i]);
	}
	printf("\n");
}

bool SaveFile(int *a, int size)
{
	FILE *fpWrite = fopen("data.txt", "w");
	if (fpWrite == NULL)
	{
		printf("Open the file Failed!\n");
		return 0;
	}

	for (int i = 0; i < size; i++)
		fprintf(fpWrite, "%d,", i);
	fclose(fpWrite);
}

int ReadFile(int *a)
{
	int sizeOfNum = 0;

	FILE *fpRead = fopen("data-10000.txt", "r");
	if (fpRead == NULL)
	{
		printf("Open the file Failed!\n");
		return 0;
	}
	while (!feof(fpRead))
	{
		fscanf(fpRead, "%d,", &a[sizeOfNum++]);
	}

	return sizeOfNum;
}

void CreateTestDataFile()
{
	int base = 10000;
	int *a;

	for (int i = 1; i < 2; i *= 10)
	{
		a = (int*)malloc(sizeof(int)*base*i);
		CreateMatrix(a, base*i, base);
		SaveFile(a, base*i);
		free(a);
	}
}

void CreateTestDataFile(int size)
{
	int base = 10000;
	int *a;

	a = (int*)malloc(sizeof(int)*base*size);
	CreateMatrix(a, base*size, base);
	SaveFile(a, base*size);
	free(a);
}

