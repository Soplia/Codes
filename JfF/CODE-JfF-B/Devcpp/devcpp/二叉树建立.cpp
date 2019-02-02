//ABCD00E00F00G00�������� 
#include  <stdio.h>
#include  <stdlib.h>

typedef char Elem;

typedef struct Node
{
    Elem data;
    struct Node *pLchild;
	struct Node *pRchild;
}BTreeNode, *BTree;

BTree CreateBTree(BTree T)//����������
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

void PostTraverseBTree(BTree T)//����
{
	if (NULL != T)
	{
		PostTraverseBTree(T->pLchild);
		PostTraverseBTree(T->pRchild);
		printf("%c ", T->data);
	}
}

void InTraverseBTree(BTree T)//����
{
	if (NULL != T)
	{
		InTraverseBTree(T->pLchild);
		printf("%c ", T->data);
		InTraverseBTree(T->pRchild); 
	}
}

void PreTraverseBTree(BTree T)//ǰ��
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

	printf("�����������Ԫ��:\n");
	T = CreateBTree(T);
	printf("\n\n");

	printf("�������:\n");
	PreTraverseBTree(T);
	printf("\n\n");

	printf("�������:\n");
	InTraverseBTree(T);
	printf("\n\n");

	printf("�������:\n");
	PostTraverseBTree(T);
	printf("\n\n");
} 

