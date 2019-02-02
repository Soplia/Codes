/*
	Subject:DisjointSet_畅通工程
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:5-2-2 
	Date_Begin:16/01/17 15:44
	Date_End:18/01/17 14:36
*/

#include <stdio.h>
#include <stdlib.h>
const int N=1000;

int table[N];

void init(int x)
{
	for(int i=1;i<=x;i++)
		table[i]=-1;
}

int findRoot1(int x)
{
	int t=x;
	int ret;
	while(table[x]!=-1)
		x=table[x];
	ret=x;
	
	x=t;
	while(table[x]!=-1)
	{
		int temp=table[x];
		table[x]=ret;
		x=temp;
	}
	
	return ret;
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

int main()
{
	int n,m;
	while(scanf("%d",&n)!=EOF && n!=0)
	{
		init(n);
		scanf("%d",&m);
		int a,b;
		for(int i=1;i<=m;i++)
		{
			int aa,bb;
			scanf("%d%d",&a,&b);
			a=findRoot(a);
			b=findRoot(b);
			if(a!=b)
				table[b]=a;
			printf("\n添加第%d条公路\n",i);	
			for(int i=1;i<=n;i++)
				printf("%3d",i);
			printf("\n");
			for(int i=1;i<=n;i++)
				printf("%3d",table[i]);
			printf("\n");
			
			
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			if(table[i]==-1)
				ans++;
		printf("ans=%d\n",ans-1);
		
	}
	return 0;
}

/*
测试数据
样例输入
4 2
1 3
4 3
3 3 
1 2 
1 3
2 3 
5 4
1 2
3 5
4 5
4 2
999 0
0
样例输出
1
0 
2
998
*/

