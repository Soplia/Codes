
#include "settype.h"
//#include<iostream>
//using namespace std;

bool operator<(int x, settype A);    //���������<, ע��ú������Ǽ������еĳ�Ա������
//�亯���������ж�x�Ƿ����ڼ���A
istream& operator>>(istream &input, settype &A);     // ���������>>
ostream& operator<<(ostream &output, settype &A);   // ���������<<
//int main(int argc, char* argv[])
int main()
{
	settype A(5),B,C;
	//settype B,C;
	cout<<"���뼯��A:\n";
	cin>>A;
	//settype *A=new settype(argc,argv);
    cout<<"�������A:\n";
	cout<<A;
	cout<<"���뼯��B:\n";
	cin>>B;
    cout<<"�������B:\n";
	cout<<B;

	int x;
	cout<<"����һ��������x,�ж�x�Ƿ��ڼ���A��\n";
	cin>>x;
	//if(x<A) ע�⺯������ֵ 
	if(x<A)
		cout<<" x is in set A!\n";
	else  
		cout<<" x is not in set A!\n";
	
	cout<<"���㼯��A�ͼ���B�Ĳ���:\n";
	C=A+B;
	cout<<"A+B=";
	cout<<C;

	cout<<"���㼯��A�ͼ���B�Ľ���:\n";
	C=A*B;
	cout<<"A*B=";
	cout<<C;

	cout<<"���㼯��A�ͼ���B�Ĳ:\n";
	C=A-B;
	cout<<"A-B=";
	cout<<C;

	return 0;
}
