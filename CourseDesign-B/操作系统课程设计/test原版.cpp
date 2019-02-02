//这里。
//#include<stdio.h>
//#include<stdlib.h>
//#include<iostream.h>

#include <iostream>
#include <cstdlib>
using namespace std;

#define Free 0 //空闲状态
#define MAX_length 100 //最大内存空间为100M
typedef int Status;
int flag;//标志

typedef struct freearea//定义一个空闲区说明表结构
{
    int size;   //分区大小
    int address; //分区地址
    int state;   //状态
}ElemType;//元素类型

// 线性表的双向链表存储结构
typedef struct DuLNode//结构指针
{
    ElemType data; 
    struct DuLNode *prior; //前趋指针
    struct DuLNode *next;  //后继指针
}DuLNode,*DuLinkList;//指针链表 

/////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
//限制limit
int limit=5; 
//分区号
int numOfPart=0; 
//节点类型 
typedef struct list_node
{
	int numOfNode;//节点编号 （也就是盘块的大小） 
	int size;//节点大小（也就是盘块的大小） 
	int leftSize;//节点剩余的大小（也就是盘块剩余的大小） 
	struct list_node *next;//指向下一个节点的指针 
}Node;
//要被分配的盘块节点 
typedef struct block_node
{
	int part;//分区号 
	int numOfBlock;//编号（也就是将要被分配的盘块编号） 
	int size;//文件大小 
	int begin;//在盘块中开始的位置 
	//Node *current;//当前盘块指针 
	int current_size;
	int current_leftSize;
	
	struct block_node *next;
}Block;
//整个盘块的链表头指针 
Node *head_node=NULL;
//循环适应时的当前指针 
Node *next_node=NULL;
//整个待分配的文件的头指针 
Block *head_block=NULL;
//释放分配的盘块
void free_one(int num)
{
	if(head_block==NULL)
		cout<<"未分配分区,不可进行释放!"<<endl;
	else
	{
		int tempNum;
		Node *temp;
		Block *temp1,*temp2=temp1;
		temp1=head_block;
		while(temp1->part!=num&&temp1!=NULL)
		{
			temp2=temp1;
			temp1=temp1->next;
		}
		tempNum=temp1->numOfBlock;
		if(temp1==NULL)
			cout<<"该分区未被分配,释放出错!"<<endl;
		else
		{
			temp=head_node;
			while(temp->numOfNode!=tempNum)
				temp=temp->next;
		
			temp->leftSize+=temp1->size;
			if(head_block==temp1)
				head_block=temp1->next;
			else
				temp2->next=temp1->next;
			cout<<"释放成功!"<<endl;
		}
	}
} 
//创建一个节点 
Node * create_node(int xuhao,int daxiao)
{
	Node *temp=new Node();
	temp->numOfNode=xuhao;
	temp->size=daxiao;
	temp->leftSize=daxiao;
	temp->next=NULL;
	return temp;
}
//创建一个节点 
Block * create_block(int xuhao,int daxiao,int kaishi,Node *a)
{
	Block * temp=new Block();
	temp->part=numOfPart++; 
	temp->numOfBlock=xuhao;
	temp->size=daxiao;
	temp->begin=kaishi;
	//这个地方因为a是指正所以会发生浅拷贝但是因为
	//没有对a进行操作所以不会影响到原来的链表，所以不用改为深拷贝了 
	//temp->current=new Block();
	//temp->current=a;
	temp->current_size=a->size;
	temp->current_leftSize=a->leftSize;
	temp->next=NULL;
	return temp;
}
//讲节点插入待分配的文件的链表中 
void insert_block(Block *temp)
{
	Block *p;
	if(head_block==NULL)
		head_block=temp;
	else
	{
		p=head_block;
		while(p->next!=NULL)
			p=p->next;
		p->next=temp;
	}
}
//交换两个节点，在排序中使用 
void exchange(Node *a,Node *b)
{
	int num;
	int size;
	int left;
	num=a->numOfNode;
	size=a->size;
	left=a->leftSize;
	a->numOfNode=b->numOfNode;
	a->size=b->size;
	a->leftSize=b->leftSize;
	b->numOfNode=num;
	b->size=size;
	b->leftSize=left;
}
//按盘块的大小进行排序(从大到小进行排序)，主要是用于worst_fit这个算法中 
void sort_size()
{
	if(head_node==NULL)
		cout<<"The list is empty!"<<endl;
	else
	{
		int size=100;
		Node *temp=head_node;
		for(int i=0;i<size-1;i++)
		{
			temp=head_node;
			for(int j=0;j<size-1-i;j++)
			{
				if(temp->size<temp->next->size)
					exchange(temp,temp->next);
				temp=temp->next;
			}
		}
			
	}
}

