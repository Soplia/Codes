/*
	Subject:两个日期之间的天数差-预处理 
    Compiler:Devcpp
	Description:输入两个日期，输出两个日期之间的天数 ,连续两天的天数为2。 
	Id:2-2-1
	Author:JiaruiXie
	Date:05/01/17 09:58  
*/

#include <stdio.h>

#define isYear(x) x%100!=0&&x%4==0||x%400==0?1:0

int abs(int a)
{
	return a>0?a:-a;
}
int dayOfYear[13][2]=
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
						31,31,
					};

typedef struct myDate
{
	int day;
	int month;
	int year;
	void nextDay()
	{
		day++;
		if(day>dayOfYear[month][isYear(day)])
		{
			day=1;
			month++;
			if(month>12)
			{
				month=1;
				year++;
			}
		}
		
	}
}Date;

int days[5001][13][32];

int main()
{
	Date myDate;
	myDate.day=1;
	myDate.month=1;
	myDate.year=0;
	//开始时与第一天是相差0天的。 
	int count=0;
	while(myDate.year!=5001)
	{
		days[myDate.year][myDate.month][myDate.day]=count;
		myDate.nextDay();
		count++;
	}
	int d1,d2,m1,m2,y1,y2;
	while(scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF)
	{
		scanf("%4d%2d%2d",&y2,&m2,&d2);
		printf("%d",abs(days[y2][m2][d2]-days[y1][m1][d1])+1);
		printf("\n");
	}
	return 0;
}




















