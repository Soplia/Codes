/*
	Subject:Least Common Multiple 
    Compiler:Devcpp
	Description:������������С������ 
	Author:JiaruiXie
	Id:4-5-1
	Date_Begin:11/01/17 21:00
	Date_End:
*/
#include <stdio.h>
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		int ta=a;
		int tb=b;
		while(a!=b)
			if(a>b)	
				a-=b;
			else
				b-=a;
		printf("%d\n",ta*tb/a);
	}
	return 0;
} 
/*
��������
��������
10 14
�������
70
*/

