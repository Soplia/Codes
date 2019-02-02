#include <stdio.h>

int const N=10;

int table[N];

//�ݹ���Ҹ��ڵ� 
int findRoot(int x)
{
	if(table[x]==-1)
		return x;
	else
		return findRoot(table[x]);
}

//�ǵݹ���Ҹ��ڵ�
int findRoot(int x)
{
	int t;
	while(table[x]!=-1)
		x=table[x];
	t=x;
	return t;
} 

//�ݹ�����иı�DisjointSet�Ľṹ
int findRoot(int x)
{
	if(table[x]==-1)
		return x;
	else
	{
		int temp=findRoot(table[x]);
		table[x]=temp;
		return temp;
	}	
} 

//�ڷǵݹ�����иı�DisjointSet�Ľṹ
int findRoot(int x)
{
	int t1=x;
	int ret;
	while(table[x]!=-1)
		x=table[x];
	ret=x;
	x=t1;
	while(table[x]!=-1)
	{
		int t2=table[x];
		table[x]=ret;
		x=t2;
	}
	return ret;
} 
