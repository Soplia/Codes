//求某个班英语成绩的平均分, 该班学生人数和每个学生的成绩由键盘输入
#include <stdio.h>
int main()
{
	int num;
	printf("请输入学生的人数：\n");
	scanf("%d",&num);
	int sum=0;
	for(int i=0;i<num;i++)
	{
	 		int j;
	scanf("%d",&j);
		sum+=j;
	}
	return 0;
}
