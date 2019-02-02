/*
	Subject:More is Better
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:5.2
	Date_Begin:01/02/17 19:22
	Result:Accepted
	Date_End:01/02/17 20:06
*/
#include <stdio.h>
#define N 10000001

int Tree[N];
int Num[N];

void init()
{
	for(int i=0;i<N;i++)
	{
		Tree[i]=-1;
		Num[i]=1;
	}
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
	int a;
	while(scanf("%d",&a)!=EOF)
	{
		init();
		int b,c;
		while(a--)
		{
			scanf("%d%d",&b,&c);
			b=findRoot(b);
			c=findRoot(c);
			if(b!=c)
			{
				Tree[c]=b;
				Num[b]+=Num[c];
			}
		}
		
		int max=1;
		for(int i=1;i<N;i++)
			if(Tree[i]==-1&&Num[i]>max)
				max=Num[i];
				
		printf("%d\n",max);
		
	}
	return 0;
}

/*
InputData:
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
outputData:
4 
2
*/

