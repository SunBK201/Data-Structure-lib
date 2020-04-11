#include <cstdlib>
#define MaxSize 100
#define ElemType int

using namespace std;

typedef struct
{
    ElemType data[MaxSize];
    int top;
} SqStack;

bool SqStack_InitStack(SqStack &S)
{
    S.top = -1;
}

bool SqStack_IsEmpty(SqStack S)
{
    if (S.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool SqStack_Push(SqStack &S, ElemType e)
{
    if (S.top >= MaxSize - 1)
    {
        cout << "Stack is full!" << endl;
        return false;
    }
    S.data[++S.top] = e;
    return true;
}

bool SqStack_Pop(SqStack &S, ElemType &e)
{
    if (S.top == -1)
    {
        cout << "Stack is null!" << endl;
        return false;
    }
    e = S.data[S.top--];
    return true;
}