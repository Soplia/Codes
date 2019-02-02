#include <iostream>
using namespace std; 
bool equal(int a,int b,int c,int d)
{
	int array[4];
	array[0]=a;
	array[1]=b;
	array[2]=c;
	array[3]=d;
	for(int i=0;i<4;i++)
		for(int j=i+1;j<4;j++)
			if(array[i]==array[j])
				return false;
	return true;
}
bool equal(int a,int b,int c,int d,int e,int f,int g,int h,int r)
{
	int array[9];
	array[0]=a;
	array[1]=b;
	array[2]=c;
	array[3]=d;
	array[4]=e;
	array[5]=f;
	array[6]=g;
	array[7]=h;
	array[8]=r;
	for(int i=0;i<9;i++)
		for(int j=i+1;j<9;j++)
			if(array[i]==array[j])
				return false;
	return true;
}
int main()
{
	int first,second,third;
	for(int i=1;i<=9;i++)
		for(int j=1;j<=9;j++)
			for(int k=1;k<10;k++)
				for(int a=1;a<10;a++)
					for(int b=1;b<10;b++)					
						for(int c=1;c<10;c++)
							for(int d=1;d<10;d++)
								for(int e=1;e<10;e++)
									for(int f=1;f<10;f++)
									{
										if(equal(i,j,k,a))
											first=i*1000+j*100+k*10+a;
										if(equal(c,d,e,f))
											second=c*1000+d*100+e*10+f;
										if(first*b==second&&equal(i,j,k,a,b,c,d,e,f))
											cout<<i<<j<<k<<a<<"*"<<b<<"="<<c<<d<<e<<f<<endl;
									}	
}



















