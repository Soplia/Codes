#include <stdio.h>
#include <math.h>

#define N 1000001

int list[N];
int dp[N];

int MyMax(int a, int b)
{
	return a > b ? a : b;
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
				
		for (int i = 0; i < size; i++)
		{
			int max = 1;
			for (int j = 0; j < i; j++)
				if (list[j] <= list[i])
					max = MyMax(max, dp[j] + 1);
			dp[i] = max;
		}

		int ans = 1;
		for (int i = 0; i < size; i++)
			ans = MyMax(ans, dp[i]);

		printf("%d", ans);
	}

	return 0;
}
