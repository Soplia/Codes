/*
	Name: ����ʶ��ϵͳ 
	Complier: Devcpp 
	Author: JiaruiXie
	Date: 19/11/15 14:19
	Description: ����⣬�ۺ����ݿ⣬����ϵͳ
					���飬�����ṹ�壬ȫ�ֱ������ļ���д�� 
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;
//����ܵ����Ŷ�
float zhixindu; 
//Ϊ�ڵ���ʹ��
int nodeNum=0; 
//����ܹ��ж��ٸ��ڵ�.��¼���ļ���ʱ����Ѿ�������ˡ� 
static int numOfPre=0;
//���һ��ʹ���˶��ٹ��� 
static int numOfEnd=0;
//����������Ǹ����� 
string result="";
//��ֹ���Ｏ�� 
string end[]={"��Ǯ��","�ϻ�","����¹","����","������","����","���"};
//��Ź�����ŶȵĽṹ��
typedef struct nodeOfCre
{
	int num;
	float cre;
	struct nodeOfCre *next;
}NodeC;
NodeC *createNode(int num,float a)
{
	NodeC *temp=new NodeC();
	temp->num=num;
	temp->cre=a;
	temp->next=NULL;
	return temp;
}
//����ڵ�ṹ�� 
typedef struct nodeOfArray
{
	int num;
	string firstIf;
	string secondIf;
	string thirdIf;
	string forthIf;
	string fifthIf;
	string conclusion;
	bool used;
	struct nodeOfArray *next;
}NodeA;
NodeA *headA=NULL;
//�ۺ����ݿ�ṹ�� 
typedef struct nodeOfList
{
	string type;
	struct nodeOfList *next;
}NodeL;
NodeL *headL=NULL;

NodeL *createNode(string str)
{
	NodeL *temp=new NodeL();
	temp->type=str;
	temp->next=NULL;
	return temp;
}
//���ջ���Ҫͨ���ַ������нڵ�Ĳ��롣 
void create(string s)
{
	NodeL *p;
	NodeL *temp=createNode(s);
	if(headL==NULL)
		headL=temp;
	else
	{
		p=headL;
		while(p->next!=NULL)
			p=p->next;
		p->next=temp;
	}
}
void outputList()
{
	NodeL *temp;
	if(headL!=NULL)
	{
		temp=headL;
		while(temp!=NULL)
		{
			cout<<temp->type<<endl;
			temp=temp->next;
		}
	}
	else
		cout<<"THE LIST IS EMPTY!"<<endl;
}
NodeA* createNode(string *str)
{
	NodeA *temp=new NodeA();
	temp->num=++nodeNum;
	temp->firstIf=str[0];
	temp->secondIf=str[1];
	temp->thirdIf=str[2];
	temp->forthIf=str[3];
	temp->fifthIf=str[4];
	temp->conclusion=str[5];
	temp->used=false;
	temp->next=NULL;
	return temp;
}
void create(string *str)
{
	NodeA *q;
	NodeA *temp=createNode(str);
	if(headA==NULL)
		headA=temp;
	else
	{
		q=headA;
		while(q->next!=NULL)
			q=q->next;
		q->next=temp;
	}
}
void outputArray()
{
	if(headA==NULL)
		cout<<"THE ARRAY IS NULL !"<<endl;
	else
	{
		NodeA *temp=headA;
		while(temp!=NULL)
		{
			cout<<temp->num<<"   ";
			cout<<temp->firstIf<<"   ";
			cout<<temp->secondIf<<"   ";
			cout<<temp->thirdIf<<"   ";
			cout<<temp->forthIf<<"   ";
			cout<<temp->fifthIf<<"   ";
			cout<<temp->conclusion<<"   ";
			if(temp->used)
				cout<<"�Ѿ�ʹ��"<<endl;
			else
				cout<<"δʹ��"<<endl;
			temp=temp->next;
		}
	}
}
void outputNode(NodeA *temp)
{
	cout<<temp->firstIf<<"   ";
	cout<<temp->secondIf<<"   ";
	cout<<temp->thirdIf<<"   ";
	cout<<temp->forthIf<<"   ";
	cout<<temp->fifthIf<<"   ";
	cout<<temp->conclusion<<endl;
}
//�ҳ�һ��������ʵ�ʵĴ�����
int findNum(NodeA *t)
{
	int num=0;
	if(t->firstIf!="0")
		num++;
	if(t->secondIf!="0")
		num++;
	if(t->thirdIf!="0")
		num++;
	if(t->forthIf!="0")
		num++;
	if(t->fifthIf!="0")
		num++;
	return num;
} 
//��������д��Ľ� 
//������ǰ�ۺ����ݿ�����û����ֹ���Ｏ���еĶ��� 
string isMatch(NodeL *head)
{
	NodeL *temp=head; 
	while(temp!=NULL)
	{
		for(int i=0;i<7;i++)
			if(temp->type==end[i])
				return temp->type;
		temp=temp->next;
	}
	return "";
}
//���str�ַ����Ƿ���ĳ��֪ĳһ����ʵ��ͬ�� 
bool isMatch(string str)
{
	bool flag=false;
	NodeL *temp=headL;
	//��Ϊ����ط�Ĭ���Ƿ���true��ôÿ����������������� 
	if(str=="0")
		return !flag;
	while(temp!=NULL)
	{
		//ֻҪ��һ����ȵľ����ˡ� 
		if(str==temp->type)
		{ 
			flag=true;
			break;
		}
		temp=temp->next;
	}
	return flag;
}
//�ж��Ƿ�Ӧ�ý��� 
string isEnd(NodeL *head)
{
	string str=isMatch(head);
	if(str!="")
		return str;
	else if(numOfEnd==numOfPre)
		return "end";
	else
		return "";
}

void writeToFile()
{
	ofstream out("result.txt");
	if(out.fail())
	{
		cerr<<"OPEN FILE FAIL��"<<endl;
		exit(0); 
	}
	out<<result<<"  "<<zhixindu<<endl;
	out.close();
}
void readFromFile()
{	
	ifstream in("rule.txt");
	if(in.fail())
	{
		cerr<<"OPEN THE FILE FAIL!";
		exit(0);
	}	
	string str[6],word;
	int num=0;
	while((in>>word))
	{
		num++;
		str[(num-1)%6]=word;
		if(num%6==0)
		{
			numOfPre++;
			create(str);
		}	
	}	
	in.close();
}
//�ҵ��ڵ���Ϊx�Ľڵ�
void modify(int num)
{
	NodeA *temp=headA;
	while(temp!=NULL)
	{
		if(temp->num==num)
		{
			temp->used=true;
			create(temp->conclusion);
			//��ʾ�õ��Ĺ���
			outputNode(temp); 
			//����ط����������⣬�ᵼ����ѭ����
			break;
		}
		temp=temp->next;
	}
}
void display(NodeC *a)
{
	NodeC* b=a;
	while(a!=NULL)
	{
		cout<<a->num<<"  "<<a->cre<<endl;
		a=a->next;
	}
}
//�ҵ����������Ŷ���ߵĽڵ�ı��. 
NodeC *getMostCre(NodeC *temp)
{
	int i=0;
	float j=-3.0;
	NodeC *a=temp;
	NodeA *b;
	while(a!=NULL)
	{
		if(a->cre>j)
		{
			b=headA;
			//�ҵ���������ʵ��ͬ���ҿ��Ŷ����Ĺ��� 
			while(b!=NULL)
			{
				if(b->num==a->num)
					break;
				b=b->next;
			}
			if(!isMatch(b->conclusion))
			{
				i=a->num;
				j=a->cre;
			}
		}
		a=a->next;
	}
	return createNode(i,j);
}

void findAnimal()
{
	int num=0;//��¼ÿ�������ڲ�ƥ��Ĵ����� 
	cout<<"�õ��Ĺ�����:"<<endl; 
	bool flag=true;
	NodeA *temp=headA;
	//���ڷ���ÿ������ȫƥ��Ĺ�������Ŷ� 
	NodeC *headC=NULL;
	zhixindu=1.0;
	while(true)
	{
		num=0;
		//ÿ�ζ���flag����һ��.���ܻ������⡣ 
		flag=true;
		//����������û�б�ʹ�ã�����û�б�ʹ�õ���˼��
		//û��ͨ��������򵼳�ʲô���ۣ�
		if(!temp->used)
		{
			if(!isMatch(temp->firstIf))
			{
				flag=false;
				num++;
			}
			if(!isMatch(temp->secondIf))
			{
				flag=false;
				num++;
			}
			if(!isMatch(temp->thirdIf))
			{
				flag=false;
				num++;
			}
			if(!isMatch(temp->forthIf))
			{
				flag=false;
				num++;
			}
			if(!isMatch(temp->fifthIf))
			{
				flag=false;
				num++;
			}
			//���ĳ����������ʵ��ȫƥ�䣬�Ͱ������Ϊʹ��
			//���Ұѽ��۲鵽���ݿ��У���ӡ��ǰ�Ĺ��� 
			//numOfEnd++ 
			if(flag)
			{
				temp->used=true;
				create(temp->conclusion);
				//��ʾ�õ��Ĺ���
				outputNode(temp); 
				//����ط����������⣬�ᵼ����ѭ���� 
				numOfEnd++;
				//ÿ�β��뵽�ۺ����ݿ����ݺ�Ҫ�����µ��ж�
				result=isEnd(headL);
				if(result!="")
				{
					if(result=="end")
						result="�޷��ж�";
					cout<<endl<<"���Ŷ�="<<zhixindu<<endl;
					writeToFile();
					break;
				}else{
				}
			}
			//����ۺ����ݿ������е����ݲ�������ȫƥ��ù���
			//��ô������Ŷȣ����Ѹù������źͿ��ŶȲ��뵽�����С� 
			else 
			{
				//���������ŶȻ�����һ��. 
				int zhenshijiedianshu=findNum(temp);
				int zhenshipipeishu=zhenshijiedianshu-num;
				float c=(float)zhenshipipeishu/zhenshijiedianshu;
				NodeC *t=createNode(temp->num,c);
				//������ڵ���뵽�����С� 
				if(headC==NULL)
					headC=t;
				else
				{
					NodeC *a=headC;
					while(a->next!=NULL)
					 	a=a->next;
					a->next=t;
				}
			}
		}	
		temp=temp->next;
		//ѭ���ƶ� ���headC��Ϊ�գ���ô�����ҵ�һ�����Ŷ���ߵĽ��в��� 
		//��ʱ���Ѿ�����ɵ�һ��ı����ˣ��������û���ҵ��Ļ�ֻ����
		//��һ�����Ŷ����Ľ��в����ˡ� 
		if(temp==NULL)
		{
			if(headC!=NULL)
			{
				NodeC *b=getMostCre(headC);//�ҵ�������Ŷȵı��
				//�޸Ĺ�������. 
				modify(b->num); 
				numOfEnd++;
				zhixindu*=b->cre;
				//ÿ����һ�Σ��Ͱ�������Ŷȵ��������. 
				headC=NULL;
				result=isEnd(headL);
				if(result!="")
				{
					if(result=="end")
						result="�޷��ж�";
					cout<<endl<<"���Ŷ�="<<zhixindu<<endl;
					writeToFile();
					break;
				}	
			}
			//�ٴ�ͷ��ʼ�� 
			temp=headA;
		}
	}
}
int main()
{
	string str[]={"ë��","�ƺ�ɫ","Ȯ��","��צ","�۶�ǰ��","���ߵ�"}; 
	//string str[]={"����","����","�ƺ�ɫ","��ɫ����"};
	//string str[]={"����","����","����","������","���ߵ�"};
	//string str[]={"����","��ɫ����","����"};
	//string str[]={"�µ�","���","������","����"}; 
	//string str[]={"��ë", "��Ӿ", "�ڰ׶�ɫ", "����"};
	//string str[]={"�µ�","���","�Ʒ�"};
	//ע���������ط���iֵ����������str�е�ֵ�ø���һ�¡� 
	for(int i=0;i<6;i++)
		create(str[i]);
	readFromFile();
	findAnimal();
	cout<<"�ö�����:"+result<<endl;
	return 0;
}
























