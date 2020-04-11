#include<iostream>
#include<cstdlib>
#define ElemType int
#include"BiTree.h"
#include"SqStack.h"
#include"SqQueue.h"

using namespace std;

void Insert(BiTree &T, ElemType e)
{
	BiTNode *p = T;	
	
	if(T == NULL)
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = e;
		T->lchild = NULL;
		T->rchild = NULL;
		return;
	}
	if(p->lchild == NULL || p->rchild != NULL)
	{ 
		Insert(p->lchild, e);
	}
	else
	{
		Insert(p->rchild, e);
	}
}

void Visit(BiTree T)
{
	cout << T->data;
}

void PreOrder(BiTree T)
{
	if(T != NULL)
	{
		Visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);	
	}	
}

void PreOrder2(BiTree T)
{
	BiTNode *Stack[100];
	BiTNode *p = T;
	int top = -1;
	while(p || top != -1)
	{
		if(p)
		{
			Visit(p);
			Stack[++top] = p;
			p = p->lchild;
		}
		else
		{
			p = Stack[top--];
			p = p->rchild;
		}
	}
}

void InOrder(BiTree T)
{
	if(T != NULL)
	{
		InOrder(T->lchild);
		Visit(T);
		PreOrder(T->rchild);
	}
}

void InOrder2(BiTree T)
{
	SqStack S;
	InitStack(S);
	BiTNode *p = T;
	while(p || !StackEmpty(S))
	{
		if(p)
		{
			Push(S, p);
			p = p->lchild;
		}
		else
		{
			Pop(S, p);
			Visit(p);
			p = p->rchild;
		}
	}
}

void PostOrder(BiTree T)
{
	if(T != NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		Visit(T);
	}
}

void PostOrder2(BiTree T)
{
	if(T != NULL)
	{
		BiTNode *Stack1[100];
		int top1 = -1;
		BiTNode *Stack2[100];
		int top2 = -1;
		BiTNode *p = NULL;
		Stack1[++top1] = T;
		while(top1 != -1)
		{
			p = Stack1[top1--];
			Stack2[++top2] = p;
			if(p->lchild != NULL)
			{
				Stack1[++top1] = p->lchild;
			}
			if(p->rchild != NULL)
			{
				Stack1[++top1] = p->rchild;
			}
		}
		while(top2 != -1)
		{
			p = Stack2[top2--];
			Visit(p);
		}
	}	
}


void PostOrder3(BiTree T)
{
	BiTNode *Stack[100];
	int top = -1;
	BiTNode *p = T;
	BiTNode *r = NULL;
	while(p || top != -1)
	{
		if(p)
		{
			Stack[++top] = p;
			p = p->lchild;
		}
		else
		{
			p = Stack[top];
			if(p->rchild && p->rchild != r)
			{
				p = p->rchild;
				Stack[++top] = p;
				p = p->lchild;
			}
			else
			{
				p = Stack[top--];
				Visit(p);
				r = p;
				p = NULL;
			}
		}
	}
}

void LevelOrder(BiTree T)
{
	SqQueue Q;
	InitQueue(Q);
	BiTree p;
	EnQueue(Q, T);
	while(!IsEmpty(Q))
	{
		DeQueue(Q, p);
		Visit(p);
		if(p->lchild != NULL)
		{
			EnQueue(Q, p->lchild);
		}
		if(p->rchild != NULL)
		{
			EnQueue(Q, p->rchild);
		}
	}
}

void InverLevel(BiTree T) //134 4 
{
	BiTNode *Stack[100];
	SqQueue Q;
	InitQueue(Q);
	BiTNode *p = T;
	int top = -1;
	if(T != NULL)
	{
		EnQueue(Q, T);
		while(IsEmpty(Q) == false)
		{
			DeQueue(Q, p);
			Stack[++top] = p;
			if(p->lchild)
			{
				EnQueue(Q, p->lchild);
			}
			if(p->rchild)
			{
				EnQueue(Q, p->rchild);
			}
		}
		while(top != -1)
		{
			p = Stack[top--];
			Visit(p);
		}
	}
}


int main()
{
	BiTree T = NULL;
	Insert(T, 3);
	Insert(T, 4);
	Insert(T, 9);
	Insert(T, 19);
	InOrder2(T);

	cout << "\n";
	system("pause");
} 
