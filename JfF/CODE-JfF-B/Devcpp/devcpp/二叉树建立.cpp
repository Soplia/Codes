//ABCD00E00F00G00测试数据 
#include  <stdio.h>
#include  <stdlib.h>

typedef char Elem;

typedef struct Node
{
    Elem data;
    struct Node *pLchild;
	struct Node *pRchild;
}BTreeNode, *BTree;

BTree CreateBTree(BTree T)//创建二叉树
{
	Elem x;

	scanf("%c", &x);

	if ('0' == x)
	{
		T = NULL;
	}
	else
	{
		T = (BTree) malloc (sizeof(BTreeNode));
		T->data = x;

		T->pLchild = CreateBTree(T->pLchild);
		T->pRchild = CreateBTree(T->pRchild);
	}

	return T;
}

void PostTraverseBTree(BTree T)//后序
{
	if (NULL != T)
	{
		PostTraverseBTree(T->pLchild);
		PostTraverseBTree(T->pRchild);
		printf("%c ", T->data);
	}
}

void InTraverseBTree(BTree T)//中序
{
	if (NULL != T)
	{
		InTraverseBTree(T->pLchild);
		printf("%c ", T->data);
		InTraverseBTree(T->pRchild); 
	}
}

void PreTraverseBTree(BTree T)//前序
{
	if (NULL != T)
	{
		printf("%c ", T->data);
		PreTraverseBTree(T->pLchild);
		PreTraverseBTree(T->pRchild);
	}
}

int main(void)
{
	BTree T = NULL;

	printf("请输入二叉树元素:\n");
	T = CreateBTree(T);
	printf("\n\n");

	printf("先序遍历:\n");
	PreTraverseBTree(T);
	printf("\n\n");

	printf("中序遍历:\n");
	InTraverseBTree(T);
	printf("\n\n");

	printf("后序遍历:\n");
	PostTraverseBTree(T);
	printf("\n\n");
} 

