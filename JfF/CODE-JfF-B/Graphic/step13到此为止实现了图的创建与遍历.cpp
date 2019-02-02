/*
	Name: Graphic 
	compiler: Dev-cpp 
	Author: 解家瑞 
	Date: 28/11/14 20:26
	Description: 构造函数，获取第一个节点，获取下一个节点，获取权重，插入节点，删除节点，
				插入边，删除边。 
*/
#include <iostream>
#include <cstdlib>
using namespace std;
//设置默认定点的个数。 
const int DefaultVertices=5;
//这个地方原程序写的是const E maxWeight=.....; 
const int maxWeight=10000;
//构造边的结构体 
template <typename T,typename E>
struct Edge
{
	//标定这条边的终点。 
	int dest;
	//这条边的权重值。 
	E cost;
	//指向边的指针。 
	Edge<T,E> *link;
	Edge()
	{
	}
	//创建一条边 
	Edge(int num,E weight):dest(num),cost(weight),link(NULL)
	{
	}
	//重载运算符 
	bool operator !=(Edge<T,E> &R)const
	{
		return (dest!=R.dest)?true:false;
	}
}; 
//定义节点的结构体 
template <typename T,typename E>
struct Vertex
{
	//标定顶点的值是多少。 
	T data;
	//指向邻接边的指针变量。
	Edge<T,E> *adj; 
}; 
template <typename T,typename E>
class Graphlnk
{
 public:
 	void input(Graphlnk<T,E>& G);
 	void output(Graphlnk<T,E>& G);
 	//构造函数有一个默认的大小的值。 
	Graphlnk(int sz=DefaultVertices);
	//析构函数. 
	~Graphlnk();
	//形参是该节点在节点数组中的位置 
	//返回值是相应的顶点集合中的相应顶点的值。 
	T getValue(int i)
	{
		return (i>=0&&i<this->numVertices)?NodeTable[i].data:0;
	}
	//获取权重 
	E getWeight(int v1,int v2);
	//插入一个顶点 形参是这个顶点的值 默认是插到顶点数组的最后 
	bool insertVertex(const T &vertex);
	//删除一个顶点 形参是顶点的位置 
	bool removeVertex(int v);
	//插入一条边 形参是始点 终点 权重 
	bool insertEdge(int v1,int v2,E cost);
	//删除一条边 形参是始点 终点 
	bool removeEdge(int v1,int v2);
	//获取这条边的第一个邻接顶点 
	int getFirstNeighbor(int v);
	//获取这条边的邻接的顶点的第一个邻接顶点 
	int getNextNeightbor(int v,int w);
	//创建一个顶点集 
	Vertex<T,E> *NodeTable;
	//获取顶点的位置，这里的位置是指数组中的位置。 
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
	//给顶点集中的每个指向边的指针赋值为空。 
	for(int i=0;i<this->maxVertices;i++)
	{
		NodeTable[i].adj==NULL;
	}
}
//析构的话主要是要析构掉顶点集就可以了。 
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
//获取与这个顶点通过变相连的第一个点的值。 
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
//返回第v个权重为w的顶点的值。 
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
//这里的第一个参数是该边的始点的位置，第二个参数是该边的终点的值。 
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
//默认是直接将这个顶点插入到给数组的末尾 
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
//删除给定的顶点，这里注意要删除两遍，才可以，这就是邻接表实现图的弱点。 
template <typename T,typename E>
bool Graphlnk<T,E>::removeVertex(int v)
{
	if(this->numVertices==1||v<0||v>=this->numVertices)
		return false;
	//定义边的三个指针 
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
//插边要插两次的 
template<typename T,typename E>
bool Graphlnk<T,E>::insertEdge(int v1,int v2,E weight)
{
	
	if(v1>=0&&v1<this->numVertices&&v2>=0&&v2<this->numVertices)
	{
		//cout<<"进入了if里面了"<<endl; 
		Edge<T,E> *q,*p,*p0,*p1;
//这里暂时不作处理 
		//这里的v2是该边的终点的值. 
		//这里的while循环的目的就是要找一找有没有重复的边。 
		//while(p!=NULL&&p->dest!=v2)
//		{
//			cout<<"进入了while循环里了"<<endl;
//			system("pause");
//			p=p->link;
//		}	
//		if(p!=NULL)
//			return false;
	//这个函数的形参需要的是一个位置坐标
	//而在赋值的时候需要的是一个具体的数字 
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
		//cout<<"边的条数已经加一了"<<endl;
		return true;		
	}
	return false;
}
//删边要删两次的 
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
			//这个地方应该传顶点的位置 
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
	for(int i=0;i<n;i++)//这一句对但是后面的应该不对才是。 
		{
			e1=G.getValue(i);
			//cout<<"进入for循环里了"<<endl;
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
				// 气死我了竟然是因为放错了位置而已吗？ 
				//的确是的竟然是因为一个位置放错了就出现了这个问题，气死我了。 
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



