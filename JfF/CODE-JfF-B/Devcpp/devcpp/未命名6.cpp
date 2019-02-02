//输入一个年份、月份，输出此月的天数（按阳历计算）
#include<stdio.h>
int main()
{
	int year,month;
	printf("Input the year and month:\n");
	scanf("%d%d",&year,&month);
	if(year>=1869&&year<=2016&&month>=1&&month<12)
	{
		switch(month)
		{
			case 2:
				 if(year%4==0||year%100==0)
		         printf("这个月的天数是28天\n");
		         else
		         	 printf("这个月的天数是29天\n");
			break;
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:printf("这个月的天数是31天\n");break;
			case 4:
			case 6:
			case 9:
			case 11:printf("这个月的天数是30天\n");break;
		}
	}
	else
		printf("请确认输入是否正确!\n");
	return 0;
}
