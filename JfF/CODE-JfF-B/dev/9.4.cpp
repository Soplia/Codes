/*
Subject:9.4
ID:9.4
Complier:Devcpp
Author:JiaruiXie
StartTime:10/02/17 10:47
Result:
EndTime:
*/
#include <stdio.h>

int dayOfMonth[13][2]=
						{
							0,0,
							31,31,
							28,29,
							31,31,
							30,30,
							31,31,
							30,30,
							31,31,
							31,31,
							30,30,
							31,31,
							30,30,
							31,31
						};

int isYear(int x)
{
	return (x%100!=0&&x%4==0||x%400==0)?1:0;
}

int getDay(int y,int m,int d)
{
	for(int i=1;i<m;i++)
		d+=dayOfMonth[i][isYear(y)];
	return d;
}

void getYMD(int y,int *m,int *d)
{
	for(;*d>dayOfMonth[*m][isYear(y)];(*m)++)
		*d-=dayOfMonth[*m][isYear(y)];
}

int main()
{
	int y,d;
	while(scanf("%d%d",&y,&d)!=EOF)
	{
		int m=1;
		getYMD(y,&m,&d);
		printf("%d_%d_%d\n",y,m,d);
	}
	return 0;
}
/*
InputData:

OutputData:

*/

