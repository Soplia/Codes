/*
	Subject: BubbleSort 
	Compiler:Devcpp
	Description: 1S�ڵ�n<=3000�ǿ���ʹ��ð������ 
	Id: 2(�ڶ���)-1(��һ������--����)-1(��һ����Ҫ����Ĵ���)
	Author:JiaruiXie
	Date: 04/01/17 14:05
	
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size;
	//1.��ֹ���ж�������
	//2.���� 
	while(scanf("%d",&size)!=EOF)
	{
		int *p=(int *)malloc(sizeof(int)*size);
		for(int i=0;i<size;i++)
			scanf("%d",p+i);
			
		for(int i=0;i<size;i++)
			for(int j=0;j<size-i-1;j++)
				if(p[j]>p[j+1])
				{
					int temp=p[j];
					p[j]=p[j+1];
					p[j+1]=temp;
				}
				
		for(int i=0;i<size;i++)
			printf("%d ",p[i]);//ÿ��ӡ��һ������֮�󣬶���һ���ո� 
		printf("\n");//ÿ��ӡ��һ��֮�󣬶�Ҫ��ӡһ������ 
	}
	return 0;
}

