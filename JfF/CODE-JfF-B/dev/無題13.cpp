#include <stdio.h>
#define EPS 1e-5

int main()
{
	int n=1;
	float term=1;
	float sum=0;
	while(term>=EPS)
	{
		sum+=term;
		term=term/n;
		n++;
	}
	printf("%.6f\n",sum);
	return 0;
}
