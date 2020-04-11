#include <cstdlib>
#define MaxSize 100
#define ElemType int

using namespace std;

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct
{
    BiTree data[MaxSize];
    int front, rear;
} TreeQueue;

typedef struct
{
    BiTree data[MaxSize];
    int top;
} TreeStack;

bool TreeQueue_InitQueue(TreeQueue &Q)
{
    Q.rear = Q.front = 0;
    return true;
}

bool TreeQueue_IsEmpty(TreeQueue Q)
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

bool TreeQueue_EnQueue(TreeQueue &Q, BiTree e)
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

bool TreeQueue_DeQueue(TreeQueue &Q, BiTree &e)
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

bool TreeStack_InitStack(TreeStack &S)
{
    S.top = -1;
}

bool TreeStack_IsEmpty(TreeStack S)
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

bool TreeStack_Push(TreeStack &S, BiTree e)
{
    if (S.top >= MaxSize - 1)
    {
        cout << "Stack is full!" << endl;
        return false;
    }
    S.data[++S.top] = e;
    return true;
}

bool TreeStack_Pop(TreeStack &S, BiTree &e)
{
    if (S.top == -1)
    {
        cout << "Stack is null!" << endl;
        return false;
    }
    e = S.data[S.top--];
    return true;
}

BiTNode *q[100];
int front = 0;
int rear = 0;
bool BiTree_LevelInsert(BiTree &T, ElemType e)
{
    if (T == NULL)
    {
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = e;
        T->lchild = NULL;
        T->rchild = NULL;
        q[rear] = T;
        rear = (rear + 1) % MaxSize;
        return true;
    }
    else
    {
        BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
        p->data = e;
        p->lchild = NULL;
        p->rchild = NULL;

        BiTNode *k = q[front];
        if (k->lchild == NULL)
        {
            k->lchild = p;
        }
        else
        {
            k->rchild = p;
            front = (front + 1) % MaxSize;
        }
        q[rear] = p;
        rear = (rear + 1) % MaxSize;
    }
    return true;
}

void BiTree_Visit(BiTree &T)
{
    cout << T->data << " ";
}

void BiTree_PreOrder(BiTree T)
{
    if (T != NULL)
    {
        BiTree_Visit(T);
        BiTree_PreOrder(T->lchild);
        BiTree_PreOrder(T->rchild);
    }
}

void BiTree_PreOrder_NoRecursive(BiTree T)
{
    TreeStack S;
    TreeStack_InitStack(S);
    BiTNode *p = T;
    while (p || !TreeStack_IsEmpty(S))
    {
        if (p)
        {
            BiTree_Visit(p);
            TreeStack_Push(S, p);
            p = p->lchild;
        }
        else
        {
            TreeStack_Pop(S, p);
            p = p->rchild;
        }
    }
}

void BiTree_InOrder(BiTree T)
{
    if (T != NULL)
    {
        BiTree_InOrder(T->lchild);
        BiTree_Visit(T);
        BiTree_InOrder(T->rchild);
    }
}

void BiTree_Inorder_NoRecursive(BiTree T)
{
    TreeStack S;
    TreeStack_InitStack(S);
    BiTNode *p = T;
    while (p || !TreeStack_IsEmpty(S))
    {
        if (p)
        {
            TreeStack_Push(S, p);
            p = p->lchild;
        }
        else
        {
            TreeStack_Pop(S, p);
            BiTree_Visit(p);
            p = p->rchild;
        }
    }
}

void BiTree_PostOrder(BiTree T)
{
    if (T != NULL)
    {
        BiTree_PostOrder(T->lchild);
        BiTree_PostOrder(T->rchild);
        BiTree_Visit(T);
    }
}

void BiTree_PostOrder_NoRecursive(BiTree T)
{
    TreeStack S1;
    TreeStack S2;
    TreeStack_InitStack(S1);
    TreeStack_InitStack(S2);
    BiTNode *p = T;
    while (p || !TreeStack_IsEmpty(S1))
    {
        if (p)
        {
            TreeStack_Push(S2, p);
            TreeStack_Push(S1, p);
            p = p->rchild;
        }
        else
        {
            TreeStack_Pop(S1, p);
            p = p->lchild;
        }
    }
    while (!TreeStack_IsEmpty(S2))
    {
        TreeStack_Pop(S2, p);
        BiTree_Visit(p);
    }
}

void BiTree_LevelOrder(BiTree T)
{
    TreeQueue Q;
    TreeQueue_InitQueue(Q);
    BiTree p;
    TreeQueue_EnQueue(Q, T);
    while (!TreeQueue_IsEmpty(Q))
    {
        TreeQueue_DeQueue(Q, p);
        BiTree_Visit(p);
        if (p->lchild != NULL)
        {
            TreeQueue_EnQueue(Q, p->lchild);
        }
        if (p->rchild != NULL)
        {
            TreeQueue_EnQueue(Q, p->rchild);
        }
    }
}

void BiTree_Count(BiTree T, int &n)
{
    if (T != NULL)
    {
        n++;
        BiTree_Count(T->lchild, n);
        BiTree_Count(T->rchild, n);
    }
}

void BiTree_Exchange(BiTree &T)
{
    if (!T)
    {
        return;
    }
    BiTNode *temp;
    temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;
    BiTree_Exchange(T->lchild);
    BiTree_Exchange(T->rchild);
}