//���������ɽ�ʦ��ѧ�������ݣ���ʦ���ݰ������������䣬ְҵ�����������
//ѧ�����ݰ������������䣬ְҵ���༶���
//Ҫ����������Ա���ݣ����Ա����ʽ�����Щ���ݡ�


//�����⣬��Ҫ��һ���Ľ� 
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










