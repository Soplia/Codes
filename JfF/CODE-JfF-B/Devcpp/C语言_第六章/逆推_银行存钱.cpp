/*
	Subject:逆推_银行存钱 
    Compiler:Devcpp
	Description:银行1年整存零取的月息为1.875%，某人向银行中存入a元，一年后取出1000元后刚好取完，问a是多少？
				正确答案是a=1000/(1+12*0.01875),但是我想的是a=1000/pow(1+0.01875,12);我想问一下 1年整存零取的月息为1.875%
				该怎样理解？ 
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
