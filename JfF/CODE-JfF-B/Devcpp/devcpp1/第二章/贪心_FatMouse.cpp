/*
	Subject:贪心_FatMouse 
    Compiler:Devcpp
	Description:用一定的钱，买最大价值的东西 
	Author:JiaruiXie
	Id:2-6-1 
	Date_Begin:08/01/17 13:57
	Date_End:08/01/17 14:13
*/
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

typedef struct good
{
	float price;
	float weight;
	float re;
	bool operator < (const good &a) const
	{
		return re>a.re;
	}
}Good;

int main()
{
	float p;
	int n;
	while(scanf("%f%d",&p,&n)!=EOF)
	{
		if(p==-1||n==-1)
			break;
		Good *a=(Good*)malloc(sizeof(Good)*n);
		for(int i=0;i<n;i++)
		{
			cin>>a[i].weight>>a[i].price;
			a[i].re=a[i].weight/a[i].price;
		}
		
		sort(a,a+n);
		
		int pos=0;
		float ans=0.0;
		
		while(pos<n&&p>0)
		{
			if(p>a[pos].price)
			{
				ans+=a[pos].weight;
				p-=a[pos].price;
			}
			else
			{
				ans+=p*a[pos].weight/a[pos].price;
				p=0;
			}
			pos++;
		}
		
		printf("%.3f\n",ans);
	}
	return 0;
}
/*
测试数据
5 3
7 2
4 3
5 2
20 3
25 18
24 15
15 10 
-1 -1
*/























