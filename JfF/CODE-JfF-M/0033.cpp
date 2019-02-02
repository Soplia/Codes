#include <iostream>
using namespace std;

class A
{
 public:
 	A(int a);
 	void SetMem(int a);
 	void Dis();	
 	static int m_t;
};

void A::A()
{
	SetMem(a);
}

void A::Dis()
{
	cout << m_t;
}

void A::SetMem(int a)
{
	m_t = a;
}

int main()
{
	A *a = new A(10);
	a->Dis();
	A *b = new A(20);
	b->Dis(); 
	return 0;
}
