/*
	Subject:Çó½×³Ë 
    Compiler:Devcpp
	Description:
	Author:JiaruiXie
	Id:4-8-2 
	Date_Begin:14/01/17 20:40
	Date_End:
*/
#include <stdio.h>

long long bF(int a,int b)
{
	if(b==0)
		return 1;
	else
	{
		long long ans=1;
		while(b!=0)
		{
			if(b%2==1)
				ans*=a;
			a*=a;
			b/=2;
		}
		return ans;
	}
}

int main()
{
	printf("%lld\n",bF(2,31));
	return 0;
}
