/*
	Name: 
	Copyright: 
	Author: 
	Date: 28/11/14 19:12
	Description: 
*/

#include <iostream>
using namespace std;
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
int main()
{
	return 0;
}
