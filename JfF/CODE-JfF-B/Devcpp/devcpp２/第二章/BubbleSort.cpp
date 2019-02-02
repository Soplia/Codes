/*
	Subject: BubbleSort 
	Compiler:Devcpp
	Description: 1S内当n<=3000是可以使用冒泡排序。 
	Id: 2(第二章)-1(第一个问题--排序)-1(第一个需要记忆的代码)
	Author:JiaruiXie
	Date: 04/01/17 14:05
	
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size;
	//1.防止进行多组输入
	//2.连贯 
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
			printf("%d ",p[i]);//每打印完一个数据之后，都有一个空格 
		printf("\n");//每打印完一行之后，都要打印一个换行 
	}
	return 0;
}

