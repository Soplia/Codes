/*
	Subject:DisjointSet_畅通工程_自己臆造 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:5-2-1
	Date_Begin:16/01/17 15:15
	Date_End:16/01/17 15:42
*/
#include <stdio.h>

const int N=1000;
int table[N];

void init(int x)
{
	for(int i=1;i<=x;i++)
		table[i]=-1;
}

int main()
{
	int m,n;
	while(scanf("%d",&m)!=EOF&&m!=0)
	{
		scanf("%d",&n);
		int num=0;
		init(m);
		int t1,t2;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&t1,&t2);
			
			if(table[t1]==-1&&table[t2]==-1)
				table[t1]=table[t2]=++num;
				
			else if(table[t1]!=table[t2])
				if(table[t1]!=-1)
						table[t2]=table[t1];
						
				else if(table[t2]!=-1)
						table[t1]=table[t2];
		}
		int t=0;
		for(int i=1;i<=m;i++)
			if(table[i]==-1)
				t++;
		printf("%d\n",t+num-1);
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
5 2
1 2
3 5
999 0
0
样例输出
1
0 
2
998
*/

























