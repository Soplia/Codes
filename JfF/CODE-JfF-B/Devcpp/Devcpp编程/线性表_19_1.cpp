/*
	Name: 线性表的顺序实现 
	Complier:Devcpp 
	Author:  
	Date: 19/07/16 18:54
	Description: 
*/

#include <iostream>
using namespace std;

#define maxLength 100
typedef int position;
typedef int Elementtype;

struct LIST
{
	Elementtype elements [maxLength];
	int last;		
};

void print(LIST &L)
{
	if(L.last==0)
		cout<<"线性表为空!"<<endl;
	else
		for(position i=0;i<L.last;i++)
			cout<<"第"<<i+1<<"个元素是:"<<L.elements[i]<<endl;
}

//首先进行校验，然后再进行插入 
void  Insert(Elementtype e,position p,LIST &L)
{
	if(L.last>=maxLength-1)
		cout<<"线性表已满!"<<endl; 
	else if(p>L.last+1||p<1)
		cout<<"插入位置非法!"<<endl;
	else
	{
		position q;
		for(q=L.last;q>=p;q--)
			L.elements[q]=L.elements[q+1];
		L.elements[q]=e;
		L.last+=1;
		cout<<"成功插入元素!"<<endl;
	} 	
}

//首先进行校验然后再删除 
void Delete(position p,LIST &L)
{
	if(p>L.last||p<1)
		cout<<"删除位置非法!"<<endl;
	else
	{
		L.last-=1;
		Elementtype e=L.elements[p];
		for(position q=p;q<=L.last;q++)//这个地方在调试的时候需要注意是否是<= 
			L.elements[q]=L.elements[q+1];
		cout<<"成功删除元素："+e<<endl;	
	}
}

//在线性表中顺序寻找元素 
position Locate(Elementtype e,LIST &L)
{
	for(position p=1;p<=L.last;p++)
		if(L.elements[p]==e)
			return p;
	return L.last+1;
}

position First()
{
	return 0;
} 

void MakeNull(LIST &L)
{
	L.last=0; 
}

position previous(position p,LIST L)
{
	if(p>L.last||p<1)
	{
		cout<<"位置不合法"<<endl;
		return -1;
	}
	else
		return p-1;
} 

Elementtype Retrive(position p,LIST &L)
{
	if(p>L.last||p<0)
 	{
 		cout<<"该位置不合法!"<<endl;
 	}
 	else
 		return L.elements[p];
}
int main()
{
	LIST f;
	f.last=0;
	print(f);
	Insert(1,1,f);
	print(f);
	return 0;
}


















