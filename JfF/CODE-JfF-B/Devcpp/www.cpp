// 11.cpp : Defines the entry point for the console application.


//#include "stdafx.h"
//#include"fraction.h"
#include<iostream>
using namespace std;
class fraction
{
public:
	   fraction();
	   fraction(int a);
	   fraction(int a,int b);
	   fraction addition(fraction m);
	   fraction subtract(fraction m);
	   fraction multiply(fraction m);
	   fraction divide(fraction m);
	   void common(fraction m);
	   void reduct();
	   void disply();
	   //ͨ�����������������Լ�� 
	   int get(int a,int b);
private:
	   int molecule;
	   int denominator;

//}����ط���Ҫ�ӷֺŵİ�. 
};
int fraction::get(int a,int b)
{
	//cout<<a<<"  "<<b<<endl;
	if(a==0||b==0)
		return 0;
	while(a!=b)
	{
		if(a>b)
			a-=b;
		else
			b-=a;	
	}
	return a;
}
//�ڶ��� 
//fraction::fraction()
fraction::fraction()
{   
	molecule=0;
    denominator=1;
}
fraction::fraction(int a)
{   molecule=a;
    denominator=1;
}
fraction::fraction(int a,int b)
{   
	molecule=a;
    denominator=b;
}
//��һ������ 
void fraction::common(fraction m)
{ 
	//int a,b t, c;
	int a,b,t,c;
	//����ͬ��Ӧ�ô���ĸ�� 
	//a=molecule;            
	//b=m.molecule;   
	a=denominator;
	b=m.denominator; 
	// ������Ҫ����������� 
	if(m.denominator!=0&&this->denominator!=0)
	{
	   /*�����շת�����������   
	if(a<b)              
	   {  t=a;	   a=b;	   b=t;	}
	   b=a%b;
	while(b!=0)             
	{    a=b;	   b=a%b;	}  */   
	
	
    c=molecule*m.molecule/get(a,b);    
	
    //molecule=molecule*(c/denominator);
    	molecule=molecule*(c/denominator);
    	//�������˸��ֺ� 
	m.molecule=m.molecule*(c/m.denominator);
	denominator=c;
	m.denominator=c;
	}	           
}
//�������� ������
 
void fraction::reduct()
{  
	int a, b, t;
	a=molecule;           
	b=denominator;           
	//�����������
	if(this->denominator!=0&&this->molecule!=0)
	{
		
	/*�����շת��������� 
	if(a<b) {  t=a;   a=b;   b=t;	}      
	
	while(b!=0)               
	{ 	   a=b;   b=a%b;   }      
	*/ 
	molecule=molecule/get(a,b);                
    denominator=denominator/b;          
	}
}
fraction fraction::addition(fraction m)
{ 
	fraction *c=new fraction();
	fraction *t=new fraction();
    t->molecule=molecule;   
   //ѧ��Ҫע��ϸ�� 
   //t.denomonator=denominator;
   t->denominator=denominator;
   
   if(t->denominator!=m.denominator)
      t->common(m); 
   c->molecule=t->molecule+m.molecule;
   c->denominator=t->denominator;
   		c->reduct();     
   return *c;

}
fraction fraction::subtract(fraction m)
{ fraction c, t;
   t.molecule=molecule;   
   t.denominator=denominator;
   if(t.denominator!=m.denominator)
      t.common(m); 
   c.molecule=t.molecule-m.molecule;
   c.denominator=t.denominator;
   if(c.denominator!=0)
   c.reduct();     
   return c;
}

fraction fraction::multiply(fraction m)
{  fraction c;
//����Ӧ����m.�� 
   //c.molecule=molecule*b.molecule;
   c.molecule=molecule*m.molecule;
   c.denominator=denominator*m.denominator;
   
   if(c.denominator!=0)  
   	c.reduct();
   return c;
 
}
//ע�������fraction_number ����һ���� 
//fraction fraction_number::divide(fraction m)
fraction fraction::divide(fraction m)
{ fraction c;
  //if(m.denoination=0)ע��ϸ�� 
  if(m.denominator==0)
	  cout<<"erro!"<<endl;
  else//����ط�Ҫ�����Ű� 
  //c.molecule=melecule*(m.denominator);ע��ϸ�� 
 {
  c.molecule=molecule*(m.denominator);
  c.denominator=denominator*(m.molecule);
	  if(c.denominator!=0)
		 c.reduct();}
	  return c;
}
//fraction fraction::disply()ע�⺯������ֵ
//���Ӻͷ�ĸ������. 
void fraction::disply() 
{  
	if(denominator!=0)//����ط��ǲ��Ǹü�һ�������Ű� 
	/*{
	
	   cout<<"addtion is:"<<denominator<<"/"<<molecule<<endl;
	   cout<<"subtract is:"<<denominator<<"/"<<molecule<<endl;
	   
	   cout<<"multiply is:"<<denominator<<"/"<<molecule<<endl;
	   cout<<"divide is:"<<denominator<<"/"<<molecule<<endl;
	}*/
	{
		cout<<"addtion is:"<<molecule<<"/"<<denominator<<endl;
		cout<<"subtract is:"<<molecule<<"/"<<denominator<<endl;
		cout<<"multiply is:"<<molecule<<"/"<<denominator<<endl;
		cout<<"divide is:"<<molecule<<"/"<<denominator<<endl;
	}
}
//����ѧ�ã����������ݳ�Աȫ����int ���͵���������
//�Ҿ���Ӧ�ø�Ϊfloat���͵ġ� 
int main()
{  
	//����ط�ʹ��ָ�����ҵ�ϰ�ߣ���Ȼѧ��Ҳ�����ڸĹ����� 
	fraction *fraction1=new fraction(1,2);
	fraction *fraction2=new fraction(1,2);
   fraction2->disply();
   cout<<endl<<endl;
   //����֮���Ի�����������Ϊշת���д���� 
   //���о�����Ϊaddition���ĸ��������з���ֵ����Ҫ������Ӧ�ĸ�ֵ����. 
   *fraction1=fraction1->addition(*fraction2);
   fraction1->disply();
  	*fraction1->subtract(*fraction2);
  	*fraction1->multiply(*fraction2);
   *fraction1->divide(*fraction2);
   
   return 0;
}

