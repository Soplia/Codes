/*
	Subject:多关键字排序 成绩、名字、年龄 ,使用运算符重载 
    Compiler:Devcpp
	Author:JiaruiXie
	Date:04/01/17 16:02
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct student
{
	char name[101];
	int age;
	float score;
	//注意这个地方使用的是引用，并且隐藏的哪一个没有使用this来进行引用 
	bool operator < (const struct student &x )const
	{
		int temp=strcmp(name,x.name);
		if(score!=x.score)
			return score<x.score;
		else if(temp!=0)
			return temp<0;
		return age<x.age;
	}
}Stu;

int main()
{
	int size;
	while(scanf("%d",&size)!=EOF)
	{
		Stu *p=(Stu *)malloc(size*sizeof(Stu));
		for(int i=0;i<size;i++)
		{
			scanf("%s",p[i].name);
			cin>>p[i].age;
			cin>>p[i].score;
		}
		sort(p,p+size);
		for(int i=0;i<size;i++)
			cout<<p[i].name<<" "<<p[i].age<<" "<<p[i].score<<endl;
		cout<<endl;
	}
}

