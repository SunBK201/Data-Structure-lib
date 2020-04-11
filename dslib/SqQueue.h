#include <cstdlib>
#include "SqStack.h"
#define MaxSize 100
#define ElemType int

using namespace std;

typedef struct
{
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

bool SqQueue_InitQueue(SqQueue &Q)
{
    Q.rear = Q.front = 0;
    return true;
}

bool SqQueue_IsEmpty(SqQueue Q)
{
    if (Q.rear == Q.front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool SqQueue_EnQueue(SqQueue &Q, ElemType e)
{
    if ((Q.rear + 1) % MaxSize == Q.front)
    {
        cout << "Queue is full!" << endl;
        return false;
    }
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool SqQueue_DeQueue(SqQueue &Q, ElemType &e)
{
    if (Q.rear == Q.front)
    {
        cout << "Queue is null!" << endl;
        return false;
    }
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

bool SqQueue_Reverse(SqQueue &Q)
{
    SqStack S;
    ElemType x;
    SqStack_InitStack(S);
    while (!SqQueue_IsEmpty(Q))
    {
        SqQueue_DeQueue(Q, x);
        SqStack_Push(S, x);
    }
    SqQueue_InitQueue(Q);
    while (!SqStack_IsEmpty(S))
    {
        SqStack_Pop(S, x);
        SqQueue_EnQueue(Q, x);
    }
    return true;
}