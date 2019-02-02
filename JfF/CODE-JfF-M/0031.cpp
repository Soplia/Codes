#include <iostream>
using namespace std;

struct A 
{
    int var1;
    int var2;
};

void fun1(struct A &a);

int main()
{
    struct A a;
    a.var1 = 2;
    fun1(a);
	return 0 ;
}

void fun1(struct A &a) 
{
    printf("a is: %d\n", a.var1);
}
