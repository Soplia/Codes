//���
//#include<stdio.h>
//#include<stdlib.h>
//#include<iostream.h>

#include <iostream>
#include <cstdlib>
using namespace std;

#define Free 0 //����״̬
#define MAX_length 100 //����ڴ�ռ�Ϊ100M
typedef int Status;
int flag;//��־

typedef struct freearea//����һ��������˵����ṹ
{
    int size;   //������С
    int address; //������ַ
    int state;   //״̬
}ElemType;//Ԫ������

// ���Ա��˫������洢�ṹ
typedef struct DuLNode//�ṹָ��
{
    ElemType data; 
    struct DuLNode *prior; //ǰ��ָ��
    struct DuLNode *next;  //���ָ��
}DuLNode,*DuLinkList;//ָ������ 

/////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
//����limit
int limit=5; 
//������
int numOfPart=0; 
//�ڵ����� 
typedef struct list_node
{
	int numOfNode;//�ڵ��� ��Ҳ�����̿�Ĵ�С�� 
	int size;//�ڵ��С��Ҳ�����̿�Ĵ�С�� 
	int leftSize;//�ڵ�ʣ��Ĵ�С��Ҳ�����̿�ʣ��Ĵ�С�� 
	struct list_node *next;//ָ����һ���ڵ��ָ�� 
}Node;
//Ҫ��������̿�ڵ� 
typedef struct block_node
{
	int part;//������ 
	int numOfBlock;//��ţ�Ҳ���ǽ�Ҫ��������̿��ţ� 
	int size;//�ļ���С 
	int begin;//���̿��п�ʼ��λ�� 
	//Node *current;//��ǰ�̿�ָ�� 
	int current_size;
	int current_leftSize;
	
	struct block_node *next;
}Block;
//�����̿������ͷָ�� 
Node *head_node=NULL;
//ѭ����Ӧʱ�ĵ�ǰָ�� 
Node *next_node=NULL;
//������������ļ���ͷָ�� 
Block *head_block=NULL;
//�ͷŷ�����̿�
void free_one(int num)
{
	if(head_block==NULL)
		cout<<"δ�������,���ɽ����ͷ�!"<<endl;
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
			cout<<"�÷���δ������,�ͷų���!"<<endl;
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
			cout<<"�ͷųɹ�!"<<endl;
		}
	}
} 
//����һ���ڵ� 
Node * create_node(int xuhao,int daxiao)
{
	Node *temp=new Node();
	temp->numOfNode=xuhao;
	temp->size=daxiao;
	temp->leftSize=daxiao;
	temp->next=NULL;
	return temp;
}
//����һ���ڵ� 
Block * create_block(int xuhao,int daxiao,int kaishi,Node *a)
{
	Block * temp=new Block();
	temp->part=numOfPart++; 
	temp->numOfBlock=xuhao;
	temp->size=daxiao;
	temp->begin=kaishi;
	//����ط���Ϊa��ָ�����Իᷢ��ǳ����������Ϊ
	//û�ж�a���в������Բ���Ӱ�쵽ԭ�����������Բ��ø�Ϊ����� 
	//temp->current=new Block();
	//temp->current=a;
	temp->current_size=a->size;
	temp->current_leftSize=a->leftSize;
	temp->next=NULL;
	return temp;
}
//���ڵ�����������ļ��������� 
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
//���������ڵ㣬��������ʹ�� 
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
//���̿�Ĵ�С��������(�Ӵ�С��������)����Ҫ������worst_fit����㷨�� 
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

//���̿�Ĵ�С��������(��С�����������)����Ҫ������best_fit����㷨�� 
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
//���̿����Ž�������(��С�����������)����Ҫ������first/next_fit����㷨�� 
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

