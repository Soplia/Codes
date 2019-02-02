//设计一个歌唱比赛的计分程序, 有10名专家给歌手打分, 
        //歌手的最终成绩为去掉一个最高分和一个最低分的平均分
#include<stdio.h>
int main()
{
	int max=-1111,min=9999;
	double sum=0;
	printf("请输入学生成绩:\n");
	int i;
	for(int j=0;j<10;j++)
	{
		scanf("%d",&i);
		sum+=i;
		if(i>max)
	 max=i;
	 else if(i<min)
	 min=i;
	}
	sum=sum-min-max;
	printf("%.2f",sum/8);
	return 0;
	
}

