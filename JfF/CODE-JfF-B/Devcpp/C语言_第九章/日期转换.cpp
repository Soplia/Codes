/*
Subject:日期转换 
ID:9.4
Complier:Devcpp
Author:JiaruiXie
StartTime:23/01/17 10:46
EndTime:
*/
#include <stdio.h>

int day[2][13][32];
int dayOfMonth[2][13]=
						{
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

int isYear(int a)
{
	//闰年返回1 
	if(a%100!=0&&a%4==0||a%400==0)
		return 1;
	return 0;
}

void pre()
{
	for(int y=0;y<=1;y++)
	{
	 	int t=0;
		for(int m=1;m<=12;m++)
			for(int d=1;d<=dayOfMonth[y][m];d++)
			{
				t++;
				day[y][m][d]=t;
			}
	} 
}

int DayofYear(int year,int month,int d)
{
	printf("%d\n",isYear(year)); 
	return day[isYear(year)][month][d];
}

void MonthDay(int year,int yearDay,int *mm,int *dd)
{
	int y=isYear(year);
	for(int m=1;m<=12;m++)
		for(int d=1;d<=dayOfMonth[y][m];d++)
			if(day[y][m][d]==yearDay)
			{
				*mm=m;
				*dd=d;
			}
}

int main()
{
	pre();
	printf("%d\n",day[1][1][31]); 
	printf("%d\n",day[1][2][29]); 
	printf("%d\n",day[1][3][1]);
	int year,month,day;
	int m,d;
	while(scanf("%d%d%d",&year,&month,&day)!=EOF)
		printf("%d\n",DayofYear(year,month,day));
//	while(scanf("%d%d",&year,&day)!=EOF)
//	{
//		MonthDay(year,day,&m,&d);
//		printf("%d-%d\n",m,d);
//	}
//		
	return 0;
}
/*
测试数据
样例输入
2000 3 1
2011 3 1
样例输出
61
60
*/
















