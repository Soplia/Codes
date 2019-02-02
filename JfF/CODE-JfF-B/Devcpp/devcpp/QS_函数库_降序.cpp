/*
	Subject: QS_函数库_降序 
    Compiler:Devcpp
	Description:由于不能肯定是否能够快速、正确的写出QS，所以可以借助于
				C++中的sort函数完成快速排序。
	Id:2-1-2 
	Author:JiaruiXie
	Date:04/01/17 14:20
*/
#include <iostream>
#include <algorithm>
using namespace std;

//不要把它理解成一个函数，把它理解成为一个标志更好
//就是要求排序结束后的数据串中，前面的数大于后面的数 
bool cmp(int x,int y)
{
	return x>y;
} 

int main()
{
	int size;
	while(scanf("%d",&size)!=EOF)
	{
		int *p=(int *)malloc(size*sizeof(int));
		for(int i=0;i<size;i++)
			cin>>p[i];
		
		sort(p,p+size,cmp);
		
		for(int i=0;i<size;i++)
			printf("%d ",p[i]);
		printf("\n");
	}
	return 0;
}

