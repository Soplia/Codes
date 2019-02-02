// wwww.cpp : Defines the entry point for the console application.
//

// pro1.cpp : Defines the entry point for the console application.
//
//学妹，这个可以不用的 
//#include "stdafx.h"
#include<iostream>
using namespace std;
class fraction
{  
 public:
      fraction();
      fraction(int a);
      fraction(int a,int b);
      fraction operator +(fraction& m);
      fraction operator -(fraction& m);
      fraction operator *(fraction& m);
      fraction operator /(fraction& m);
      //通分 
      //void common(fraction m);
      //这里因为要将m的值也一同改变，所以可以使用指针，也可以使用引用。 
      void common(fraction &m);
      //约分 
      void reduct();
      //显示 
	  void disply();
 private:
	   int molecule;//分子 
	   int denominator;//分母
	   //但是学妹有的时候也是需要一些注释的，不在于多， 
};
fraction::fraction()
{ 
	molecule=0;
  	denominator=1;
}
fraction::fraction(int a)
{ 
	molecule=a;
  	denominator=1;
}
fraction::fraction(int a,int b)
{ 
	molecule=a;
  	denominator=b;
}
//void fraction::common(fraction m)
void fraction::common(fraction &m)
{
	int a,b,c,t;
  	//a=denominator;
  	//这个地方为了看得更清楚可以这样写（当然学妹那样写也是对的）
	a=this->denominator; 
  	b=m.denominator;
  	//这里使用辗转相除得最大公约数a是公约数.
	//当然公约数有可能是0
	//最小公倍数为两数之积除以最大公约数. 
  	if(a!=0&&b!=0)
  	{ 
	  	if(a<b)
  		{
		  t=a;
		  a=b;
		  b=t;
		}
    	while(b!=0)
		{
			t=a%b;
			a=b;
			b=t;
		}
  	}
  	//这里要注意精度问题 
   	c=(denominator*(m.denominator))/a;
   	molecule=molecule*(c/denominator);
   	m.molecule=m.molecule*(c/m.denominator);
   	denominator=m.denominator=c;
}
void fraction::reduct()
{
	int a,b,t;
  	a=molecule;
  	b=denominator;
  	if(a!=0&&b!=0)
  	{ 
		if(a<b)
  	  	{
	  	  	t=a;
		  	a=b;
		  	b=t;
	  	}
        while(b!=0)
		{
			t=a%b;
			a=b;
			b=t;
		}
  	}
   molecule=molecule/a;
   denominator=denominator/a;
}
fraction fraction::operator +(fraction& m)
{ 
	fraction t;
  	t.molecule=molecule;
  	t.denominator=denominator;
  	if(t.denominator!=m.denominator)
	  	t.common(m);
	/*学妹，这里已经把this也就是x1的值给改变了，所以不要这样写. 
    (*this).molecule=(t.molecule)+(m.molecule);
    (*this).denominator=t.denominator;
    (*this).reduct();
    //this->disply();
    */
    t.molecule+=m.molecule;
    return t;
}
//fraction fraction::operator -(fraction& m)
fraction fraction::operator -(fraction &m)
{ 
	fraction t;
  	t.molecule=molecule;
  	t.denominator=denominator;
  	if(t.denominator!=m.denominator)
	  	t.common(m);
	/*
    (*this).molecule=t.molecule-m.molecule;
    (*this).denominator=t.denominator;
    (*this).reduct();
	return (*this); 
	*/
	t.molecule-=m.molecule;
    return t;
 }
fraction fraction::operator *(fraction& m)
{
	/*
	(*this).molecule=molecule*m.molecule;
 	(*this).denominator=denominator*m.denominator;
 	if((*this).denominator!=0)
	 	(*this).reduct();
 	return (*this);
	*/
	fraction *t=new fraction(this->molecule,this->denominator);
	t->molecule*=m.molecule;
	t->denominator*=m.denominator;
	if(t->denominator!=0)
		t->reduct();
	return *t;
}
fraction fraction::operator /(fraction& m)
{ 
	//if(m.denominator==0)
     	//cout<<"erro!"<<endl;
    if(m.denominator==0)
    {
    	cout<<"erro!"<<endl;
    	return NULL;
    }
     	
   /* 
  else
	  (*this).molecule=molecule*(m.denominator);
      (*this).denominator=denominator*(m.molecule);
	  if((*this).denominator!=0)
		  (*this).reduct();
          return (*this);
        */
    else
    {
    	fraction *t=new fraction(this->molecule,this->denominator);
		t->molecule*=m.denominator;
		t->denominator*=m.molecule;
		if(t->denominator!=0)
			t->reduct();
		return *t;
    	/*
	  	(*this).molecule=molecule*(m.denominator);
      	(*this).denominator=denominator*(m.molecule);
	  	if((*this).denominator!=0)
		  	(*this).reduct();
        return (*this);*/
        
    }
}
void fraction::disply()
{ 
	cout<<molecule<<"/"<<denominator<<endl<<endl; 
}
int main()
{
	fraction x1(1,2),x2(1,3),x3;
	cout<<"x3 is:"; 
	x3.disply();
	cout<<"x1 is:";
 	x1.disply();
 	cout<<"x2 is:";
 	x2.disply();
 	//学妹直接写x3=x1+x2;就可以了
 	x3=x1+(x2);
 	cout<<"x1+x2=";
 	x3.disply();
 	x3=x1-(x2);
 	cout<<"x1-x2=";
 	x3.disply();
 	x3=x1*(x2);
 	cout<<"x1*x2=";
 	x3.disply();
 	x3=x1/(x2);
 	cout<<"x1/x2=";
 	x3.disply();
 	return 0;
}
