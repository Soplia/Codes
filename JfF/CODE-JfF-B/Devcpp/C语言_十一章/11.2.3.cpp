#include <stdio.h>

#define STUD 30
#define COURSE 5

void Total(int *score,int sum[],int m,int n);
void Print(int *score,int sum[],int m,int n);

int main()
{
	int i,j,m,n,score[STUD][COURSE],sum[STUD];
	float aver[STUD];
	
	//printf("How many stuents?\n");
	scanf("%d",&m);
	//printf("How many courst?\n");
	scanf("%d",&n);
	
	//printf("Input scores:\n");
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&score[i][j]);
	//传送二维数组首行首列的地址。		
	Total(*score,sum,m,n);
	Print(*score,sum,m,n);
	
	return 0;
}

void Total(int *score ,int sum[],int m,int n)
{
	for(int i=0;i<m;i++)
	{
		int temp=0;
		for(int j=0;j<n;j++)
			temp+=score[i*COURSE+j];
		sum[i]=temp;
	}
}

void Print(int *score ,int sum[],int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",score[i*COURSE+j]);
		printf("%d\n",sum[i]);
	}
}

/*
测试数据
样例输入
4 
3
60 60 60 
70 70 70
80 80 80
90 90 90
样例输出
60 60 60 180
70 70 70 210
80 80 80 240
90 90 90 270
*/























