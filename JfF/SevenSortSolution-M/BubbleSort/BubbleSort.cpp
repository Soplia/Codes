#include  "BubbleSort.h" //"" 是搜索用户自定义的头文件


void BubbleSort1(int *mat, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (mat[j] > mat[j + 1])
				Swap(mat[j], mat[j + 1]);
}

void BubbleSort2(int *a, int size)
{
	bool flag = true;

	while (flag)
	{
		flag = false;
		for (int i = 0; i < size - 1; i++)
			if (a[i] > a[i + 1])
			{
				Swap(a[i], a[i + 1]);
				flag = true;
			}
		size--;
	}
}

void BubbleSort3(int *a, int size)
{
	int flag = size;
	while (flag > 0)
	{
		int k = flag;
		flag = 0;
		for (int i = 0; i < k - 1; i++)
			if (a[i] > a[i + 1])
			{
				Swap(a[i], a[i + 1]);
				flag = i + 1;
			}
	}
}