#include<iostream>
#include<cstdlib>
#define ElemType int

using namespace std;

typedef struct LinkNode{
	ElemType data;
	struct LinkNode *next;
}LNode, *LinkStack;

void InitStack(LinkStack &S)
{
	S = (LNode*)malloc(sizeof(LNode));
	S->next = NULL;	
}

bool isEmpty(LinkStack S)
{
	if(S->next == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Push(LinkStack &S, ElemType x)
{
	LNode *p;
	p = (LNode *)malloc(sizeof(LNode));
	p->next == NULL;
	p->data = x;
	p->next = S->next;
	S->next = p;
	
	return true;
}

bool Pop(LinkStack &S, ElemType x)
{
	LNode *p;
	if(S->next == NULL)
	{
		return false;
	}
	p = S->next;
	x = p->data;
	S->next = p->next;
	free(p);
	
	return true;
}

int main()
{
	
}
