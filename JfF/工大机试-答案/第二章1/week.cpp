/*
Subject:week
ID:2.4
Complier:Devcpp
Author:JiaruiXie
StartTime:06/02/17 09:08
Result:	Accepted
EndTime:06/02/17 09:55
*/
#include <stdio.h>
#include <string.h>
char week[][12]={  "Wednesday","Thursday",
				   "Friday","Saturday","Sunday","Monday","Tuesday"};

char month[][12]={ "","January","February","March","April","May",
				   "June","July","August","September","October","Novermber",
				   "December"};

int dayOfMonth[][2]=
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
				
int day[5001][13][32];

int getMonth(char name[])			
{
	for(int i=1;i<13;i++)
		if(strcmp(month[i],name)==0)
			return i;
	return -1;
}

int isYear(int x)
{
	if(x%100!=0&&x%4==0||x%400==0)
		return 1;
	return 0;
}

void init()
{
	int y=0,m=1,d=0,cnt=0;
	while(y!=5001)
	{
		cnt++;
		d++;
		if(d>dayOfMonth[m][isYear(y)])
		{
			d=1;
			m++;
			if(m>12)
			{
				m=1;
				y++;
			}
		}
		day[y][m][d]=cnt;
	}
}

int main()
{
	int d,y,m;
	char mo[12];
	init();
	
	while(scanf("%d%s%d",&d,mo,&y)!=EOF)
	{	
		m=getMonth(mo);
		int rest=day[y][m][d]-day[2017][2][6];
		
		printf("%s\n",*(week+(rest%7+12)%7));
	}
	
	return 0;
}
/*
InputData:
9 October 2001
14 October 2001
OutputData:
Tuesday
Sunday
*/

