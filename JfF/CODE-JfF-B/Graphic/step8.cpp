/*
	Name: 
	Copyright: 
	Author: 
	Date: 28/11/14 20:11
	Description: 
*/

#include <iostream>
#include <cstdlib>
using namespace std;
const int DefaultVertices=30;
template <typename T,typename E>
struct Edge
{
	int dest;
	E cost;
	Edge<T,E> *link;
	Edge()
	{
	}
	Edge(int num,E weight):dest(num),cost(weight),link(NULL)
	{
	}
	bool operator !=(Edge<T,E>& R)const
	{
		return (dest!=R.dest)?true:false;
	}
}; 
template <typename T,typename E>
struct Vertex
{
	T data;
	Edge<T,E> *adj;
};
template<typename T,typename E>
class Graph
{
 public:
 	const E maxWeight;//这个地方原程序写的是const E maxWeight=.....; 
 	Graph(int sz=DefaultVertices);
 	~Graph();
 	bool GraphEmpty()const
 	{
 		if(numEdges==0)
 			return true;
 		else
 			return false;
 	}
 	bool GraphFull()const
 	{
 		if(numVertices==maxVertices||numEdges==maxVertices*(maxVertices-1)/2)
 			return true;
 		else
 			return false;
 	}
 	int NumberOfVertices()
 	{
 		return numVertices;
 	}
 	int NumberOfEdges()
 	{
 		return numEdges;
 	}
 	virtual T getValue(int i);
 	virtual E getWeight(int v1,int v2);
 	virtual int getFirstNeighbor(int v);
 	virtual int getNextNeighbor(int v,int w);
 	virtual bool insertVertex(const T&vertex);
 	virtual bool insertEdge(int v1,int v2,E cost);
 	virtual bool removeVertex(int v);
 	virtual bool removeEdge(int v1,int v2);
 protected:
 	int maxVertices;
 	int numEdges;
 	int numVertices;
 	virtual int getVertexPos(T vertex);
};
template <typename T,typename E>
class Graphlnk:public Graph<T,E>
{
	friend istream& operator>>(istream &in,Graphlnk <T,E> &G);
	friend ostream& operator<<(ostream &out,Graphlnk <T,E> &G);
	public:
		Graphlnk(int sz=DefaultVertices);
		~Graphlnk();
		T getValue(int i)
		{
			return (i>=0&&i<this->numVertices)?NodeTable[i].data:0;
		}
		E getWeight(int v1,int v2);
		bool insertVertex(const T&vertex);
		bool removeVertex(int v);
		bool insertEdge(int v1,int v2,E cost);
		bool removeEdge(int v1,int v2);
		int getFirstNeighbor(int v);
		int getNextNeightbor(int v,int w);
	private:
		Vertex<T,E>* NodeTable;
		int getVertexPos(const T vertex)
		{
			for(int i=0;i<this->numVertices;i++)
				if(NodeTable[i].data==vertex)
					return i;
			return -1;
		}
};
template <typename T,typename E>
Graphlnk<T,E>::Graphlnk(int sz)
{
	this->maxVertices=sz;
	this->numVertices=0;
	this->numEdges=0;
	NodeTable-new Vertex<T,E>[this->maxVertices];
	if(NodeTable==NULL)
	{
		cerr<<"The room distributed error!"<<endl;
		exit(1);
	}
	for(int i=0;i<this->maxVertices;i++)
	{
		NodeTable[i].adj==NULL;
	}
}
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
template <typename T,typename E>
bool Graphlnk<T,E>::insertVertex(const T &vertex)
{
	if(this->numVertices==this->maxVetices)
		return false;
	NodeTable[this->numVertices].data=vertex;
	this->numVertices++;
	return true;
}
template <typename T,typename E>
bool Graphlnk<T,E>::removeVertex(int v)
{
	if(this->numVertices==1||v<0||v>=this->numVertices)
		return false;
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
template<typename T,typename E>
bool Graphlnk<T,E>::insertEdge(int v1,int v2,E weight)
{
	if(v1>=0&&v1<this->numVertices&&v2>=0&&v2<this->numVertices)
	{
		Edge<T,E> *q,*p=NodeTable[v1].adj;
		while(p!=NULL&&p->dest!=v2)
			p=p->link;
		if(p!=NULL)
			return false;
		p=new Edge<T,E>;
		q=new Edge<T,E>;
		p->dest=v2;
		p->cost=weight;
		p->link=NodeTable[v1].adj;
		NodeTable[v1].adj=p;
		q->dest=v1;
		q->cost=weight;
		q->link=NodeTable[v2].adj;
		NodeTable[v2].adj=q;
		this->numEdges++;
		return true;
	}
	return 0;
}
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
int main()
{	
	return 0;
}























