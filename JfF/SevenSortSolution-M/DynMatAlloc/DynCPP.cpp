#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

template <typename T>
T** AllMat2Dpp(int row, int col)
{
	int size = sizeof(T);
	int pointSize = sizeof(T*);

	T** arr = (T**)malloc(pointSize * row + row * col * size);
	if (NULL != arr)
	{
		//memset(arr, 0, pointSize * row + row * col * size);
		T* head = (T*)((int)arr + pointSize * row);

		for (int i = 0; i< row; i++)
		{
			arr[i] = (T*)((int)head + size * i * col);
			for (int j = 0; j < col; j++)
				new (&arr[i][j]) T;
		}
	 }
	return (T**)arr;
}
template <typename T>
void DelMempp(T **p, int row, int col)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			p[i][j].~T();

	if (NULL != p)
		free(p);
}

int main()
{
	const int row = 3;
	const int col = 4;
	//这样改了之后的确是不行
	string **mat = AllMat2Dpp<string>(row, col);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			//char temp[30];
			//sprintf_s(temp,"第%d行，第%d列", i, j);
			//mat[i][j] = temp;
			mat[i][j] = "Hello World";
		}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			printf("%s ", mat[i][j].c_str());
		printf("\n");
	}

	DelMempp<string>(mat, row, col);
	system("pause");
	return 0;
}