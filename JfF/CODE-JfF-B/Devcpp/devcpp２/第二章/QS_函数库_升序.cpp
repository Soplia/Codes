/*
	Subject:QS_������_���� 
    Compiler:Devcpp
	Description:���ڲ��ܿ϶��Ƿ��ܹ����١���ȷ��д��QS�����Կ��Խ�����
				C++�е�sort������ɿ������� 
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
