/*
	Subject:Greast Common Diviser 
    Compiler:Devcpp
	Description:�������������Լ�� 
	Author:JiaruiXie
	Id:4-4-1 
	Date_Begin:11/01/17 20:48
	Date_End:11/01/17 20:59
*/
#include <stdio.h>
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		while(a!=b)
		{
//			if(a*b==0)
//				if(a==0)
//				{
//					a=b;
//					break;
//				}
//			else else
				if(a>b)
					a=a-b;
				else 
					b=b-a;
		}
		printf("%d\n",a);
	}
	return 0;
}
/*
��������
��������
49 14
�������
7
*/

