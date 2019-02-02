#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float a,b,c;
	cout<<"请输入该方程的系数:(a,b,c)\n"<<endl;
	cin>>a>>b>>c;
	//判断分母是否为零 
	if(a==0)
		//判断分母是否为零 
		if(b!=0)
			cout<<"该方程的解是:"<<-c/b<<endl;
		else
			cout<<"请输入一组正确的数据!"<<endl;
	else
	{
		float temp=b*b-4*a*c;
		if(temp<0)
			cout<<"该方程没有解!\n";
		else if(temp==0)
		{
			cout<<"该方程的解相同都是:"<<(-b)/2/a<<endl;
		}
		else
		{
			cout<<"该方程有两个相异的解:\n";
			cout<<((-b)+sqrt(temp))/2/a<<"   "<<((-b)-sqrt(temp))/2/a<<endl;
		}
	}
	return 0;
}
