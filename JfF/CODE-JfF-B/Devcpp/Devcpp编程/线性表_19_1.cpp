/*
	Name: ���Ա��˳��ʵ�� 
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
		cout<<"���Ա�Ϊ��!"<<endl;
	else
		for(position i=0;i<L.last;i++)
			cout<<"��"<<i+1<<"��Ԫ����:"<<L.elements[i]<<endl;
}

//���Ƚ���У�飬Ȼ���ٽ��в��� 
void  Insert(Elementtype e,position p,LIST &L)
{
	if(L.last>=maxLength-1)
		cout<<"���Ա�����!"<<endl; 
	else if(p>L.last+1||p<1)
		cout<<"����λ�÷Ƿ�!"<<endl;
	else
	{
		position q;
		for(q=L.last;q>=p;q--)
			L.elements[q]=L.elements[q+1];
		L.elements[q]=e;
		L.last+=1;
		cout<<"�ɹ�����Ԫ��!"<<endl;
	} 	
}

//���Ƚ���У��Ȼ����ɾ�� 
void Delete(position p,LIST &L)
{
	if(p>L.last||p<1)
		cout<<"ɾ��λ�÷Ƿ�!"<<endl;
	else
	{
		L.last-=1;
		Elementtype e=L.elements[p];
		for(position q=p;q<=L.last;q++)//����ط��ڵ��Ե�ʱ����Ҫע���Ƿ���<= 
			L.elements[q]=L.elements[q+1];
		cout<<"�ɹ�ɾ��Ԫ�أ�"+e<<endl;	
	}
}

//�����Ա���˳��Ѱ��Ԫ�� 
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
		cout<<"λ�ò��Ϸ�"<<endl;
		return -1;
	}
	else
		return p-1;
} 

Elementtype Retrive(position p,LIST &L)
{
	if(p>L.last||p<0)
 	{
 		cout<<"��λ�ò��Ϸ�!"<<endl;
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


















