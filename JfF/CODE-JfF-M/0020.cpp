#include <stdio.h>


int[] RandomNum(int m,int n)
{
	int[] v = new int[m];
	boolean[] b = new boolean[n];
	Random r = new Random();
	do
	{
		int x = r.nextInt(n);
		if(!b[x])
		{
		    
			v[--m]=x;
		    b[x]=true;
		}
	}
	while(m>0);
	return v;
}

int main()
{
	return 0;
}
