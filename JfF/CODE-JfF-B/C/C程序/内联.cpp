//���� 
inline void Foo(int a,int b);
//��ȷ 
void Foo(int a,int b);
inline void Foo(int a,int b)
{
	
}
//���������ᳫ 
class A
{
 public :
 	void Foo(int a)
 	{
	 }
};
//�������ᳫ 
class A
{
 public :
 	void Foo(int a);
}
inline void A::Foo(int a)
{
}
