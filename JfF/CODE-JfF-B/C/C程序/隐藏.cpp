#include <iostream>
using namespace std;

class Base
{
 public:
 	virtual void O_Int(int a)
 	{
 		cout<<"Base::Output "<<a<<endl;
	 }
	 void O_Float(float a)
	 {
	 	cout<<"Base::Output "<<a<<endl;
	 }
 	virtual void v_Func(float a)
 	{
 		cout<<"Base::v_Func"<<a<<endl;
	 }
};

class Derived:public Base
{
 public:
 	virtual void O_Int(int a)
 	{
 		cout<<"Derived::Output "<<a<<endl;
	 }
	 void O_Float(float a)
	 {
	 	cout<<"Derived::Output "<<a<<endl;
	 }
 	virtual void v_Func(int a)
 	{
 		cout<<"Derived::v_Func"<<a<<endl;
	 }
 	
};

int main()
{
	Derived d;
	Base *pb=&d;
	Derived *pd=&d;
	pb->O_Float(1.2f);
	pd->O_Float(1.2f);
	cout<<endl<<endl;
	pb->O_Int(3);
	pd->O_Int(3);
	cout<<endl<<endl;
	pb->v_Func(1.2f);
	pd->v_Func(3);
	return 0;
}
