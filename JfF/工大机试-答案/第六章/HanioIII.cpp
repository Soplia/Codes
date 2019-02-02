/*
	Subject:HanioIII 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:6.4
	Date_Begin:03/02/17 10:45
	Result:Accepted
	Date_End:03/02/17 10:47
*/
#include <stdio.h>

long f(int x)
{
	if(x==1)
		return 2;
	else
		return 3*f(x-1)+2;
}

int main()
{
	int x;
	while(scanf("%d",&x)!=EOF)
		printf("%ld\n",f(x));
	return 0;
}
//#include <stdio.h>
//
//void move(int x,char a,char b)
//{
//	printf("%d:%cÅ®%c\n",x,a,b);
//}
//
//void hanio(int x,char a,char b,char c)
//{
//	if(x==1)
//	{
//		move(x,a,b);
//		move(x,b,c);
//	}
//	else
//	{
//		hanio(x-1,a,b,c);
//		move(x,a,b);
//		hanio(x-1,c,b,a);
//		move(x,b,c);
//		hanio(x-1,a,b,c);
//	}
//}
//
//int main()
//{
//	int x;
//	while(scanf("%d",&x)!=EOF)
//		hanio(x,'A','B','C');
//	return 0;
//}
/*
InputData:
1
3
12
outputData:
2
26
531440
*/


