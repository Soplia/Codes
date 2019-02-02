/*
	Name: 
	Copyright: 
	Author: 
	Date: 28/11/14 19:13
	Description: 
*/

#include <iostream>
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

 
int main()
{
	return 0;
}

















