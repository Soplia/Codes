/*
	Subject:����_���д�Ǯ 
    Compiler:Devcpp
	Description:����1��������ȡ����ϢΪ1.875%��ĳ���������д���aԪ��һ���ȡ��1000Ԫ��պ�ȡ�꣬��a�Ƕ��٣�
				��ȷ����a=1000/(1+12*0.01875),�����������a=1000/pow(1+0.01875,12);������һ�� 1��������ȡ����ϢΪ1.875%
				��������⣿ 
	Author:JiaruiXie
	Id:6.6
	Date_Begin:31/01/17 09:20
	Date_End:31/01/17 09:24
*/
#include <stdio.h>
#define Rate 0.01875
#define Month 12
#define Year 5
#define Cap 1000

int main()
{
	float deposit=0;
	for(int i=0;i<Year;i++)
		deposit=(deposit+Cap)/(1+Month*Rate);
	printf("%.2f\n",deposit);
	return 0;
}
