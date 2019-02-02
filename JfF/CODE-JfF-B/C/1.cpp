#include <stdio.h>
#include <sys/time.h>

void dis()
{
	int a=0;
	for(int i=0;i<1000000;i++);
}

int main()
{
	struct timeval tv_begin,tv_end;
	gettimeofday(&tv_begin,NULL);
	printf("%d,%d\n",tv_begin.tv_sec,tv_begin.tv_usec);
	dis();
	gettimeofday(&tv_end,NULL);
	printf("%d,%d\n",tv_end.tv_sec,tv_end.tv_usec);
	return 0;
}

