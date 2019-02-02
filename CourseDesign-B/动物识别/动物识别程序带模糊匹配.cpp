/*
	Name: 动物识别系统 
	Complier: Devcpp 
	Author: JiaruiXie
	Date: 19/11/15 14:19
	Description: 规则库，综合数据库，控制系统
					数组，链表，结构体，全局变量，文件读写。 
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;
//存放总的置信度
float zhixindu; 
//为节点编号使用
int nodeNum=0; 
//存放总共有多少个节点.在录入文件的时候就已经计算好了。 
static int numOfPre=0;
//存放一共使用了多少规则 
static int numOfEnd=0;
//存放最终是那个动物 
string result="";
//终止动物集合 
string end[]={"金钱豹","老虎","长颈鹿","鸵鸟","信天翁","斑马","企鹅"};
//存放规则可信度的结构体
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
//规则节点结构体 
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
//综合数据库结构体 
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
//最终还是要通过字符串进行节点的插入。 
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
				cout<<"已经使用"<<endl;
			else
				cout<<"未使用"<<endl;
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
//找出一条规则中实际的词条数
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
//这个函数有待改进 
//看看当前综合数据库中有没有终止动物集合中的动物 
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
//检查str字符串是否与某已知某一条事实相同。 
bool isMatch(string str)
{
	bool flag=false;
	NodeL *temp=headL;
	//因为这个地方默认是返回true那么每条规则就是五条内容 
	if(str=="0")
		return !flag;
	while(temp!=NULL)
	{
		//只要有一个相等的就行了。 
		if(str==temp->type)
		{ 
			flag=true;
			break;
		}
		temp=temp->next;
	}
	return flag;
}
//判断是否应该结束 
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
		cerr<<"OPEN FILE FAIL！"<<endl;
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
//找到节点编号为x的节点
void modify(int num)
{
	NodeA *temp=headA;
	while(temp!=NULL)
	{
		if(temp->num==num)
		{
			temp->used=true;
			create(temp->conclusion);
			//显示用到的规则
			outputNode(temp); 
			//这个地方可能有问题，会导致死循环。
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
//找到链表中置信度最高的节点的编号. 
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
			//找到与已有事实不同的且可信度最大的规则 
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
	int num=0;//记录每条规则内不匹配的词条数 
	cout<<"用到的规则是:"<<endl; 
	bool flag=true;
	NodeA *temp=headA;
	//用于放置每条不完全匹配的规则的置信度 
	NodeC *headC=NULL;
	zhixindu=1.0;
	while(true)
	{
		num=0;
		//每次都把flag更新一遍.可能会有问题。 
		flag=true;
		//如果这个规则没有被使用（这里没有被使用的意思是
		//没有通过这个规则导出什么结论）
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
			//如果某条规则与事实完全匹配，就把它标记为使用
			//并且把结论查到数据库中，打印当前的规则 
			//numOfEnd++ 
			if(flag)
			{
				temp->used=true;
				create(temp->conclusion);
				//显示用到的规则
				outputNode(temp); 
				//这个地方可能有问题，会导致死循环。 
				numOfEnd++;
				//每次插入到综合数据库内容后都要进行新的判断
				result=isEnd(headL);
				if(result!="")
				{
					if(result=="end")
						result="无法判定";
					cout<<endl<<"置信度="<<zhixindu<<endl;
					writeToFile();
					break;
				}else{
				}
			}
			//如果综合数据库中现有的内容并不能完全匹配该规则
			//那么计算可信度，并把该规则的序号和可信度插入到链表中。 
			else 
			{
				//这样求置信度还可以一看. 
				int zhenshijiedianshu=findNum(temp);
				int zhenshipipeishu=zhenshijiedianshu-num;
				float c=(float)zhenshipipeishu/zhenshijiedianshu;
				NodeC *t=createNode(temp->num,c);
				//将这个节点插入到链表中。 
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
		//循环移动 如果headC不为空，那么从中找到一个置信度最高的进行插入 
		//这时候已经是完成第一遍的遍历了，所以如果没有找到的话只能是
		//找一个可信度最大的进行插入了。 
		if(temp==NULL)
		{
			if(headC!=NULL)
			{
				NodeC *b=getMostCre(headC);//找到最大置信度的编号
				//修改规则链表. 
				modify(b->num); 
				numOfEnd++;
				zhixindu*=b->cre;
				//每插入一次，就把这个置信度的链表清空. 
				headC=NULL;
				result=isEnd(headL);
				if(result!="")
				{
					if(result=="end")
						result="无法判定";
					cout<<endl<<"置信度="<<zhixindu<<endl;
					writeToFile();
					break;
				}	
			}
			//再从头开始。 
			temp=headA;
		}
	}
}
int main()
{
	string str[]={"毛发","黄褐色","犬齿","有爪","眼盯前方","暗斑点"}; 
	//string str[]={"有奶","吃肉","黄褐色","黑色条纹"};
	//string str[]={"有奶","长腿","有蹄","长脖子","暗斑点"};
	//string str[]={"有奶","黑色条纹","有蹄"};
	//string str[]={"下蛋","会飞","长脖子","不飞"}; 
	//string str[]={"羽毛", "游泳", "黑白二色", "不飞"};
	//string str[]={"下蛋","会飞","善飞"};
	//注意更改这个地方的i值让它和上面str中的值得个数一致。 
	for(int i=0;i<6;i++)
		create(str[i]);
	readFromFile();
	findAnimal();
	cout<<"该动物是:"+result<<endl;
	return 0;
}
























