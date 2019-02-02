#include <iostream>
using namespace std;

class Base
{
 public:
 	void Output(int a)
 	{
 		cout<<"Base::Output "<<a<<endl;
	 }
	 void Output(float a)
	 {
	 	cout<<"Base::Output "<<a<<endl;
	 }
 	virtual void v_Func(void)
 	{
 		cout<<"Base::v_Func"<<endl;
	 }
};

class Derived:public Base
{
 public:
 	void v_Func(void)
 	{
 		cout<<"Derived::v_Func"<<endl;
	 }
};

int main()
{
	Derived d;
	Base *p=&d;
	p->Output(1.5f);
	p->Output(43);
	p->v_Func();
	return 0;
}
