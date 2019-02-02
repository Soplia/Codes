/*
	Subject:階段（かいだん）お登る （のぼる） 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:7.1
	Date_Begin:04/02/17 10:35
	Result:Accepted
	Date_End:04/02/17 10:43
*/
#include <stdio.h>

int main()
{
	long long setp[100];
	setp[1]=1;
	setp[2]=2;
	for(int i=3;i<=99;i++)
		setp[i]=setp[i-1]+setp[i-2];
	int size;
	while(scanf("%d",&size)!=EOF&&size!=0)
		printf("%lld\n",setp[size]);
	return 0;
}

/*
InputData:
4
OutputData:
5
*/

