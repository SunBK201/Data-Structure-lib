#include<iostream>
#include<cstdlib>
#define ElemType int

using namespace std;

typedef struct LinkNode{
	ElemType data;
	struct LinkNode *next;
}LinkNode;

typedef struct{
	LinkNode *front;
	LinkNode *rear;
}LinkQueue;

void InitQueue(LinkQueue &Q)
{
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q)
{
	if(Q.front = Q.rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void EnQueue(LinkQueue &Q, ElemType x)
{
	LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}

bool DeQueue(LinkQueue &Q, ElemType &x)
{
	if(Q.front == Q.rear)
	{
		return false;
	}
	LinkNode *p = Q.front->next;
	x = p->data;
	Q.front->next = p->next;
	if(Q.rear == p)
	{
		Q.rear = Q.front;
	}
	free(p);
	return true;
}

int main()
{
	
}
