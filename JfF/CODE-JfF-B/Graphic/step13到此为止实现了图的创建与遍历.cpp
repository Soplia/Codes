/*
	Name: Graphic 
	compiler: Dev-cpp 
	Author: ����� 
	Date: 28/11/14 20:26
	Description: ���캯������ȡ��һ���ڵ㣬��ȡ��һ���ڵ㣬��ȡȨ�أ�����ڵ㣬ɾ���ڵ㣬
				����ߣ�ɾ���ߡ� 
*/
#include <iostream>
#include <cstdlib>
using namespace std;
//����Ĭ�϶���ĸ����� 
const int DefaultVertices=5;
//����ط�ԭ����д����const E maxWeight=.....; 
const int maxWeight=10000;
//����ߵĽṹ�� 
template <typename T,typename E>
struct Edge
{
	//�궨�����ߵ��յ㡣 
	int dest;
	//�����ߵ�Ȩ��ֵ�� 
	E cost;
	//ָ��ߵ�ָ�롣 
	Edge<T,E> *link;
	Edge()
	{
	}
	//����һ���� 
	Edge(int num,E weight):dest(num),cost(weight),link(NULL)
	{
	}
	//��������� 
	bool operator !=(Edge<T,E> &R)const
	{
		return (dest!=R.dest)?true:false;
	}
}; 
//����ڵ�Ľṹ�� 
template <typename T,typename E>
struct Vertex
{
	//�궨�����ֵ�Ƕ��١� 
	T data;
	//ָ���ڽӱߵ�ָ�������
	Edge<T,E> *adj; 
}; 
template <typename T,typename E>
class Graphlnk
{
 public:
 	void input(Graphlnk<T,E>& G);
 	void output(Graphlnk<T,E>& G);
 	//���캯����һ��Ĭ�ϵĴ�С��ֵ�� 
	Graphlnk(int sz=DefaultVertices);
	//��������. 
	~Graphlnk();
	//�β��Ǹýڵ��ڽڵ������е�λ�� 
	//����ֵ����Ӧ�Ķ��㼯���е���Ӧ�����ֵ�� 
	T getValue(int i)
	{
		return (i>=0&&i<this->numVertices)?NodeTable[i].data:0;
	}
	//��ȡȨ�� 
	E getWeight(int v1,int v2);
	//����һ������ �β�����������ֵ Ĭ���ǲ嵽������������ 
	bool insertVertex(const T &vertex);
	//ɾ��һ������ �β��Ƕ����λ�� 
	bool removeVertex(int v);
	//����һ���� �β���ʼ�� �յ� Ȩ�� 
	bool insertEdge(int v1,int v2,E cost);
	//ɾ��һ���� �β���ʼ�� �յ� 
	bool removeEdge(int v1,int v2);
	//��ȡ�����ߵĵ�һ���ڽӶ��� 
	int getFirstNeighbor(int v);
	//��ȡ�����ߵ��ڽӵĶ���ĵ�һ���ڽӶ��� 
	int getNextNeightbor(int v,int w);
	//����һ�����㼯 
	Vertex<T,E> *NodeTable;
	//��ȡ�����λ�ã������λ����ָ�����е�λ�á� 
	int getVertexPos(const T vertex)
	{
		for(int i=0;i<this->numVertices;i++)
			if(NodeTable[i].data==vertex)
				return i;
		return -1;
	}
	int NumberOfVertices()
	{
		return numVertices;
	}
	int NumberOfEdges()
	{
		return numEdges;
	}
	int maxVertices;
 	int numVertices;
 	int numEdges;
};
template <typename T,typename E>
Graphlnk<T,E>::Graphlnk(int sz)
{
	this->maxVertices=sz;
	this->numVertices=0;
	this->numEdges=0;
	NodeTable=new Vertex<T,E>[this->maxVertices];
	if(NodeTable==NULL)
	{
		cerr<<"The room distributed error!"<<endl;
		exit(1);
	}
	//�����㼯�е�ÿ��ָ��ߵ�ָ�븳ֵΪ�ա� 
	for(int i=0;i<this->maxVertices;i++)
	{
		NodeTable[i].adj==NULL;
	}
}
//�����Ļ���Ҫ��Ҫ���������㼯�Ϳ����ˡ� 
template <typename T,typename E>
Graphlnk<T,E>::~Graphlnk()
{
	for(int i=0;i<this->numVertices;i++)
	{
		Edge<T,E> *p=NodeTable[i].adj;
		while(p!=NULL)
		{
			NodeTable[i].adj=p->link;
			delete p;
			p=NodeTable[i].adj;
		}
	}
	delete [] NodeTable;
}
//��ȡ���������ͨ���������ĵ�һ�����ֵ�� 
template <typename T,typename E>
int Graphlnk<T,E>::getFirstNeighbor(int v)
{
	if(v!=-1)
	{
		Edge<T,E> *p=NodeTable[v].adj;
		if(p!=NULL)
			return p->dest;
	}
	return -1;	
}
//���ص�v��Ȩ��Ϊw�Ķ����ֵ�� 
template <typename T,typename E>
int Graphlnk<T,E>::getNextNeightbor(int v,int w)
{
	if(v!=-1)
	{
		Edge<T,E> *p=NodeTable[v].adj;
		while(p!=NULL&&p->dest!=w)
			p=p->link;
		if(p!=NULL&&p->link!=NULL)
			return p->link->dest;
	}
	return -1;
}
//����ĵ�һ�������Ǹñߵ�ʼ���λ�ã��ڶ��������Ǹñߵ��յ��ֵ�� 
template <typename T,typename E>
E Graphlnk<T,E>::getWeight(int v1,int v2)
{
	if(v1!=-1&&v2!=-1)
	{
		Edge<T,E> *p=NodeTable[v1].adj;
		while(p!=NULL&&p->dest!=v2)
		{
			p=p->link;
		}
		if(p!=NULL)
			return p->cost;
	}
	return 0;
}
//Ĭ����ֱ�ӽ����������뵽�������ĩβ 
template <typename T,typename E>
bool Graphlnk<T,E>::insertVertex(const T &vertex)
{
	if(this->numVertices==this->maxVertices)
		return false;
	NodeTable[this->numVertices].data=vertex;
	NodeTable[this->numVertices].adj=NULL;
	(this->numVertices)++;
	return true;
}
//ɾ�������Ķ��㣬����ע��Ҫɾ�����飬�ſ��ԣ�������ڽӱ�ʵ��ͼ�����㡣 
template <typename T,typename E>
bool Graphlnk<T,E>::removeVertex(int v)
{
	if(this->numVertices==1||v<0||v>=this->numVertices)
		return false;
	//����ߵ�����ָ�� 
	Edge<T,E> *p,*s,*t;
	int i,k;
	while(NodeTable[v].adj!=NULL)
	{
		p=NodeTable[v].adj;
		k=p->dest;
		s=NodeTable[k].adj;
		t=NULL;
		while(s!=NULL&&s->dest!=v)
		{
			t=s;
			s=s->link;
		}
		if(s!=NULL)
		{
			if(t==NULL)
				NodeTable[k].adj=s->link;
			else
				t->link=s->link;
			delete s;
		}
		NodeTable[v].adj=p->link;
		delete p;
		this->numEdges--;
	}
	this->numVertices--;
	NodeTable[v].data=NodeTable[this->numVertices].data;
	p=NodeTable[v].adj=NodeTable[this->numVertices].adj;
	while(p!=NULL)
	{
		s=NodeTable[p->dest].adj;
		while(s!=NULL)
			if(s->dest==this->numVertices)
			{
				s->dest=v;
				break;
			}
			else
				s=s->link;
	}
	return true;
}
//���Ҫ�����ε� 
template<typename T,typename E>
bool Graphlnk<T,E>::insertEdge(int v1,int v2,E weight)
{
	
	if(v1>=0&&v1<this->numVertices&&v2>=0&&v2<this->numVertices)
	{
		//cout<<"������if������"<<endl; 
		Edge<T,E> *q,*p,*p0,*p1;
//������ʱ�������� 
		//�����v2�Ǹñߵ��յ��ֵ. 
		//�����whileѭ����Ŀ�ľ���Ҫ��һ����û���ظ��ıߡ� 
		//while(p!=NULL&&p->dest!=v2)
//		{
//			cout<<"������whileѭ������"<<endl;
//			system("pause");
//			p=p->link;
//		}	
//		if(p!=NULL)
//			return false;
	//����������β���Ҫ����һ��λ������
	//���ڸ�ֵ��ʱ����Ҫ����һ����������� 
		int j,k;
		j=this->getValue(v1);
		k=this->getValue(v2);
		p=new Edge<T,E>;
		q=new Edge<T,E>;
		p->dest=k;
		p->cost=weight;
		p->link=(NodeTable[v1].adj);
		NodeTable[v1].adj=p;	
		q->dest=j;
		q->cost=weight;
		q->link=(NodeTable[v2].adj);
		NodeTable[v2].adj=q;
		(this->numEdges)++;
		//cout<<"�ߵ������Ѿ���һ��"<<endl;
		return true;		
	}
	return false;
}
//ɾ��Ҫɾ���ε� 
template <typename E,typename T>
bool Graphlnk<E,T>::removeEdge(int v1,int v2)
{
	if(v1!=-1&&v2!=-1)
	{
		Edge<T,E> *p=NodeTable[v1].adj,*q=NULL,*s=p;
		while(p!=NULL&&p->dest!=v2)
		{
			q=p;
			p=p->link;
		}
		if(p!=NULL)
		{
			if(p==s)
				NodeTable[v1].adj=p->link;
			else
				q->link=p->link;
			delete p;
		}
		else 
			return false;
		p=NodeTable[v2].adj;
		q=NULL;
		s=p;
		while(p->dest!=v1)
		{
			q=p;
			p=p->link;
		}
		if(p==s)
		NodeTable[v2].adj=p->link;
		else
			q->link=p->link;
		delete p;
		return true;
	}
	return false;
}
template<typename T,typename E>
void Graphlnk<T,E>::input(Graphlnk<T,E>& G)
{
	int i,j,k,n,m;
	T e1,e2;
	E weight;
	cout<<"Please input the numbers of the vertex:"<<endl;
	cin>>n;
	cout<<"Please input the numbers of the edge:"<<endl;
	cin>>m;
	cout<<"Start to input the VertexsList:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>e1;
		G.insertVertex(e1);
	}
	i=0;
	while(i<m)
	{
		cout<<"Please input the information of the edge in the form of(v1 v2 weight):"<<endl;
		cin>>e1;
		cin>>e2;
		cin>>weight;
		j=G.getVertexPos(e1);
		k=G.getVertexPos(e2);
		if(j==-1||k==-1)
			cout<<"the input is illagel!"<<endl;
		else
		{
			//����ط�Ӧ�ô������λ�� 
			G.insertEdge(j,k,weight);	
			i++;
		}
	}
}
template <typename T,typename E>
void Graphlnk<T,E>::output(Graphlnk<T,E>& G)
{
	int i,j,n,m;
	T e1,e2;
	E w;
	n=G.NumberOfVertices();
	m=G.NumberOfEdges();
	cout<<"The number of the vertex is:"<<n<<",";
	cout<<"The number of the edge is:"<<m<<endl;
	for(int i=0;i<n;i++)//��һ��Ե��Ǻ����Ӧ�ò��Բ��ǡ� 
		{
			e1=G.getValue(i);
			//cout<<"����forѭ������"<<endl;
			Edge<T,E> *p=G.NodeTable[i].adj;
			//p=p->link;
			while(p!=NULL)
			{
				w=p->cost;
				//w=G.getWeight(i,this->getNodeTable(j)); 
				if(w>0&&w<maxWeight)
				{	
					e2=p->dest;
					cout<<"("<<e1<<","<<e2<<","<<w<<")"<<endl;
					//system("pause");
				}
				// �������˾�Ȼ����Ϊ�Ŵ���λ�ö����� 
				//��ȷ�ǵľ�Ȼ����Ϊһ��λ�÷Ŵ��˾ͳ�����������⣬�������ˡ� 
				p=p->link;
			}	
		}
}
int main()
{
	Graphlnk<int,int> myGraphlnk(5);
	myGraphlnk.input(myGraphlnk);
	cout<<"The inpution for the graph had finished!"<<endl;
	//system("pause");
	myGraphlnk.output(myGraphlnk);
	return 0;
}



