/*
	Subject:DisjointSet_MonerBetter
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:5-2-4 
	Date_Begin:16/01/17 17:42
	Date_End:18/01/17 14:36
*/

#include <stdio.h> 
#define N 1000001

int table[N];
int sum[N];

void init()
{
	for(int i=1;i<=N;i++)
	{
		table[i]=-1;
		sum[i]=1;
	}
}

int findRoot(int x)
{
	if(table[x]==-1)
		return x;
	else
	{
		int temp=findRoot(table[x]);
		table[x]=temp;
		return temp;
	}
}

int getMax(int x)
{
	int max=1;
	for(int i=1;i<=x;i++) 
		if(max<sum[i])
			max=sum[i];
	return max;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		init();
		int a,b,size=-1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			if(size<a)
				size=a;
			if(size<b)
				size=b;
				
			a=findRoot(a);
			b=findRoot(b);
			
			if(a!=b)
			{
				table[b]=a;
				sum[a]+=sum[b];
			}
			
//			printf("\n添加第%d组伙伴\n下标",i);	
//			for(int i=1;i<=size;i++)
//				printf("%3d",i);
//			printf("\n节点");
//			for(int i=1;i<=size;i++)
//				printf("%3d",table[i]);
//			printf("\n数目");
//			for(int i=1;i<=size;i++)
//				printf("%3d",sum[i]);
//			printf("\n");
		}
		printf("%d\n",getMax(size));
	}
	return 0;
}
/*
测试数据
样例输入
4
1 2 
3 4
5 6
1 6
4 
1 2 
3 4 
5 6
7 8 
样例输出
4
2
*/



