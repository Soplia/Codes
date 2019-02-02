/*
	Subject:DisjointSet_MonerBetter_自己臆造 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:5-2-3
	Date_Begin:16/01/17 16:43
	Date_End:16/01/17 17:19
*/
#include <stdio.h>

//数据太多，时间复杂度不允许。 
const int N=10000000;
int table[N];

void init()
{
	for(int i=0;i<N;i++)
		table[i]=-1;
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

int getMax(int n)
{
	int t[n+1];
	
	for(int i=1;i<=n;i++)
		t[i]=0;
		
	for(int i=1;i<=n;i++)
		if(table[i]!=-1)
			t[table[i]]++;
			
	int max=0;
	for(int i=1;i<=n;i++)
		if(max<t[i])
			max=t[i];
			
	return max;
}

int main()
{
	int n;
	while(scanf("%d",&n))
	{
		init();
		int a,b;
		int size=-1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			if(size<a)
				size=a;
			if(size<b)
				size=b;
			
			int t1=a,t2=b;
			a=findRoot(a);
			b=findRoot(b);
			
			if(a!=b)
				table[b]=a;
			//再找一遍把所有的子树的根都弄对	
			findRoot(t1);
			findRoot(t2);
				
//			printf("\n添加第%d组伙伴\n",i);	
//			for(int i=1;i<=size;i++)
//				printf("%3d",i);
//			printf("\n");
//			for(int i=1;i<=size;i++)
//				printf("%3d",table[i]);
//			printf("\n");
		}
		
		printf("%d\n",getMax(size)+1);
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

























