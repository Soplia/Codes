/*
	Name: 
	Copyright: 
	Author: 
	Date: 28/11/14 19:43
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
int main()
{
	return 0;
}






















