#include <stdio.h>

int main()
{
	long ans1=0,ans2=0;
	long term1=1;
	int term2=10;
	for(int i=1;i<=30;i++)
	{
		ans1+=term1;
		ans2+=term2;
		term1*=2;
	}
	printf("%ld,%ld\n",ans1,ans2);
	return 0;
}
