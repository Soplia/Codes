#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100
int data[MAXNUM];
int num;   //记录输入数据的个数
int countOfBinSearch=1;//这个全局变量用于记录查找的次数
						//不能把它声明成局部的因为如果是那样的话每次递归都会重新被赋值的。 
int search_seq(int a)   //顺序查找，输入元素，返回比较次数
{
	int count=1;
	for(int i=0;i<num;i++)
	{
		if(a==data[i])
			break;
		else
			count++;	
	}
	return count;
}
int search_bin(int a,int start,int end)   //折半查找，输入元素，返回比较次数
{
	int mid=(start+end)/2;
	if(data[mid]==a)
		return countOfBinSearch;
	else
	{
		countOfBinSearch++;
		if(a<data[mid])
			search_bin(a,0,mid-1);
		else if(a>data[mid])
			search_bin(a,mid+1,end);
	}	
}
int main()
{
	int aim;
	int count1,count2;
	double average1,average2;
	printf("请输入数据的个数:\n");
	scanf("%d",&num);
	if (num>MAXNUM || num<1) 
	{
		printf("input error");
		return 0;
	}
    printf("请输入检测数据的集合,以空格间隔:\n");
	for(int i=0;i<num;i++)
		scanf("%d",&data[i]);
	printf("请输入待查的数据:\n");
	scanf("%d",&aim);
	count1=search_seq(aim);
	printf("顺序查找的次数是:%d\n",count1);
	count2=search_bin(aim,0,num-1); 
	printf("折半查找的次数是:%d\n",count2);
	average1=(float)count1/num;
	average2=(float)count2/num; 
	printf("顺序查找成功平均比较次数为%.2lf\n",average1);
	printf("折半查找成功平均比较次数为%.2lf\n",average2);
	return 0;
}

















