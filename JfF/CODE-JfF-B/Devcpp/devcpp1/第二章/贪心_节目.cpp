/*
	Subject:贪心_节目 
    Compiler:Devcpp
	Description:给出一系列节目的开始结束时间，进行安排，要求完整看最多的节目 
	Author:JiaruiXie
	Id:2-6-2
	Date_Begin:08/01/17 14:49
	Date_End:08/01/17 15:09
*/
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

typedef struct tv
{
	int startTime;
	int endTime;
	bool flag;
	bool operator < (const tv &a) const
	{
		return endTime<a.endTime;
	}
}TV;

int main()
{
	int num;
	while(scanf("%d",&num)!=EOF)
	{
		//读入数据 
		if(num==0)
			break;
		TV *a=(TV *)malloc(sizeof(TV)*num);
		for(int i=0;i<num;i++)
		{
			cin>>a[i].startTime>>a[i].endTime;
			a[i].flag=false;
		}
		//按结束时间从小到大排序 
		sort(a,a+num);	
		//贪心 
		int currentTime=0;
		int ans=0;
		for(int i=0;i<num;i++)
		{
			if(currentTime<=a[i].startTime)
			{
				a[i].flag=true;
				currentTime=a[i].endTime;
				ans++;
			}
		}
		//打印结果
		cout<<ans<<endl;
		for(int i=0;i<num;i++)
			if(a[i].flag)
				cout<<"("<<a[i].startTime<<","<<a[i].endTime<<")"<<"→";
		cout<<"END"<<endl; 
	}
	return 0;
}
/*
测试数据
12
1 3
3 4
0 7
3 8
15 19
15 20
10 15
8 18
6 12
5 10
4 14
2 9 
0
*/
 
