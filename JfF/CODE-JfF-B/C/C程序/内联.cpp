//错误 
inline void Foo(int a,int b);
//正确 
void Foo(int a,int b);
inline void Foo(int a,int b)
{
	
}
//内联，不提倡 
class A
{
 public :
 	void Foo(int a)
 	{
	 }
};
//内联，提倡 
class A
{
 public :
 	void Foo(int a);
}
inline void A::Foo(int a)
{
}
