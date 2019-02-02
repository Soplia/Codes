// 12.cpp : Defines the entry point for the console application.
//
//这个头文件不用也可以 
//#include "stdafx.h"
#include<iostream>
using namespace std;
class time24
//学妹下次写的时候要注意格式 
{
 public:
	time24(int h=0,int m=0,int s=0);
    void get_time24(int& h,int& m,int& s)const;
    void set_time24(int h,int m,int s);
    time24 operator+(int sect)const;
    time24 operator+(const time24& t)const;
 private:
	int hours;
	int minutes;
	int seconds;
};
time24::time24(int h,int m,int s)
{
   hours=h;
   minutes=m;
   seconds=s;
}
void time24::get_time24(int& h,int& m,int& s)const
{   
	h=hours;
	m=minutes;
	s=seconds;
}
void time24::set_time24(int h,int m,int s)
{   
	hours=h;
	minutes=m;
	seconds=s;
}
time24 time24::operator+(int sect)const
{ 
	time24 temp;
  	temp.seconds=seconds+sect;
	temp.minutes=minutes+temp.seconds/60;
	temp.seconds=temp.seconds%60;
	temp.hours=hours+temp.minutes/60;
	temp.minutes=temp.minutes%60;
	temp.hours=temp.hours%24;
	return temp;
}
time24 time24::operator+(const time24& t)const
{ 
	time24 temp;
  	int secs=t.hours*3600+t.minutes*60+t.seconds;
  	temp.seconds=seconds+secs;
  	temp.minutes=minutes+temp.seconds/60;
  	temp.seconds=temp.seconds%60;
  	temp.hours=hours+temp.minutes/60;
  	temp.minutes=temp.minutes%60;
  	temp.hours=temp.hours%24;
  	return temp;
}
time24 operator+(int secs,const time24& t)
{ 
	time24 temp;
  	temp=t+secs;
  	return temp;
}
int main()
{  
	int h,m,s;
	//因为没有这样的构造函数 
   	//time24 t1(23.59,57);
   	time24 t1(23,59,57);
   	time24 t2;
   	t2=4+t1;
   	//这个也是因为没有相应的成员函数 
   	//t2.get_time(h,m,s);
   	t2.get_time24(h,m,s);
   	cout<<"Time t2 is"<<h<<":"<<m<<":"<<s<<endl;
   	return 0;
}




