#include <stdio.h>
#include <stdlib.h>

#define N 100001
int Tree[N];

int findRoot(int x)
{
	if (Tree[x] == -1)
		return x;
	else
	{
		int tmp = findRoot(Tree[x]);
		Tree[x] = tmp;
		return tmp;
	}
}

int sum[N];

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int temp = n;
		int number = 1;
		
		for (int i = 1; i < N; i++)
		{
			Tree[i] = -1;
			sum[i] = 1;
		}
		
		while (n-- != 0)
		{
			int a;
			int b;
			while (scanf("%d", &a) != EOF)
			{
				char ch = getchar();
				if(ch == '\n')
					break;
				a = findRoot(a);
				b = findRoot(number);
				if (a != b)
					Tree[a] = number;
			}
			number ++;
		}

		int ans = 0;
		for (int i = 1; i <= temp; i++)
		{
			//printf("Root=%d,",Tree[i]);
			if (Tree[i] == -1)
				ans++;
		}
			
		printf("%d", ans);

	}
	return 0;
}
