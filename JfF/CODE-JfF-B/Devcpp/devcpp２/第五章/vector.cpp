#include <stdio.h>
#include <vector>
using namespace std;

struct edge
{
	int cost;
	int nextNode;
};

int main()
{
	int n=10;
	vector<edge> Edge[n];
	//��� 
	for(int i=0;i<n;i++) 
		Edge[i].clear();
	//����
	edge a,b;
	a.cost=3;
	a.nextNode=1;
	b.cost=3;
	b.nextNode=2;
	Edge[1].push_back(a);
	Edge[1].push_back(b);
	//����
	for(int i=0;i<Edge[1].size();i++)
	{
		printf("%d_%d\n",Edge[1][i].nextNode,Edge[1][i].cost);	
	}	
	//ɾ��
	Edge[1].erase(Edge[1].begin()+1,Edge[1].begin()+1);
	printf("ɾ����\n");
	//����
	for(int i=0;i<Edge[1].size();i++)
	{
		printf("%d_%d\n",Edge[1][i].nextNode,Edge[1][i].cost);	
	}
	return 0; 
}



























