/*
	Subject: QS_������_���� 
    Compiler:Devcpp
	Description:���ڲ��ܿ϶��Ƿ��ܹ����١���ȷ��д��QS�����Կ��Խ�����
				C++�е�sort������ɿ�������
	Id:2-1-2 
	Author:JiaruiXie
	Date:04/01/17 14:20
*/
#include <iostream>
#include <algorithm>
using namespace std;

//��Ҫ��������һ����������������Ϊһ����־����
//����Ҫ���������������ݴ��У�ǰ��������ں������ 
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

