#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 1000001

int list[N];
int dp[N];

int upper_bound(int arr[], int s, int e, int key)
{
    int mid;
    if (arr[e] <= key)
        return e + 1;
    while (s < e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] <= key)
            s = mid + 1;
        else
            e = mid;
    }
    return s;
}

int LIS(int d[], int n)
{
    int i = 0, len = 1;
	int *end = (int *)malloc(sizeof(int) * (n + 1));
	//int end[n+1];
    end[1] = d[0]; //初始化：长度为1的LIS末尾为d[0]
    for (i = 1; i < n; i++)
    {
        int pos = upper_bound(end, 1, len, d[i]); //找到插入位置
        end[pos] = d[i];
        if (len < pos) //按需要更新LIS长度
            len = pos;
    }
    free(end);
    end = NULL;
    return len;
}


int main()
{
	int t, n;
	while (scanf("%d%d", &n, &t) != EOF)
	{
		int size = n * t;
		for (int i = 0; i < n; i++)
			scanf("%d", &list[i]);
		for (int i = 1; i < t; i++)
			for (int j = 0; j < n; j++)
				list[i * n + j] = list[j];
				
		printf("%d", LIS(list, size));
	}

	return 0;
}
