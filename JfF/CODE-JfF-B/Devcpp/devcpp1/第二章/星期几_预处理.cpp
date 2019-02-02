/*
	Subject:星期几 
    Compiler:Devcpp
	Description:给定一个日期确定其是星期几 
	Id:2-2-3
	Author:JiaruiXie
	Date_Begin:05/01/17 11:02
	Date_End:05/01/17 12:20
*/

#include <stdio.h>
#include <string.h>

#define isYear(x) x%100!=0&&x%4==0||x%400==0?1:0

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

typedef struct myDate
{
	int day;
	int month;
	int year;
	void nextDay()
	{
		day++;
		if(day>dayOfMonth[month][isYear(year)])
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

char monthName[13][20]=
						{
						"",
						"January",
						"February",
						"March",
						"April",
						"May",
						"June",
						"July",
						"August",
						"September",
						"October",
						"November",
						"December"	
						};
char weekName[7][20]=
					{
					"Sunday",
					"Monday",
					"Tuesday",
					"Wednesday",
					"Thursday",
					"Friday",
					"Saturday"	
					};
int main()
{
	Date myDate;
	myDate.day=1;
	myDate.month=1;
	myDate.year=0;
	int count=0;
	while(myDate.year<5000)
	{
		days[myDate.year][myDate.month][myDate.day]=count;
		myDate.nextDay();
		count++;
	}
	char s[20];
	int y,d,m;
	//注意输入格式 
	while(scanf("%d%s%d",&d,s,&y)!=EOF)
	{
		//通过这种方法来确定month是多少
		//比switch case简洁太多了 
		for(m=1;m<=12;m++)
			if(strcmp(s,monthName[m])==0)
				break;
		
		//printf("%d_%d_%d\n",y,m,d);
		//日期相差有可能是正也有可能是负 
		int day=days[y][m][d]-days[2017][1][5];
		//printf("%d\n",day);
		//day如果是正的无所谓，但是负的话会day%7+4可能会发生数组下标越界。 
		//利用补码规律减负数相当于加上|模|+该负数 
		puts(weekName[((day%7+7)+4)%7]);
	}
	return 0;
}





















