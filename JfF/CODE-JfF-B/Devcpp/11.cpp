// 11.cpp : Defines the entry point for the console application.
//
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
	   //void common(fraction m);
	   //这里应该使用应用的方式来调用函数 
	   void common(fraction &m);
	   void reduct();
	   void disply();
 private:
	   int molecule;
	   int denominator;
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
//void fraction::common( fraction m)
void fraction::common(fraction &m)
{ 
	int a,b,t,c;
	//a=molecule;            
	//b=m.molecule;  学妹通分错了
	a=denominator;
	b=m.denominator;         
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
    //c=molecule*m.molecule/a;  学妹注意这里 
	c=denominator*m.denominator/a;           
    molecule=molecule*(c/denominator);
	m.molecule=m.molecule*(c/m.denominator);
	denominator=m.denominator=c;	           
}
void fraction::reduct()
{ 
	int a, b, t;
	a=molecule;           
	b=denominator;           
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
	molecule=molecule/a;                
    denominator=denominator/a;         
}
fraction fraction::addition(fraction m)
{ 
	fraction c, t;
   	t.molecule=molecule;   
   	t.denominator=denominator;
   	if(t.denominator!=m.denominator)
      	t.common(m); 
   	c.molecule=t.molecule+m.molecule;
   	c.denominator=t.denominator;
   	if(c.denominator!=0)
   		c.reduct();  
   	return c;
}
fraction fraction::subtract(fraction m)
{ 
	fraction c, t;
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
{  
	fraction c;
   	c.molecule=molecule*m.molecule;
   	c.denominator=denominator*m.denominator;
   	if(c.denominator!=0)  
		c.reduct();
   	return c;
 
}
fraction fraction::divide(fraction m)
{ 
	fraction c;
	
	/*
  	if(m.denominator=0)
	  	cout<<"erro!"<<endl;
  	else
      	c.molecule=molecule*(m.denominator);
      	c.denominator=denominator*(m.molecule);
	    if(c.denominator!=0)
		  	c.reduct();
	    return c;*/
	//if(m.denominator=0)学妹这个地方要注意啊 
	if(m.denominator==0)
	{
		cout<<"erro!"<<endl;
		return fraction(0);
	}
  	else
  	{
  		c.molecule=molecule*(m.denominator);
      	c.denominator=denominator*(m.molecule);
	    if(c.denominator!=0)
		  	c.reduct();
	    return c;
  	}    	
}
void fraction::disply()
{  
	if(denominator!=0)
   		cout<<molecule<<"/"<<denominator<<endl;
}
int main()
{  
	fraction fraction1(1,2),fraction2(1,3),fraction3;
   	cout<<"fraction1 is:";
   	fraction1.disply();
   	cout<<"fraction2 is:";
   	fraction2.disply();
   	fraction3=fraction1.addition(fraction2);
   	cout<<"fraction1+fraction2=";
   	fraction3.disply();
   	fraction3=fraction1.subtract(fraction2);
   	cout<<"fraction1-fraction2=";
   	fraction3.disply();
   	fraction3=fraction1.multiply(fraction2);
   	cout<<"fraction1*fraction2=";
   	fraction3.disply();
   	fraction3=fraction1.divide(fraction2);
   	cout<<"fraction1/fraction2=";
   	fraction3.disply();
   	return 0;
}

