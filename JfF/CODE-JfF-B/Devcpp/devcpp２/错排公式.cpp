/*
	Subject:���Ź�ʽ 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:7-1-2 
	Date_Begin:21/01/17 09:50
	Date_End:
*/
#include <stdio.h>

int main()
{
	int x[21];
	x[1]=1;
	x[2]=2;
	for(int i=3;i<21;i++)
		x[i]=(i-1)*x[i-1]+(i-1)*x[i-2];
	int t;
	while(scanf("%d",&t)!=EOF)
		printf("%d\n",x[t]);
	return 0;
}
/*
��������
��������
2
3
�������
1
2
*/




