//按盘块的大小进行排序(从小到大进行排序)，主要是用于best_fit这个算法中 
void sort_size1()
{
	if(head_node==NULL)
		cout<<"The list is empty!"<<endl;
	else
	{
		int size=100;
		Node *temp=head_node;
		for(int i=0;i<size-1;i++)
		{
			temp=head_node;
			for(int j=0;j<size-1-i;j++)
			{
				if(temp->size>temp->next->size)
					exchange(temp,temp->next);
				temp=temp->next;
			}
		}
			
	}
}
//按盘块的序号进行排序(从小到大进行排序)，主要是用于first/next_fit这个算法中 
void sort_num()
{
	if(head_node==NULL)
		cout<<"The list is empty!"<<endl;
	else
	{
		int size=100;
		Node *temp=head_node;
		for(int i=0;i<size-1;i++)
		{
			temp=head_node;
			for(int j=0;j<size-1-i;j++)
			{
				if(temp->numOfNode>temp->next->numOfNode)
					exchange(temp,temp->next);
				temp=temp->next;
			}
		}
			
	}
}

//创建盘块链表
//假定一共有100个盘块，盘块大小从10 开始每次逐步加10 所以最后一个是1000 
void createList()
{
	int i=0;
	int size=10;
	Node *p;
	while(i<100)
	{
		Node *temp=create_node(i,size);
		if(head_node==NULL)
			head_node=temp;
		else
			p->next=temp;
		p=temp;
		i++;
		size+=10;
	}
}
//显示节点 
void show_node(Node *temp)
{
	cout<<"序号是:"<<temp->numOfNode<<"  ";
	cout<<"大小是:"<<temp->size<" ";
	cout<<"剩余大小是:"<<temp->leftSize<<endl;
}
//显示节点 
void show_block(Block *temp)
{
	cout<<"文件大小    分区号   盘块号    盘块容量    起始位置    盘块剩余容量\n";
	cout<<"    "<<temp->size<<"    ";
	cout<<"    "<<temp->part<<"        ";
	cout<<temp->numOfBlock<<"        ";
	cout<<temp->current_size<<"         ";
	cout<<temp->begin<<"             ";
	cout<<temp->current_leftSize<<endl;
//	cout<<"文件大小是: "<<temp->size<"  ";
//	cout<<"盘块号是: "<<temp->numOfBlock<<"  ";
//	cout<<"盘块容量是: "<<temp->current_size<<"  ";
//	cout<<"起始位置是: "<<temp->begin<<"  ";
//	cout<<"盘块剩余容量是:"<<temp->current_leftSize<<endl;
}
//显示链表 
void show_list()
{
	Node *temp;
	if(head_node==NULL)
		cout<<"The list is empty!"<<endl;
	else
	{
		temp=head_node;
		while(temp!=NULL)
		{
			show_node(temp);
			temp=temp->next;
		}
	}
}
//显示链表 
void show()
{
	Block *temp;
	if(head_block==NULL)
		cout<<"未分配盘块!"<<endl;
	else
	{
		temp=head_block;
		while(temp!=NULL)
		{
			show_block(temp);
			temp=temp->next;
		}
	}
}
//最佳适应，这个和首次适应时一样的。 
Status Best_fit(int request)
{
	Node *temp;
	if(head_node==NULL)
	{
		cout<<"The list is empty!"<<endl;
		return 0;
	}
	else
	{
		//按盘块大小（从小到大）进行排序 
		sort_size1();
		temp=head_node;
		//找到待分配的节点 
		while(temp!=NULL&&temp->leftSize<request||temp->leftSize<=limit)
			temp=temp->next;
		if(temp==NULL)
			return 0;
		else
		{
			int temp_leftSize=temp->leftSize;
			temp->leftSize=temp->leftSize-request;
			Block *b=create_block(temp->numOfNode,request,temp->size-temp_leftSize,temp);
			insert_block(b);
		}
	}
	return 1;
}
//最坏适应 
Status Worst_fit(int request)
{
	Node *temp;
	if(head_node==NULL)
	{
		cout<<"The list is empty!"<<endl;
		return 0;
	}
	else
	{
		//按盘块大小（从大到小）进行排序 
		sort_size();
		temp=head_node;
		while(temp!=NULL&&temp->leftSize<request||temp->leftSize<=limit)
			temp=temp->next;
		if(temp==NULL)
			return 0;
		else
		{
			int temp_leftSize=temp->leftSize;
			temp->leftSize=temp->leftSize-request;
			Block *b=create_block(temp->numOfNode,request,temp->size-temp_leftSize,temp);
			insert_block(b);
			
		}
	}
	return 1;
}
//首次适应 
Status first_fit(int request)
{
	Node *temp;
	if(head_node==NULL)
	{
		cout<<"The list is empty!"<<endl;
		return 0;
	}
	else
	{
		//按序号进行排序（从小到大） 
		sort_num();
		temp=head_node;
		while(temp!=NULL&&temp->leftSize<request||temp->leftSize<=limit)
			temp=temp->next;
		if(temp==NULL)
			return 0;
		else
		{
			int temp_leftSize=temp->leftSize;
			temp->leftSize=temp->leftSize-request;
			Block *b=create_block(temp->numOfNode,request,temp->size-temp_leftSize,temp);
			insert_block(b);
		}
	}
	return 1;
}
//循环适应 
Status next_fit(int request)
{
	if(next_node==NULL)
	{
		cout<<"The list is empty!"<<endl;
		return 0;
	}	
	else
	{
		//按序号进行排序（从小到大） 
		sort_num();
		while(next_node!=NULL&&next_node->leftSize<request||next_node->leftSize<=limit)
			next_node=next_node->next;
		if(next_node->next==NULL)
			next_node=head_node;
		else 
		{	
			int temp_leftSize=next_node->leftSize;
			next_node->leftSize=next_node->leftSize-request;
			Block *b=create_block(next_node->numOfNode,request,next_node->size-temp_leftSize,next_node);
			insert_block(b);
			
		}	
	}
	return 1;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////


DuLinkList first; //头结点
DuLinkList last;  //尾结点
Status alloc(int);//内存分配
Status alloc1(int);//regular内存分配
//Status free(int); //内存回收
//Status Best_fit(int); //最佳适应算法
//Status Worst_fit(int);//最差适应算法
//Status first_fit(int);//首次适应算法
//Status next_fit(int );//循环首次适应
Status regular_fit(int);//固定分区分配
void show_static();//查看分配
Status Initblock();//开创空间表 

Status Initblock()//开创带头结点的内存空间链表
{
	//固定分区的条件 
    first=(DuLinkList)malloc(sizeof(DuLNode));
    last=(DuLinkList)malloc(sizeof(DuLNode));
    first->prior=NULL;
    first->next=last;
    last->prior=first;
    last->next=NULL;
    last->data.address=0;
    last->data.size=MAX_length;
    last->data.state=Free;
    //动态分区的条件 
	createList();
	next_node=head_node;
	//*********************
	//在这里可以设置limit的大小,我觉得不用让用户进行输入，但然让用户输入也不错。 
	//cout<<"请输入剩余盘块大小的限制:"<<endl;
	//cin>>limit; 
	
    return 1;
}


//动态分配主存
Status alloc(int ch)
{
    int request = 0;
    cout<<"请输入需要分配的主存大小(单位:M)："; 
    cin>>request;
   
    //if(request<0 ||request==0) 
    if(request<=0)
    {
        cout<<"分配大小不合适，请重试！"<<endl;
        return 0;
    }
 
    //if(ch==1||ch==2||ch==3||ch==4) //选择最佳适应算法
    if(ch==1)//选择最佳适应算法
    {
        if(Best_fit(request)==1) 
			cout<<"分配成功！"<<endl;
        else 
			cout<<"内存不足，分配失败！"<<endl;
		show();
        return 1;
    }
    if(ch==2) //选择最差适应算法
    {
        if(Worst_fit(request)==1) 
			cout<<"分配成功！"<<endl;
        else 
			cout<<"内存不足，分配失败！"<<endl;
		show();
        return 1;
    }
	if(ch==3) //首先适应算法
    {
        if(first_fit(request)==1) 
			cout<<"分配成功！"<<endl;
        else 
			cout<<"内存不足，分配失败！"<<endl;
		show();
        return 1;
    }
	if(ch==4) //首先适应算法
    {
        if(next_fit(request)==1) 
			cout<<"分配成功！"<<endl;
        else 
			cout<<"内存不足，分配失败！"<<endl;
		show();
        return 1;
    }
       /* if(ch==2) //选择最差适应算法
    {
        if(Worst_fit(request)==1) cout<<"分配成功！"<<endl;
        else cout<<"内存不足，分配失败！"<<endl;
        return 1;
    }
		if(ch==3) //首先适应算法
    {
        if(first_fit(request)==1) cout<<"分配成功！"<<endl;
        else cout<<"内存不足，分配失败！"<<endl;
        return 1;
    }
		if(ch==4) //首先适应算法
    {
        if(next_fit(request)==1) cout<<"分配成功！"<<endl;
        else cout<<"内存不足，分配失败！"<<endl;
        return 1;
    }*/
		
   
}
//静态分配内存
Status alloc1(int ch)
{
    int request = 0;
    cout<<"请输入需要分配的主存大小(单位:M)："; 
    cin>>request;
    //if(request<0 ||request==0||request>20) 
    if(request<=0||request>20)
    {
        cout<<"\n分配大小应在 < 0 M -- 20 M > ，请重新输入！"<<endl;
        return 0;
    }
    if(ch==5) //regular算法
    {
        if(regular_fit(request)==1) 
			cout<<"分配成功！"<<endl;
        else 
			cout<<"内存不足，分配失败!"<<endl;
        show_static();
        return 1;
    }
		
   
}


////最佳适应算法
//Status Best_fit(int request)
//{
//    int ch; //记录最小剩余空间
//    DuLinkList temp=(DuLinkList)malloc(sizeof(DuLNode));//申请内存空间 
//    temp->data.size=request;
//    temp->data.state=1;
//    DuLNode *p=first->next;
//    DuLNode *q=NULL; //记录最佳插入位置
//
//    while(p) //初始化最小空间和最佳位置
//    {
//        if(p->data.state==Free && (p->data.size>=request) )
//        {
//
//                        if(q==NULL)
//                        {
//                                q=p;
//                                ch=p->data.size-request;
//
//                        }
//                        else if(q->data.size > p->data.size)
//                        {
//
//                                q=p;
//                                ch=p->data.size-request;
//
//                        }
//        }
//        p=p->next;
//    }
//
//    if(q==NULL) return 0;//没有找到空闲块
//    else if(q->data.size==request)//fix state
//    {
//        q->data.state=1;
//        return 1;
//    }
//
//        else
//        {
//        temp->prior=q->prior;
//        temp->next=q;
//        temp->data.address=q->data.address;
//        q->prior->next=temp;
//        q->prior=temp;
//        q->data.address+=request;
//        q->data.size=ch;
//        return 1;
//
//    }
//        return 1;
//}
//
//
////最差适应算法
//Status Worst_fit(int request)
//{
//    int ch; //记录最大剩余空间
//    DuLinkList temp=(DuLinkList)malloc(sizeof(DuLNode)); 
//    temp->data.size=request;
//    temp->data.state=1;
//    DuLNode *p=first->next;
//    DuLNode *q=NULL; //记录最佳插入位置
//
//    while(p) //初始化最大空间和最佳位置
//    {
//        if(p->data.state==Free && (p->data.size>=request) )
//        {
//                  if(q==NULL)
//				  {
//                    q=p;
//                    ch=p->data.size-request;
//				  }
//                  else if(q->data.size < p->data.size)
//				  {
//                    q=p;
//                    ch=p->data.size-request;
//				  }
//        }
//        p=p->next;
//    }
//
//    if(q==NULL) return 0;//没有找到空闲块
//    else if(q->data.size==request)
//	{
//        q->data.state=1;
//        return 1;
//    }
//        else
//        {
//          temp->prior=q->prior;
//          temp->next=q;
//          temp->data.address=q->data.address;
//          q->prior->next=temp;
//          q->prior=temp;
//          q->data.address+=request;
//          q->data.size=ch;
//          return 1;
//		}
//        return 1;
//}
//
////首次适应
//
//
//Status first_fit(int request)
//{
//    int ch; //记录最小剩余空间
//    DuLinkList temp=(DuLinkList)malloc(sizeof(DuLNode));//申请内存空间 
//    temp->data.size=request;
//    temp->data.state=1;
//    DuLNode *p=first->next;
//    DuLNode *q=NULL; //记录最佳插入位置
//
//    while(p) //初始化最小空间和最佳位置
//    {
//        if(p->data.state==Free && (p->data.size<=request) )
//        {
//
//                        if(q==NULL)
//                        {
//                                q=p;
//                                ch=p->data.size-request;
//
//                        }
//                        else if(q->data.size <=p->data.size)
//                        {
//
//                                q=p;
//                                ch=p->data.size-request;
//
//                        }
//        }
//        p=p->next;
//    }
//
//    if(q==NULL) return 0;//没有找到空闲块
//    else if(q->data.size==request)//fix state
//    {
//        q->data.state=1;
//        return 1;
//    }
//
//        else
//        {
//        temp->prior=q->prior;
//        temp->next=q;
//        temp->data.address=q->data.address;
//        q->prior->next=temp;
//        q->prior=temp;
//        q->data.address+=request;
//        q->data.size=ch;
//        return 1;
//
//    }
//        return 1;
//}
//
////循环首次适应
//
//Status next_fit(int request)
//{
//    int ch; //记录最小剩余空间
//    DuLinkList temp=(DuLinkList)malloc(sizeof(DuLNode));//申请内存空间 
//    temp->data.size=request;
//    temp->data.state=1;
//    DuLNode *p=first->next;
//    DuLNode *q=NULL; //记录最佳插入位置
//
//    while(p) //初始化最小空间和最佳位置
//    {
//        if(p->data.state==Free && (p->data.size>=request) )
//        {
//
//                        if(q==NULL)
//                        {
//                                q=p;
//                                ch=p->data.size-request;
//
//                        }
//                        else if(q->data.size >= p->data.size)
//                        {
//
//                                q=p;
//                                ch=p->data.size-request;
//
//                        }
//        }
//        p=p->next;
//    }
//
//    if(q==NULL) return 0;//没有找到空闲块
//    else if(q->data.size==request)//fix state
//    {
//        q->data.state=1;
//        return 1;
//    }
//
//        else
//        {
//        temp->prior=q->prior;
//        temp->next=q;
//        temp->data.address=q->data.address;
//        q->prior->next=temp;
//        q->prior=temp;
//        q->data.address+=request;//始查找指针
//        q->data.size=ch;
//        return 1;
//
//    }
//        return 1;
//}

//静态内存分配

Status regular_fit(int request)
{
    int ch; //记录最小剩余空间
    DuLinkList temp=(DuLinkList)malloc(sizeof(DuLNode));//申请内存空间 
    temp->data.size=request;
    temp->data.state=1;
    DuLNode *p=first->next;
    DuLNode *q=NULL; //记录最佳插入位置

    while(p) //初始化最小空间和最佳位置
    {
        if(p->data.state==Free && (p->data.size>=request) )
        {

                        if(q==NULL)
                        {
                                q=p;
                                ch=p->data.size-request;

                        }
                        else if(q->data.size >= p->data.size)
                        {

                                q=p;
                                ch=p->data.size-request;

                        }
        }
        p=p->next;
    }

    if(q==NULL) return 0;//没有找到空闲块
    else if(q->data.size==request)//fix state
    {
        q->data.state=1;
        return 1;
    }

        else
        {
        temp->prior=q->prior;
        temp->next=q;
        temp->data.address=q->data.address;
        q->prior->next=temp;
        q->prior=temp;
        q->data.address+=request;
        q->data.size=ch;
        return 1;

    }
        return 1;
}


//主存回收用于固定分配方式。 
//这个用于固定分区有问题，所以没有把他用到固定分区上。 
//Status free_two(int flag)
//{
//    DuLNode *p=first;
//        for(int i= 0; i <= flag; i++)
//                if(p!=NULL)
//                        p=p->next;
//                else
//                        return 0;
//
//        p->data.state=Free;
//    if(p->prior!=first && p->prior->data.state==Free)//与前面的空闲块相连
//    {
//        p->prior->data.size+=p->data.size;
//        p->prior->next=p->next;
//        p->next->prior=p->prior;
//                p=p->prior;
//    }
//    if(p->next!= last && p->next->data.state==Free)//与后面的空闲块相连
//    {
//        p->data.size+=p->next->data.size;
//        p->next->next->prior=p;
//        p->next=p->next->next; 
//    }
//        if(p->next==last && p->next->data.state==Free)//与最后的空闲块相连
//    {
//                p->data.size+=p->next->data.size;
//        p->next=NULL; 
//    }
//
//    return 1;
//}
//

//显示主存分配情况
void show_static()
{
    int flag=0;
    cout<<"\n主存分配情况:\n";
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++\n\n";
    DuLNode *p= first->next;
    cout<<"分区号\t起始地址\t分区大小\t状态\n\n";
    while(p)
    {
        cout<<"  "<<flag++<<"\t";
        cout<<"  "<<p->data.address<<"\t\t";
        cout<<" "<<p->data.size<<"M\t\t";
        if(p->data.state==Free) cout<<"空闲\n\n";
        else cout<<"已分配\n\n";
        p=p->next;
    }
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++\n\n";
}
int main()
{
	int flag;
	int flag1;
	int aim_block;
	int request;
	Initblock();
	while(1)
	{
		cout<<endl<<"\t\t\t欢迎使用分区分配算法!"<<endl;
		cout<<"\t1.动态分区分配算法\t\t2.固定分区分配"<<endl;
		cout<<"\t3.退出"<<endl<<endl; 
		cout<<"请输入使用的功能的代号:"<<endl;
		cin>>flag;
		switch(flag)
		{
			case 1:
				{
					cout<<"\t\t\t动态分区分配算法!"<<endl<<endl;
					cout<<"\t\t1.最佳适应算法\t\t2.最坏适应算法"<<endl;
					cout<<"\t\t3.首次适应算法\t\t4.循环适应算法"<<endl;
					cout<<"\t\t5.释放内存"<<endl<<endl;
					cout<<"请输入选择的功能:"<<endl;
					cin>>flag1;
					switch(flag1)
					{
						case 1:alloc(flag1);break;
						case 2:alloc(flag1);break;
						case 3:alloc(flag1);break;
						case 4:alloc(flag1);break;
						case 5:
							{
								cout<<"请输入要释放的分区号："<<endl;
								cin>>aim_block; 
								free_one(aim_block);
								show();
							}
						
						break;
						default:cout<<"请确认输入!"<<endl;
					}
				}
			break;
			case 2:alloc1(5);break;	
			case 3:cout<<"谢谢使用!";exit(0);break;
			default:cout<<"请确认输入是否正确,谢谢使用!"<<endl; 
		}
	}
	return 0;
}

/*int main()
{
    int ch;//算法选择标记
    l1: cout<<"请输入所使用的内存分配算法：\n";
    cout<<"(1)最佳适应算法\n(2)最差适应算法\n";
	cout<<"(3)首次适应\n(4)首次循环适应\n";
	cout<<"(5)固定分区\n";

    cin>>ch;
     while(ch<1||ch>5)
	 {
                cout<<"输入错误，请重新输入所使用的内存分配算法：\n";
                cin>>ch;
	 }

    Initblock(); //开创空间表
    int choice;  //操作选择标记

    while(1)
    {
                show();
                cout<<"请输入您的操作：";
                cout<<"\n1: 动态分配内存\n2: 静态分配内存\n3: 回收内存\n4:返回上一层\n0: 退出\n";
				
        
        cin>>choice;
		          if(choice==4)
				  { 
				   goto l1;
				  }
		else
               if(choice==1) alloc(ch); // 分配内存
			   else if(choice==2) alloc1(ch);//静态分配内存
               else if(choice==3)  // 内存回收
			   {
                int flag;
                cout<<"请输入您要释放的分区号：";
                cin>>flag;
                free(flag);
			   }
              else if(choice==0) break; //退出
              else //输入操作有误
			  {
              cout<<"输入有误，请重试！"<<endl;
              continue;
			  }
	}
	return 0;
}*/
