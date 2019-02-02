/*
	Subject: 5.1_H’ö 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:5.1
	Date_Begin:01/02/17 09:25
	Result:Accepted
	Date_End:01/02/17 19:57
*/

#include <stdio.h>
#define N 1000

int Tree[N];

void init()
{
	for(int i=0;i<N;i++)
		Tree[i]=-1;
}

void dis(int n)
{
	for(int i=1;i<=n;i++)
		printf("%3d",Tree[i]);
	printf("\n");
	for(int i=1;i<=n;i++)
		printf("%3d",i);
	printf("\n");
}

int findRoot(int x)
{
	if(Tree[x]==-1)
		return x;
	else
	{
		int ret=findRoot(Tree[x]);
		Tree[x]=ret;
		return ret;
	}
}

int main()
{
	int a,b;
	while(scanf("%d",&a)!=EOF&&a!=0)
	{
		scanf("%d",&b);
		init();
		int c,d;
		int count=0;
		while(b--)
		{
			scanf("%d%d",&c,&d);
			c=findRoot(c);
			d=findRoot(d);
			if(c!=d)
				Tree[d]=c;
		}
		
		for(int i=1;i<=a;i++)
			if(Tree[i]==-1)
				count++;
		printf("%d\n",count-1);
		
	}
	return 0;
}

/*
InputData:
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
outputData:
1
0
2
998
*/

















