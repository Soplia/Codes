//��̽���������ĸ˳����������

#include<stdio.h>

#define  MAXLEN   7
#define  N   4


int main()
{
	char name[N][MAXLEN]={"Pascal","VC","Basic","Java"};
	char *p[N];
	for(int i=0;i<N;i++)
		*p[i]=*(name+i);
	return 0;
}
