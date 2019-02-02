///猴子吃桃问题：猴子第一天摘下若干个桃子，当即吃了
//一半，还不瘾，又多吃了一个,第二天早上又将剩下的桃子吃掉
//一半，又多吃了一个。以后每天早上都吃了前一天剩下的一半
//零一个。到第10天早上想再吃时，只剩下一个桃子了。求第一天
//共摘了多少 桃子
#include <stdio.h>

int rest(int);
int eat(int);

int main()
{
	for(int i=1;i<=2000;i++)
		if(eat(i)==1)
		{
			printf("%d",i);
			break;
		}
	return 0;
}

int rest(int a)
{
	return 2*(a+1);	
}
int eat(int a)
{
	for(int i=1;i<=9;i++)
	{
		a=rest(a);
		if(a<1)
			break;
	}
	return a;
}
