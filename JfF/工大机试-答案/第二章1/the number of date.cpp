/*
Subject:the number of date
ID:2.3
Complier:Devcpp
Author:JiaruiXie
StartTime:05/02/17 20:37
Result:Accepted
EndTime:05/02/17 21:06
*/
#include <stdio.h>
#include <math.h>

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

int isYear(int x)
{
	if(x%100!=0&&x%4==0||x%400==0)
		return 1;
	return 0;
}

void init()
{
	int cnt=0;
	int y=0,m=1,d=0;
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
	int y1,y2,m1,m2,d1,d2;
	init();
	while(scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF)
	{
		scanf("%4d%2d%2d",&y2,&m2,&d2);
		printf("%d\n",abs(day[y2][m2][d2]-day[y1][m1][d1])+1);
	}
	return 0;
}
/*
InputData:
20110412
20110422
OutputData:
11
*/

