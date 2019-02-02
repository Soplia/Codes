//已知今天是星期天，编程输入一个整数n，计算n天后是星期几
#include <stdio.h>

enum weekday
{
	mon=1,
	tue=2,
	mar=3,
	tues=4,
	fir=5,
	sta=6,
	sun=7,
};

int main()
{
	int n;
	printf("input a num:\n");
	scanf("%d",&n);
	int t=n%7;
	switch(t)
	{
		case 1:printf("星期一\n");break;
		case 2:printf("星期二\n");break;
		case 3:printf("星期三\n");break;
		case 4:printf("星期四\n");break;
		case 5:printf("星期五\n");break;
		case 6:printf("星期六\n");break;
		case 0:printf("星期七\n");break;
	}
	return 0;
}
