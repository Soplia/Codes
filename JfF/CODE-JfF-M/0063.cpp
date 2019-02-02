#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,sum=0,cnt=0;
	while(1)
	{
		scanf("%d", &i );
		if ( getchar()=='\n')
		{
			if ( cnt > 0 )
			printf("sum=%d\n", sum );
			else
			break;
			sum=0;
			cnt=0;
		}
		else
		{
			sum += i ;
			cnt++ ;
		}
	}
	return 0;
	
}
