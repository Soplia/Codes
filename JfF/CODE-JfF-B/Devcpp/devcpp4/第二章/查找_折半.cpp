/*
	Subject:查找 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:2-5-1
	Date_Begin:07/01/17 14:30
	Date_End:07/01/17 14:54
*/

#include <stdio.h>
#include <stdlib.h>
 
typedef struct node
{
	int num;
	char name[20];
	char sex[2];
	int age;
}Stu;


							
int main()
{
	int n1,n2;
	while(scanf("%d",&n1)!=EOF)
	{
		Stu *b= (Stu *)malloc(sizeof(Stu)*n1);
		for(int i=0;i<n1;i++)
			scanf("%d%s%s%d",&b[i].num,b[i].name,b[i].sex,&b[i].age);
		scanf("%d",&n2);
		int *a=(int *)malloc(sizeof(int )*n2);
		for(int i=0;i<n2;i++)
			scanf("%d",a+i);
		for(int i=0;i<n2;i++)
		//这个地方可以让空位补零 
			printf("%02d %s %s %d\n",b[a[i]-1].num,b[a[i]-1].name,b[a[i]-1].sex,b[a[i]-1].age);
	}
	return 0;
}
























