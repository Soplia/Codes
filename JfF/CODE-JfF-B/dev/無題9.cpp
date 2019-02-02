#include <stdio.h>
#include <math.h>
#define EPS 100

int main()
{
	float r,output;
	while(scanf("%f",&r)!=EOF)
	{
		int i;
		output=100;
		for( i=0;output<200;i++)
			output=output*(1+r);
			
		
		printf("%d\n",i);
	}
	return 0;
}
