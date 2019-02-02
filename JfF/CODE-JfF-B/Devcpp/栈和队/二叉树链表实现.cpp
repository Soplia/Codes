#include <iostream>
#include <iomanip>
#include "1.cpp"
using namespace std;
class TreeNode
{
 public:
 	int data;
 	TreeNode *lNext;
 	TreeNode *rNext;
 public:
 	void set(int a);
 	TreeNode();
 	TreeNode(int a);
};
TreeNode::TreeNode()
{
	this->set(-1);
}
TreeNode::TreeNode(int a)
{
	this->set(a);
}
void TreeNode::set(int a)
{
	this->data=a;
	this->rNext=NULL;
	this->lNext=NULL;
}
 
class Tree
{
 public:
 	TreeNode *root;
 public:
 	Tree();
 	TreeNode *insert(TreeNode *a,int b);
 	void insert(int a);
 	TreeNode *find(int a);
 	void print();
};
Tree::Tree()
{
	this->root=NULL;
}
TreeNode* Tree::insert(TreeNode *a,int b)
{
	if(a==NULL)
		return new TreeNode(b);
	else if(b<a->data)
	{
		a->lNext=insert(a->lNext,b);
		return a;
	}
	else
	{
		a->rNext=insert(a->rNext,b);
		return a;
	}
}
void Tree::insert(int a)
{
	root=insert(root,a); 
}
TreeNode* Tree::find(int a)
{
	TreeNode *temp=root;
	while(temp!=NULL)
	{
		if(temp->data==a)
			return temp;
		else if(temp->data<a)
			temp=temp->lNext;
		else
			temp=temp->rNext;
	}
}
void Tree::print()
{
	stack<TreeNode*> *stack=new stack<TreeNode*>();
	TreeNode *temp;
	stack->insert(root);
	while(!stack->isEmpty())
	{
		temp=stack->remove();
		if(temp!=NULL)
		{
			cout<<setw(5)<<temp->data;
			stack->insert(temp->lNext);
			stack->insert(temp->rNext);
		}
	}
}
int main()
{
	Tree *tree=new Tree();
	for(int i=1;i<11;i++)
		tree->insert(i);
	tree->print();
	return 0;
}
























