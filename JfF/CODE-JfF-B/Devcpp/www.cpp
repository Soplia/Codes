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
	   //通过这个函数来获得最大公约数 
	   int get(int a,int b);
private:
	   int molecule;
	   int denominator;

//}这个地方是要加分号的啊. 
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
//第二个 
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
//第一个错误 
void fraction::common(fraction m)
{ 
	//int a,b t, c;
	int a,b,t,c;
	//这里同分应该传分母吧 
	//a=molecule;            
	//b=m.molecule;   
	a=denominator;
	b=m.denominator; 
	// 这里需要加上这个条件 
	if(m.denominator!=0&&this->denominator!=0)
	{
	   /*这里的辗转相除法有问题   
	if(a<b)              
	   {  t=a;	   a=b;	   b=t;	}
	   b=a%b;
	while(b!=0)             
	{    a=b;	   b=a%b;	}  */   
	
	
    c=molecule*m.molecule/get(a,b);    
	
    //molecule=molecule*(c/denominator);
    	molecule=molecule*(c/denominator);
    	//这里少了个分号 
	m.molecule=m.molecule*(c/m.denominator);
	denominator=c;
	m.denominator=c;
	}	           
}
//这里少了 东西了
 
void fraction::reduct()
{  
	int a, b, t;
	a=molecule;           
	b=denominator;           
	//加上这个条件
	if(this->denominator!=0&&this->molecule!=0)
	{
		
	/*这里的辗转相除有问题 
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
   //学妹要注意细节 
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
//这里应该是m.吧 
   //c.molecule=molecule*b.molecule;
   c.molecule=molecule*m.molecule;
   c.denominator=denominator*m.denominator;
   
   if(c.denominator!=0)  
   	c.reduct();
   return c;
 
}
//注意这里的fraction_number 不是一个类 
//fraction fraction_number::divide(fraction m)
fraction fraction::divide(fraction m)
{ fraction c;
  //if(m.denoination=0)注意细节 
  if(m.denominator==0)
	  cout<<"erro!"<<endl;
  else//这个地方要有括号啊 
  //c.molecule=melecule*(m.denominator);注意细节 
 {
  c.molecule=molecule*(m.denominator);
  c.denominator=denominator*(m.molecule);
	  if(c.denominator!=0)
		 c.reduct();}
	  return c;
}
//fraction fraction::disply()注意函数返回值
//分子和分母倒颠了. 
void fraction::disply() 
{  
	if(denominator!=0)//这个地方是不是该加一个大括号啊 
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
//另外学妹，这个类的数据成员全都是int 类型的这样不好
//我觉得应该改为float类型的。 
int main()
{  
	//这个地方使用指针是我的习惯，当然学妹也可以在改过来。 
	fraction *fraction1=new fraction(1,2);
	fraction *fraction2=new fraction(1,2);
   fraction2->disply();
   cout<<endl<<endl;
   //这里之所以会有问题是因为辗转相除写错了 
   //还有就是因为addition等四个函数都有返回值所以要进行相应的赋值操作. 
   *fraction1=fraction1->addition(*fraction2);
   fraction1->disply();
  	*fraction1->subtract(*fraction2);
  	*fraction1->multiply(*fraction2);
   *fraction1->divide(*fraction2);
   
   return 0;
}

