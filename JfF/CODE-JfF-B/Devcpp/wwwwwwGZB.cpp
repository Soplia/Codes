// wwwwww.cpp : Defines the entry point for the console application.
//

// wwww.cpp : Defines the entry point for the console application.
//

// pro1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<iostream>
using namespace std;
class fraction
{  public:
      fraction();
      fraction(const int a);
      fraction(const int a,const int b);
      fraction operator +(fraction& m);
      fraction operator -(fraction& m);
      fraction operator *(fraction& m);
      fraction operator /(fraction& m);
      void set(int a,int b);
      void common(fraction & m);
      void reduct();
	  void disply();
   private:
	   int molecule;
	   int denominator;
};
void fraction::set(int a,int b)
{
	this->molecule=a;
	this->denominator=b;
}
fraction::fraction()
{ molecule=0;
  denominator=1;}
fraction::fraction(const int a)
{ molecule=a;
  denominator=1;
}
fraction::fraction(const int a,const int b)//const 保证通分约分引用值不变
{ molecule=a;
  denominator=b;
}
void fraction::common(fraction& m)
{int a, b,c,t;
  a=denominator;
  b=m.denominator;
  if(a!=0&&b!=0)
  { if(a<b)
  {t=a;a=b;b=t;}
    while(b!=0)
	{t=a%b;a=b;b=t;}
  }
   c=(denominator*(m.denominator))/a;
   molecule=molecule*(c/denominator);
   m.molecule=m.molecule*(c/m.denominator);
   denominator=m.denominator=c;
}
void fraction::reduct()
{int a,b,t;
  a=molecule;
  b=denominator;
  if(a!=0&&b!=0)
  { if(a<b)
  {t=a;a=b;b=t;}
    while(b!=0)
	{t=a%b;a=b;b=t;}
  }
   molecule=molecule/a;
   denominator=denominator/a;
}
fraction fraction::operator +(fraction& m)
{
  //(*this).molecule=molecule;学妹这里的molecule就是this->molecule他们两个是相等的. 
  //(*this).denominator=denominator;
  if((*this).denominator!=m.denominator)
	  (*this).common(m);
       (*this).molecule=(*this).molecule+m.molecule;
	   (*this).denominator=m.denominator;
	   (*this).reduct();
       return (*this);
		
}
fraction fraction::operator -(fraction& m)
{ 
  //(*this).molecule=molecule;
  //(*this).denominator=denominator;
  if((*this).denominator!=m.denominator)
      (*this).common(m);
      (*this).molecule=(*this).molecule-m.molecule;
      (*this).denominator=m.denominator;
	  (*this).reduct();
  
       return (*this);
 }
fraction fraction::operator *(fraction& m)
{
 if(denominator!=0&&m.denominator!=0)
 {
 	(*this).molecule=molecule*m.molecule;
  (*this).denominator=denominator*m.denominator;
  (*this).reduct();
  return (*this);
 }
 
}
fraction fraction::operator /(fraction& m)
{ 
  if(m.denominator==0)
     cout<<"erro!"<<endl;
  else
  { (*this).molecule=(*this).molecule*m.denominator;
     (*this).denominator=(*this).denominator*m.molecule;
	 (*this).reduct();
  }
  return (*this);  
}
void fraction::disply()
{ cout<<molecule<<"/"<<denominator<<endl; 
}
main()//因为在函数中使用的是*this所以每一次进行函数运算的时候x1都已经发生了变化. 
{fraction x1(1,2),x2(1,4),x3;
 cout<<"x1 is";
 x1.disply();
 cout<<"x2 is";
 x2.disply();
 x3=x1+(x2);
 cout<<"x1+x2=";
 x3.disply();
 x1.set(1,2);
 x3=x1-(x2);
 cout<<"x1-x2=";
 x3.disply();
 x1.set(1,2);
 x3=x1*(x2);
 cout<<"x1*x2=";
 x3.disply();
 x1.set(1,2);
 x3=x1/(x2);
 cout<<"x1/x2=";
 x3.disply();
}
