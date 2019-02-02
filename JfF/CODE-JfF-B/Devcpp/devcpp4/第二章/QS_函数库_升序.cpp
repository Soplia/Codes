/*
	Subject:QS_函数库_升序 
    Compiler:Devcpp
	Description:由于不能肯定是否能够快速、正确的写出QS，所以可以借助于
				C++中的sort函数完成快速排序。 
	Id:2-1-3 
	Author:JiaruiXie
	Date:04/01/17 14:59
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int size;
	while(scanf("%d",&size)!=EOF)
	{
		int *p=(int *)malloc(sizeof(int)*size);
		for(int i=0;i<size;i++)
			cin>>p[i];
		
		sort(p,p+size);
		
		for(int i=0;i<size;i++)
			cout<<p[i]<<" ";
		cout<<endl;
	}
	return 0;
}
