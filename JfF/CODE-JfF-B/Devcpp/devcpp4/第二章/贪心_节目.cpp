/*
	Subject:̰��_��Ŀ 
    Compiler:Devcpp
	Description:����һϵ�н�Ŀ�Ŀ�ʼ����ʱ�䣬���а��ţ�Ҫ�����������Ľ�Ŀ 
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
		//�������� 
		if(num==0)
			break;
		TV *a=(TV *)malloc(sizeof(TV)*num);
		for(int i=0;i<num;i++)
		{
			cin>>a[i].startTime>>a[i].endTime;
			a[i].flag=false;
		}
		//������ʱ���С�������� 
		sort(a,a+num);	
		//̰�� 
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
		//��ӡ���
		cout<<ans<<endl;
		for(int i=0;i<num;i++)
			if(a[i].flag)
				cout<<"("<<a[i].startTime<<","<<a[i].endTime<<")"<<"��";
		cout<<"END"<<endl; 
	}
	return 0;
}
/*
��������
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
 
