// wwww.cpp : Defines the entry point for the console application.
//

// pro1.cpp : Defines the entry point for the console application.
//
//ѧ�ã�������Բ��õ� 
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
      //ͨ�� 
      //void common(fraction m);
      //������ΪҪ��m��ֵҲһͬ�ı䣬���Կ���ʹ��ָ�룬Ҳ����ʹ�����á� 
      void common(fraction &m);
      //Լ�� 
      void reduct();
      //��ʾ 
	  void disply();
 private:
	   int molecule;//���� 
	   int denominator;//��ĸ
	   //����ѧ���е�ʱ��Ҳ����ҪһЩע�͵ģ������ڶ࣬ 
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
  	//����ط�Ϊ�˿��ø������������д����Ȼѧ������дҲ�ǶԵģ�
	a=this->denominator; 
  	b=m.denominator;
  	//����ʹ��շת��������Լ��a�ǹ�Լ��.
	//��Ȼ��Լ���п�����0
	//��С������Ϊ����֮���������Լ��. 
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
  	//����Ҫע�⾫������ 
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
	/*ѧ�ã������Ѿ���thisҲ����x1��ֵ���ı��ˣ����Բ�Ҫ����д. 
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
 	//ѧ��ֱ��дx3=x1+x2;�Ϳ�����
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
