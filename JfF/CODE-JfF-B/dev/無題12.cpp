#include <stdio.h>

int main()
{
	int count=0;
	for(int i=1;i<=21*7;i++)
	{
		if(i%5==0&&i<=21*5)
		{
			count++;
			continue;
		}	
		if(i%6==0&&i<=21*6)
		{
			count++;
			continue;
		}
		if(i%7==0)
			count++;
	}
	printf("%d\n",count);
	return 0;
}

