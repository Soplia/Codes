#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float a,b,c;
	cout<<"������÷��̵�ϵ��:(a,b,c)\n"<<endl;
	cin>>a>>b>>c;
	//�жϷ�ĸ�Ƿ�Ϊ�� 
	if(a==0)
		//�жϷ�ĸ�Ƿ�Ϊ�� 
		if(b!=0)
			cout<<"�÷��̵Ľ���:"<<-c/b<<endl;
		else
			cout<<"������һ����ȷ������!"<<endl;
	else
	{
		float temp=b*b-4*a*c;
		if(temp<0)
			cout<<"�÷���û�н�!\n";
		else if(temp==0)
		{
			cout<<"�÷��̵Ľ���ͬ����:"<<(-b)/2/a<<endl;
		}
		else
		{
			cout<<"�÷�������������Ľ�:\n";
			cout<<((-b)+sqrt(temp))/2/a<<"   "<<((-b)-sqrt(temp))/2/a<<endl;
		}
	}
	return 0;
}
