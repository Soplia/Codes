#include <iostream>
using namespace std;
const int size=2;

void dis(int a[size][size],int size)
{
	for (int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
			cout<<a[i][j]<<"  ";
		cout<<endl;
	}
}

void matrixKIJ(int a[size][size],int b[size][size],int c[size][size],int n)
{
	for(int k=0;k<n;++k)
	    for(int i=0;i<n;++i)
	    {
	        double r = a[i][k];
	        for(int j=0;j<n;++j)
	        {
	        	c[i][j]+=r*b[k][j];
	        	cout<<"c["<<i<<"]["<<j<<"]+=a["<<i<<"]["<<k<<"]*b["<<k<<"]["<<j<<"]"<<endl;
			}
	            
	    }
}

void matrixIJK(int a[size][size],int b[size][size],int c[size][size],int n)
{
	for(int i=0;i<n;++i)
	    for(int j=0;j<n;++j)
	    {
	        double sum=0;
	        for(int k=0;k<n;++k)
	        {
	        	//sum+=a[i][k]*b[k][j];
	        	//cout<<"a["<<i<<"]["<<k<<"]*b["<<k<<"]["<<j<<"]"<<endl;
	        	c[i][k]+=a[i][j]*b[j][k];
	        	cout<<"c["<<i<<"]["<<k<<"]+=a["<<i<<"]["<<j<<"]*b["<<j<<"]["<<k<<"]"<<endl;
			}
	            
	        //c[i][j]+=sum;
	    }
}

int main()
{
	//int a[][3]={1,2,3,4,5,6,7,8,9};
	//int b[][3]={1,2,3,4,5,6,7,8,9};
	//int c[3][3]={0,0,0,0,0,0,0,0,0};
	
	int a[][size]={1,2,3,4};
	int b[][size]={1,2,3,4};
	int c[size][size]={0,0,0,0};
	
	//matrixKIJ(a,b,c,size);
	
	matrixIJK(a,b,c,size);
	
	dis(c,size);
	
	return 0;
}
