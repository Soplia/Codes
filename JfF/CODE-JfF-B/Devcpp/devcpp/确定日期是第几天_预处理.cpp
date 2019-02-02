/*
	Subject:确定日期是第几天_预处理 
    Compiler:Devcpp
	Description:给定一个日期，确定其是那一年的第几天 
	Id:2-2-2
	Author:JiaruiXie
	Date_Begin:05/01/17 10:23
	Date_End:05/01/17 10:33
*/
#include <stdio.h>

#define isYear(x) x%100!=0&&x%4==0||x%400==0?1:0

int abs(int a)
{
	return a<0?-a:a;
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
		if(day>dayOfYear[month][isYear(year)])
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
	int count=0;
	while(myDate.year!=5000)
	{
		days[myDate.year][myDate.month][myDate.day]=count;
		myDate.nextDay();
		count++;
	}
	
	int y1,y2,m1,m2,d1,d2;
	while(scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF)
	{
		//scanf("%4d%2d%2d",&y2,&m2,&d2);
		//将输入的日期与这一年的元旦相减即可得到答案 
		printf("%d\n",abs(days[y1][m1][d1]-days[y1][1][1])+1);
	}
	return 0;
}			
					
					
					
					
					
					
					
					
					
					
					

