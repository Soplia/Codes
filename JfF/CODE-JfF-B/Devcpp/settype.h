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
	settype(int a=3);      //���캯����Ĭ�ϼ�����3��Ԫ��
	settype( const settype &B);  //�������캯��
	~settype();
	//void getset(int &n, int * &a);    //��ȡ���ϵ�Ԫ�أ��������롢�����
	//void getset(int &n,int *a);
	void getSize(int &a);
	void getData(int *a);
	void setData(int *a);
    bool operator!();               //�жϼ����Ƿ�Ϊ�գ����輯��Ԫ���Ǵ���0������
	settype operator+(settype B);    //���������+��ʵ�ּ��ϲ�����
	settype operator*(settype B);    //���������*��ʵ�ּ��Ͻ�����
	settype operator-(settype B);    //���������-��ʵ�ּ��ϲ�����
	settype operator=(settype B);    //���������=
		
 private:
    int n;      //Ԫ�ظ���
    int *set;   //����ָ��
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

settype::settype( const settype& B)   //�������캯��
{ 	
	n=B.n;
  	set=new int[n];
  	for(int i=0;i<n;i++)
		set[i]=B.set[i];
}

settype::~settype()     //��������
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
    k=n<B.n?n:B.n;//�����������ҵ���һ������Ԫ�ظ����ٵļ��� 
    int max=n+B.n;
	settype T(max);	//���϶���T������Ų���
	T.n=max; 
	int count=0; //����T����ļ���
	bool flag;//�����ж�set�����е����Ƿ��B�е���һ��. 
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
    settype T(min);            //���϶���T������Ž���
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
  	//settype T(n); //���϶���T������Ų ���ϵ�Ԫ�ظ�����Ҫ����ŪС�ˡ� 
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
bool operator<(int x,settype A)     //�뿴���ú���
//bool settype::operator<(int x,settype A)     //�뿴���ú���
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

istream& operator>>(istream &input, settype& A )    //�뿴���ú���
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

ostream& operator<<(ostream &output, settype& A )    //�뿴���ú���
//ostream& settype::operator<<(ostream &output, settype& A )    //�뿴���ú���
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
