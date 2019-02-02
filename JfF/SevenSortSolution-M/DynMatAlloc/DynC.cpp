#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

template <typename T>
T** AllMat2D(int row, int col)
{
	int size = sizeof(T);
	int pointSize = sizeof(T*);
	
	T** arr = (T**)malloc(pointSize * row + size * row * col);

	if (NULL != arr)
	{
		memset(arr, 0, pointSize * row + size * row * col);
		T *head = (T*)(pointSize * row + (int)arr);

		while (row--)
			arr[row] = (T*)((int)head + size * row * col);
	}
	return (T**)arr;
}

void DelMem(void **p)
{
	if (NULL != p)
		free(p);
}

