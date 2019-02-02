#include "ShellSort.h"
#include "Tool.h"

void ShellSort1(int * a, int size)
{
	for (int gap = size / 2; gap > 0; gap /= 2)
		for (int i = gap; i < size; i++)
			for (int j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap)
				Swap(a[j], a[j + gap]);
}