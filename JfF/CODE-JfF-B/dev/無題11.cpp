#include <stdio.h>
#include <math.h> 

int main()
{
	for(int i=1;i<=9;i++)
		for(int j=0;j<=9;j++)
		if(i==j)
			continue;
		else
		{
			float temp=i*1000+i*100+j*10+j;
			if(sqrt(temp)==(int)sqrt(temp))
			{
				printf("%.0f\n",temp);
				goto END;
			}
		}
	END:
	return 0;
}
