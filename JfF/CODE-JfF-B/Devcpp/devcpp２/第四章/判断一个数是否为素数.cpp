/*
	Subject:�ж�һ�����Ƿ�Ϊ���� 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:4-6-1 
	Date_Begin:11/01/17 21:04
	Date_End:11/01/17 21:07
*/
#include <stdio.h>
#include <math.h>
int main()
{
	int a;
	while(scanf("%d",&a)!=EOF)
	{
		int bound=(int)sqrt(a);
		bool flag=true;
		//������Ҫ�ر�ע��1���б� 
		if(a==1)	
			flag=false;
		else
			for(int i=2;i<=bound;i++)
				if(a%i==0)
				{
					flag=false;
					break;
				}
		if(flag)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
} 
/*
��������
��������
13
�������
yes
*/

