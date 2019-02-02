#include <stdio.h>
#define N 11

int arr[N];

int myP(int a,int b)
{
	int ans=1;
	for(int i=1;i<=b;i++)
		ans*=a;
	return ans;
}

void pre()
{
	for(int i=1;i<N;i++)
		arr[i]=myP(2,i)-1;
}

int min(int a,int b)
{
	return a<b?a:b;
}

int main()
{
	int n;
	pre();
	while(scanf("%d",&n)!=EOF)
	{
		int temp;
		for(int i=0;i<n;i++)
			scanf("%d",&temp);
		int d;
		scanf("%d",&d);
		int s=arr[d-1]+1;
		if(s>n)
			puts("EMPTY");
		else
		{
			int e=min(n,arr[d]);
			for(int i=s;i<=e;i++)
			{
				if(i!=s)
					printf(" ");
				printf("%d",i);
			}
			printf("\n");
		}
	}
	return 0;
}

