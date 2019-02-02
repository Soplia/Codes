#include <stdio.h>
#include <math.h>


int main()
{
	int num =0;
	float price =0.0;
	char ch1, ch2;
	if (scanf("%d%c%c%f", &num, &ch1,&ch2,&price) != EOF)
	{
		double oriPrice1 = num * price;
		double oriPrice2 = num * price;
		double relPrice1 = 0.0;
		double relPrice2 = 0.0;
		if (num >= 3)
			relPrice1 = oriPrice1 * 0.7;
		if (fabs(relPrice1 - 50) <= 0.01)
			relPrice1 -= 10;
		if (fabs(relPrice1 - 10) <= 0.01)
			relPrice2 -= 2;
		if (fabs(relPrice1 - 99) <= 0.01)
			relPrice2 -= 6;
		if (fabs(relPrice1 - relPrice2) <= 0.01)
			printf("0");
		else if ((relPrice1 - relPrice2) > 0)
			printf("2");
		else
			printf("1");
	}
	//system("pause");
	return 0;
}
