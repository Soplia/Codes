#include <stdio.h>
#define N 100

int myStrlen(char *a)
{
	int len=0;
	//��a??�w??�ʁC?�s??�C??���I���꘢���{�C���I
	//�L����p��??����?���������B 
	for(;*a!=0;a++)
		len++;
	return len;
}

int main()
{
	char a[N];
	while(gets(a))
	{
		printf("%d\n",myStrlen(a));
		puts(a);
	}
	return 0;
}
