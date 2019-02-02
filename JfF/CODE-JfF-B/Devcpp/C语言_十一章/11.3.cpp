#include <stdio.h>

int main()
{
	char *month[]=
					{"","January","February","March",
					 "April","May","June","July",
					 "August","September","October",
					 "Novermber","December"};
	int x;
	while(scanf("%d",&x)!=EOF)
	{
		if(x<1||x>12)
			printf("Illegal!\n");
		else
			printf("%s\n",month[x]);
	}
	return 0;
}
