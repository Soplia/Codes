#include <stdio.h>
#include <math.h>
#define EPS 1e-5

int main()
{
	float x;
	while(scanf("%f",&x)!=EOF)
	{
		int n=1;
		float sum=0,term=1;
		while(fabs(term)>=EPS)
		{
			sum+=term;
			n+=2;
			term=(-1)*term*x*x/(n+1)/(n+2);
		}
		printf("%.5f\n",sum);
	}
	
	return 0;
}