//�����̿�����
//�ٶ�һ����100���̿飬�̿��С��10 ��ʼÿ���𲽼�10 �������һ����1000 
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
//��ʾ�ڵ� 
void show_node(Node *temp)
{
	cout<<"�����:"<<temp->numOfNode<<"  ";
	cout<<"��С��:"<<temp->size<" ";
	cout<<"ʣ���С��:"<<temp->leftSize<<endl;
}
//��ʾ�ڵ� 
void show_block(Block *temp)
{
	cout<<"�ļ���С    ������   �̿��    �̿�����    ��ʼλ��    �̿�ʣ������\n";
	cout<<"    "<<temp->size<<"    ";
	cout<<"    "<<temp->part<<"        ";
	cout<<temp->numOfBlock<<"        ";
	cout<<temp->current_size<<"         ";
	cout<<temp->begin<<"             ";
	cout<<temp->current_leftSize<<endl;
//	cout<<"�ļ���С��: "<<temp->size<"  ";
//	cout<<"�̿����: "<<temp->numOfBlock<<"  ";
//	cout<<"�̿�������: "<<temp->current_size<<"  ";
//	cout<<"��ʼλ����: "<<temp->begin<<"  ";
//	cout<<"�̿�ʣ��������:"<<temp->current_leftSize<<endl;
}
//��ʾ���� 
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
//��ʾ���� 
void show()
{
	Block *temp;
	if(head_block==NULL)
		cout<<"δ�����̿�!"<<endl;
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
//�����Ӧ��������״���Ӧʱһ���ġ� 
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
		//���̿��С����С���󣩽������� 
		sort_size1();
		temp=head_node;
		//�ҵ�������Ľڵ� 
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
//���Ӧ 
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
		//���̿��С���Ӵ�С���������� 
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
//�״���Ӧ 
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
		//����Ž������򣨴�С���� 
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
//ѭ����Ӧ 
Status next_fit(int request)
{
	if(next_node==NULL)
	{
		cout<<"The list is empty!"<<endl;
		return 0;
	}	
	else
	{
		//����Ž������򣨴�С���� 
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


DuLinkList first; //ͷ���
DuLinkList last;  //β���
Status alloc(int);//�ڴ����
Status alloc1(int);//regular�ڴ����
//Status free(int); //�ڴ����
//Status Best_fit(int); //�����Ӧ�㷨
//Status Worst_fit(int);//�����Ӧ�㷨
//Status first_fit(int);//�״���Ӧ�㷨
//Status next_fit(int );//ѭ���״���Ӧ
Status regular_fit(int);//�̶���������
void show_static();//�鿴����
Status Initblock();//�����ռ�� 

Status Initblock()//������ͷ�����ڴ�ռ�����
{
	//�̶����������� 
    first=(DuLinkList)malloc(sizeof(DuLNode));
    last=(DuLinkList)malloc(sizeof(DuLNode));
    first->prior=NULL;
    first->next=last;
    last->prior=first;
    last->next=NULL;
    last->data.address=0;
    last->data.size=MAX_length;
    last->data.state=Free;
    //��̬���������� 
	createList();
	next_node=head_node;
	//*********************
	//�������������limit�Ĵ�С,�Ҿ��ò������û��������룬��Ȼ���û�����Ҳ���� 
	//cout<<"������ʣ���̿��С������:"<<endl;
	//cin>>limit; 
	
    return 1;
}


//��̬��������
Status alloc(int ch)
{
    int request = 0;
    cout<<"��������Ҫ����������С(��λ:M)��"; 
    cin>>request;
   
    //if(request<0 ||request==0) 
    if(request<=0)
    {
        cout<<"�����С�����ʣ������ԣ�"<<endl;
        return 0;
    }
 
    //if(ch==1||ch==2||ch==3||ch==4) //ѡ�������Ӧ�㷨
    if(ch==1)//ѡ�������Ӧ�㷨
    {
        if(Best_fit(request)==1) 
			cout<<"����ɹ���"<<endl;
        else 
			cout<<"�ڴ治�㣬����ʧ�ܣ�"<<endl;
		show();
        return 1;
    }
    if(ch==2) //ѡ�������Ӧ�㷨
    {
        if(Worst_fit(request)==1) 
			cout<<"����ɹ���"<<endl;
        else 
			cout<<"�ڴ治�㣬����ʧ�ܣ�"<<endl;
		show();
        return 1;
    }
	if(ch==3) //������Ӧ�㷨
    {
        if(first_fit(request)==1) 
			cout<<"����ɹ���"<<endl;
        else 
			cout<<"�ڴ治�㣬����ʧ�ܣ�"<<endl;
		show();
        return 1;
    }
	if(ch==4) //������Ӧ�㷨
    {
        if(next_fit(request)==1) 
			cout<<"����ɹ���"<<endl;
        else 
			cout<<"�ڴ治�㣬����ʧ�ܣ�"<<endl;
		show();
        return 1;
    }
       /* if(ch==2) //ѡ�������Ӧ�㷨
    {
        if(Worst_fit(request)==1) cout<<"����ɹ���"<<endl;
        else cout<<"�ڴ治�㣬����ʧ�ܣ�"<<endl;
        return 1;
    }
		if(ch==3) //������Ӧ�㷨
    {
        if(first_fit(request)==1) cout<<"����ɹ���"<<endl;
        else cout<<"�ڴ治�㣬����ʧ�ܣ�"<<endl;
        return 1;
    }
		if(ch==4) //������Ӧ�㷨
    {
        if(next_fit(request)==1) cout<<"����ɹ���"<<endl;
        else cout<<"�ڴ治�㣬����ʧ�ܣ�"<<endl;
        return 1;
    }*/
		
   
}
//��̬�����ڴ�
Status alloc1(int ch)
{
    int request = 0;
    cout<<"��������Ҫ����������С(��λ:M)��"; 
    cin>>request;
    //if(request<0 ||request==0||request>20) 
    if(request<=0||request>20)
    {
        cout<<"\n�����СӦ�� < 0 M -- 20 M > �����������룡"<<endl;
        return 0;
    }
    if(ch==5) //regular�㷨
    {
        if(regular_fit(request)==1) 
			cout<<"����ɹ���"<<endl;
        else 
			cout<<"�ڴ治�㣬����ʧ��!"<<endl;
        show_static();
        return 1;
    }
		
   
}


////�����Ӧ�㷨
//Status Best_fit(int request)
//{
//    int ch; //��¼��Сʣ��ռ�
//    DuLinkList temp=(DuLinkList)malloc(sizeof(DuLNode));//�����ڴ�ռ� 
//    temp->data.size=request;
//    temp->data.state=1;
//    DuLNode *p=first->next;
//    DuLNode *q=NULL; //��¼��Ѳ���λ��
//
//    while(p) //��ʼ����С�ռ�����λ��
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
//    if(q==NULL) return 0;//û���ҵ����п�
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
////�����Ӧ�㷨
//Status Worst_fit(int request)
//{
//    int ch; //��¼���ʣ��ռ�
//    DuLinkList temp=(DuLinkList)malloc(sizeof(DuLNode)); 
//    temp->data.size=request;
//    temp->data.state=1;
//    DuLNode *p=first->next;
//    DuLNode *q=NULL; //��¼��Ѳ���λ��
//
//    while(p) //��ʼ�����ռ�����λ��
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
//    if(q==NULL) return 0;//û���ҵ����п�
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
////�״���Ӧ
//
//
//Status first_fit(int request)
//{
//    int ch; //��¼��Сʣ��ռ�
//    DuLinkList temp=(DuLinkList)malloc(sizeof(DuLNode));//�����ڴ�ռ� 
//    temp->data.size=request;
//    temp->data.state=1;
//    DuLNode *p=first->next;
//    DuLNode *q=NULL; //��¼��Ѳ���λ��
//
//    while(p) //��ʼ����С�ռ�����λ��
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
//    if(q==NULL) return 0;//û���ҵ����п�
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
////ѭ���״���Ӧ
//
//Status next_fit(int request)
//{
//    int ch; //��¼��Сʣ��ռ�
//    DuLinkList temp=(DuLinkList)malloc(sizeof(DuLNode));//�����ڴ�ռ� 
//    temp->data.size=request;
//    temp->data.state=1;
//    DuLNode *p=first->next;
//    DuLNode *q=NULL; //��¼��Ѳ���λ��
//
//    while(p) //��ʼ����С�ռ�����λ��
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
//    if(q==NULL) return 0;//û���ҵ����п�
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
//        q->data.address+=request;//ʼ����ָ��
//        q->data.size=ch;
//        return 1;
//
//    }
//        return 1;
//}

//��̬�ڴ����

Status regular_fit(int request)
{
    int ch; //��¼��Сʣ��ռ�
    DuLinkList temp=(DuLinkList)malloc(sizeof(DuLNode));//�����ڴ�ռ� 
    temp->data.size=request;
    temp->data.state=1;
    DuLNode *p=first->next;
    DuLNode *q=NULL; //��¼��Ѳ���λ��

    while(p) //��ʼ����С�ռ�����λ��
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

    if(q==NULL) return 0;//û���ҵ����п�
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


//����������ڹ̶����䷽ʽ�� 
//������ڹ̶����������⣬����û�а����õ��̶������ϡ� 
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
//    if(p->prior!=first && p->prior->data.state==Free)//��ǰ��Ŀ��п�����
//    {
//        p->prior->data.size+=p->data.size;
//        p->prior->next=p->next;
//        p->next->prior=p->prior;
//                p=p->prior;
//    }
//    if(p->next!= last && p->next->data.state==Free)//�����Ŀ��п�����
//    {
//        p->data.size+=p->next->data.size;
//        p->next->next->prior=p;
//        p->next=p->next->next; 
//    }
//        if(p->next==last && p->next->data.state==Free)//�����Ŀ��п�����
//    {
//                p->data.size+=p->next->data.size;
//        p->next=NULL; 
//    }
//
//    return 1;
//}
//

//��ʾ����������
void show_static()
{
    int flag=0;
    cout<<"\n����������:\n";
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++\n\n";
    DuLNode *p= first->next;
    cout<<"������\t��ʼ��ַ\t������С\t״̬\n\n";
    while(p)
    {
        cout<<"  "<<flag++<<"\t";
        cout<<"  "<<p->data.address<<"\t\t";
        cout<<" "<<p->data.size<<"M\t\t";
        if(p->data.state==Free) cout<<"����\n\n";
        else cout<<"�ѷ���\n\n";
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
		cout<<endl<<"\t\t\t��ӭʹ�÷��������㷨!"<<endl;
		cout<<"\t1.��̬���������㷨\t\t2.�̶���������"<<endl;
		cout<<"\t3.�˳�"<<endl<<endl; 
		cout<<"������ʹ�õĹ��ܵĴ���:"<<endl;
		cin>>flag;
		switch(flag)
		{
			case 1:
				{
					cout<<"\t\t\t��̬���������㷨!"<<endl<<endl;
					cout<<"\t\t1.�����Ӧ�㷨\t\t2.���Ӧ�㷨"<<endl;
					cout<<"\t\t3.�״���Ӧ�㷨\t\t4.ѭ����Ӧ�㷨"<<endl;
					cout<<"\t\t5.�ͷ��ڴ�"<<endl<<endl;
					cout<<"������ѡ��Ĺ���:"<<endl;
					cin>>flag1;
					switch(flag1)
					{
						case 1:alloc(flag1);break;
						case 2:alloc(flag1);break;
						case 3:alloc(flag1);break;
						case 4:alloc(flag1);break;
						case 5:
							{
								cout<<"������Ҫ�ͷŵķ����ţ�"<<endl;
								cin>>aim_block; 
								free_one(aim_block);
								show();
							}
						
						break;
						default:cout<<"��ȷ������!"<<endl;
					}
				}
			break;
			case 2:alloc1(5);break;	
			case 3:cout<<"ллʹ��!";exit(0);break;
			default:cout<<"��ȷ�������Ƿ���ȷ,ллʹ��!"<<endl; 
		}
	}
	return 0;
}

/*int main()
{
    int ch;//�㷨ѡ����
    l1: cout<<"��������ʹ�õ��ڴ�����㷨��\n";
    cout<<"(1)�����Ӧ�㷨\n(2)�����Ӧ�㷨\n";
	cout<<"(3)�״���Ӧ\n(4)�״�ѭ����Ӧ\n";
	cout<<"(5)�̶�����\n";

    cin>>ch;
     while(ch<1||ch>5)
	 {
                cout<<"�������������������ʹ�õ��ڴ�����㷨��\n";
                cin>>ch;
	 }

    Initblock(); //�����ռ��
    int choice;  //����ѡ����

    while(1)
    {
                show();
                cout<<"���������Ĳ�����";
                cout<<"\n1: ��̬�����ڴ�\n2: ��̬�����ڴ�\n3: �����ڴ�\n4:������һ��\n0: �˳�\n";
				
        
        cin>>choice;
		          if(choice==4)
				  { 
				   goto l1;
				  }
		else
               if(choice==1) alloc(ch); // �����ڴ�
			   else if(choice==2) alloc1(ch);//��̬�����ڴ�
               else if(choice==3)  // �ڴ����
			   {
                int flag;
                cout<<"��������Ҫ�ͷŵķ����ţ�";
                cin>>flag;
                free(flag);
			   }
              else if(choice==0) break; //�˳�
              else //�����������
			  {
              cout<<"�������������ԣ�"<<endl;
              continue;
			  }
	}
	return 0;
}*/
