/*
Subject:Sort 
ID:1431
Complier:Devcpp
Author:JiaruiXie
StartTime:16/03/17 08:36
Result:Accepted
EndTime:30/03/17 10:21
*/

#include <stdio.h>
#define offset 500000

int hash[offset*2+1];

int main()
{
	int m,n,flag;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		//ע��Ҫ���int���͵��������ȫ����ֵ
		//int arr[N]={0}�ǲ��еģ����ֻ�ܸ�
		//����ĵ�һ��Ԫ�ؽ��и�ֵ�����Ի���
		//��Ҫʹ��ѭ������������д�ͳ�ĸ�ֵ�� 
		for(int i=0;i<offset*2+1;i++) 
			hash[i]=0;
			
		int temp;
		flag=true;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&temp);
			hash[temp+offset]=1;
		}
		for(int i=offset*2;i>=0&&m;i--)
			if(hash[i])
			{
				m--;
				if(!flag)
					printf(" ");
				printf("%d",i-offset);
				flag=0;
			}
		printf("\n");
	}
	return 0;
}

/*
InputData:
5 3
3 -35 92 213 -644
OutputData:
213 92 3
*/

