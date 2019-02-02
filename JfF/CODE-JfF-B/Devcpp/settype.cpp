
#include "settype.h"
//#include<iostream>
//using namespace std;

bool operator<(int x, settype A);    //重载运算符<, 注意该函数不是集合类中的成员函数，
//其函数功能是判断x是否属于集合A
istream& operator>>(istream &input, settype &A);     // 重载运算符>>
ostream& operator<<(ostream &output, settype &A);   // 重载运算符<<
//int main(int argc, char* argv[])
int main()
{
	settype A(5),B,C;
	//settype B,C;
	cout<<"输入集合A:\n";
	cin>>A;
	//settype *A=new settype(argc,argv);
    cout<<"输出集合A:\n";
	cout<<A;
	cout<<"输入集合B:\n";
	cin>>B;
    cout<<"输出集合B:\n";
	cout<<B;

	int x;
	cout<<"输入一个正整数x,判断x是否在集合A中\n";
	cin>>x;
	//if(x<A) 注意函数返回值 
	if(x<A)
		cout<<" x is in set A!\n";
	else  
		cout<<" x is not in set A!\n";
	
	cout<<"计算集合A和集合B的并集:\n";
	C=A+B;
	cout<<"A+B=";
	cout<<C;

	cout<<"计算集合A和集合B的交集:\n";
	C=A*B;
	cout<<"A*B=";
	cout<<C;

	cout<<"计算集合A和集合B的差集:\n";
	C=A-B;
	cout<<"A-B=";
	cout<<C;

	return 0;
}
