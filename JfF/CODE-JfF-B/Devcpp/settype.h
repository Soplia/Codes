//#if !defined(AFX_SETTYPE_H__BEA8EDF4_E9E2_46C2_9BB0_601E5D7C9AA9__INCLUDED_)
//#define AFX_SETTYPE_H__BEA8EDF4_E9E2_46C2_9BB0_601E5D7C9AA9__INCLUDED_

//#if _MSC_VER > 1000
//#pragma once
//#endif // _MSC_VER > 1000

//#include <iostream>
//#include <iomanip>
//using namespace std;

#ifndef SETTYPE
#define SETTYPE
#include <iostream>
#include <iomanip>
using namespace std;
class settype  
{
 public:
 //	settype(int size,char *array);
	settype(int a=3);      //构造函数，默认集合有3个元素
	settype( const settype &B);  //拷贝构造函数
	~settype();
	//void getset(int &n, int * &a);    //获取集合的元素，用于输入、输出等
	//void getset(int &n,int *a);
	void getSize(int &a);
	void getData(int *a);
	void setData(int *a);
    bool operator!();               //判断集合是否为空，假设集合元素是大于0的整数
	settype operator+(settype B);    //重载运算符+，实现集合并运算
	settype operator*(settype B);    //重载运算符*，实现集合交运算
	settype operator-(settype B);    //重载运算符-，实现集合差运算
	settype operator=(settype B);    //重载运算符=
		
 private:
    int n;      //元素个数
    int *set;   //数组指针
};
void settype::getData(int *a)
{
	for(int i=0;i<n;i++)
		a[i]=set[i];
}
void settype::getSize(int &a)
{
	a=n;
}
void settype::setData(int *a)
{
	
	for(int i=0;i<n;i++)
		set[i]=a[i];
	
}
//settype::settype(int size,char *array)
//{
//	 this->n=size;
//	 for(int i=0;i<size;i++)
//	 	set[i]=array[i]-'0';
//}
settype::settype( int a )
{  
	n=a;
   	set=new int[n];
   	for(int i=0;i<n;i++)
		set[i]=0;
}

settype::settype( const settype& B)   //拷贝构造函数
{ 	
	n=B.n;
  	set=new int[n];
  	for(int i=0;i<n;i++)
		set[i]=B.set[i];
}

settype::~settype()     //析构函数
{
  delete[] set;
}
//void settype::getset(int &num,int *a)
//{
//	num=n;
//	for(int i=0;i<n;i++)
//		a[i]=set[i];	
//}

bool settype::operator!()
{
	bool flag=true;
		for(int i=0;i<n;i++)
			if(set[i]!=0)
			{ 
				flag=false;
			  	break;
			}
   	return flag;
}

settype settype::operator+(settype B)
{   
	int i,j,k;
    k=n<B.n?n:B.n;//两个集合中找到了一个包含元素个数少的集合 
    int max=n+B.n;
	settype T(max);	//集合对象T用来存放并集
	T.n=max; 
	int count=0; //用于T数组的计数
	bool flag;//用于判断set数组中的数是否和B中的数一样. 
	//if(k==n)
	{ 
		for(i=0;i<B.n;i++)
			T.set[count++]=B.set[i]; 
	  		//T.set[i]=B.set[i];
	  	for(j=0;j<n;j++)
	  	{
	  		flag=true; 
	  		for(i=0;i<B.n;i++)
			  	if(set[j]==B.set[i])
			  		flag=false;
		  	if(flag) 
		  		T.set[count++]=set[j];
				//T.set[count++]=set[i];
	  	}  	
	}/*
	else
	{   
		for(i=0;i<n;i++)
	      	T.set[i]=set[i];
	    for(j=0;j<B.n;j++)
		    for(i=0;i<n;i++)
			{
				if(set[i]!=B.set[j])
				  	T.set[k++]=B.set[j];
			} 
		for(i=0;i<n;i++)
			T.set[count++]=set[i]; 
	  		//T.set[i]=B.set[i];
	  	for(j=0;j<n;j++)
	  	{
	  		flag=true;
	  		for(i=0;i<B.n;i++)
			  	if(set[i]==B.set[j])
			  		flag=false;
		  	if(flag) 
				T.set[count++]=B.set[i];
	  	}  	
	}*/
    return T;
}


settype settype::operator*(settype B)
{    
    int i,j,k=0;
    int min=n<B.n?n:B.n;
    settype T(min);            //集合对象T用来存放交集
    for(i=0;i<n;i++)
		for(j=0;j<B.n;j++)
		//{    
			if(B.set[j]==set[i])
			//{    
				T.set[k++]=set[i];
	        	//k++;
			//}
		//}
	return T;
}

settype settype::operator-(settype B)
{
  	int i,j,k=0;
  	int max=n>B.n?n:B.n;
  	//settype T(n); //集合对象T用来存放差集 集合的元素个数不要把它弄小了。 
  	settype T(max);
  	bool flag;
  	for(i=0;i<n;i++)
  	{
  		flag=true;
  		for(j=0;j<B.n;j++)
		  	//if(set[i]!=B.set[j])
		  	if(set[i]==B.set[j])
		  		  flag=false;
		  		//T.set[k++]=set[i];
		          	//k++; 
		  	
		if(flag)
			T.set[k++]=set[i];
  	}
	for(i=0;i<B.n;i++)
  	{
  		flag=true;
  		for(j=0;j<n;j++)
		  	//if(set[i]!=B.set[j])
		  	if(set[j]==B.set[i])
		  		  flag=false;
		  		//T.set[k++]=set[i];
		          	//k++; 
		  	
		if(flag)
			T.set[k++]=B.set[i];
  	}
	  	
	  /*
   for(i=0;i<B.n;i++)
	   for(j=0;j<n;j++)
		   if(set[j]!=B.set[i])
		   {
		   		T.set[k++]=B.set[i];
		      	//k++;
		   }
	  */                                             
		     
    return T;
}

settype settype::operator =(settype B)
{  
	if( this!=&B)
   	{
	  	n=B.n;
	  	delete[] set;
	  	set=new int[n];
	  	for(int i=0;i<n;i++)
		  	set[i]=B.set[i];
   	}
	return *this;
}
bool operator<(int x,settype A)     //请看懂该函数
//bool settype::operator<(int x,settype A)     //请看懂该函数
{
	int num,*a;
	A.getSize(num);
	a=new int[num];
	A.getData(a);
   	//A.getset(num,a);
   	//for(int i=0;i<num;i++)
	for(int i=0;i<num;i++)
	  	if(x==a[i])
		  	return true;
  	//if(i==num) 
	return false;
	
}

istream& operator>>(istream &input, settype& A )    //请看懂该函数
//istream &settype::operator>>(istream &input ,settype &A)
{
    int x;
	
	int num,*a;
    A.getSize(num);
    a=new int[num];
	for(int i=0;i<num;i++)
	{  
		//input>>x;
	   	//a[i]=x;
	   	input>>a[i];
	}
	A.setData(a);
	return input;
}

ostream& operator<<(ostream &output, settype& A )    //请看懂该函数
//ostream& settype::operator<<(ostream &output, settype& A )    //请看懂该函数
{
//    int num,*a=NULL;
//    A.getset(num,a);
	int num,*a;
	A.getSize(num);
	a=new int[num];
	A.getData(a);
	if(!A)
	{  
		output<<"{}"<<endl;
	   	return output;
	}
	output<<"{";
	for(int i=0;i<num;i++)
	   	if(a[i])  output<<a[i]<<",";
	output<<"\b}"<<endl;
	return output;
}
#endif
