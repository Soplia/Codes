/*
Subject:�������� 
ID:1185
Complier:Devcpp
Author:JiaruiXie
StartTime:15/03/17 09:30
Result:Accepted
EndTime:15/03/17 09:42
*/
#include <stdio.h>
#include <algorithm> 
#define N 2000
using namespace std;

int arr[N];

bool cmp(int a,int b)
{
	return a<b;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		if(n==1)
		{
			printf("%d\n",arr[0]);
			puts("-1");
		}
		else
		{
			sort(arr,arr+n,cmp);
			printf("%d\n",arr[n-1]);
			for(int i=0;i<n-1;i++)
			{
				//������Ȼû��˵����ӡ��ʽ
				//������Ϊ��ʾ�˴�ӡ��ʽ��������Ӧ��Ȼ��Ȼ���뵽���ִ�ӡ��ʽ 
				if(i)
					printf(" ");
				printf("%d",arr[i]);
			}
				
			printf("\n");
		}
	}
	return 0;
}
/*
InputData:
4
1 3 4 2
OutputData:
4
1 2 3
*/

