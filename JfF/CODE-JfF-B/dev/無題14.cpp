#include <stdio.h>
#include <math.h>
#define EPS 1e-4

int main()
{
	int n=1,sign=1;
	float term=1,sum=0;
	while(fabs(term)>=EPS)
	{
		sum+=term;
		sign=-sign;
		n+=2;
		term=sign/(float)n;
	}
	printf("%.5f\n",sum);
	return 0;
}
