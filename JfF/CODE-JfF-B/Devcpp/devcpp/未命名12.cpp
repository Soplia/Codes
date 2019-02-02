//求Fibonacci数列1 , 1 ,  2 , 3 , 5 , 8 ,  …的前20 个数       
#include <stdio.h>
int main()
{
	int a=0,b=0;
	int c=1;
	for(int i=1;i<=20;i++)
	{
		printf("%7d",c);
		if(i%5==0)
			printf("\n");
		a=b;
		b=c;
		c=a+b;
	}
	return 0;
} 
