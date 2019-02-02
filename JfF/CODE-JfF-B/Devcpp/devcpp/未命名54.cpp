//假设有若干教师与学生的数据，教师数据包含姓名，年龄，职业，教研室四项，
//学生数据包含姓名，年龄，职业，班级四项。
//要求编程输入人员数据，并以表格形式输出这些数据。


//有问题，需要进一步改进 
#include <stdio.h>

typedef union stu_tea
{
	int num;
	char name[10];
}Stu_Tea;

int main()
{
	Stu_Tea array[100];
	char next='y';
	int i=0;
	while(next=='y'||next=='Y')
	{
		printf("Input the num:\n");
		scanf("%d",&(array[i++].num));
		printf("Input the name:\n");
		scanf("%s",array[i++].name);
		getchar();
		printf("continue?\n");
		scanf("%c",&next);
	}
	for(int j=0;j<i;j++)
	{
		printf("%-3d%8s",array[j].num,array[j+1].name);
		if((j+1)%2==0)
			printf("\n");
	}
	return 0;
}










