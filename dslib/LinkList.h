#include <cstdlib>
#define MaxSize 100
#define ElemType int

using namespace std;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList, *CirLinkList;

typedef struct DNode
{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
} DNode, *DLinkList;

bool LinkList_InitList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
}

void LinkList_PrintList(LinkList L)
{
    LNode *p = L->next;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int LinkList_ListLength(LinkList L)
{
    int length;
    LNode *p = L;
    while (p)
    {
        p = p->next;
        length++;
    }
    return length - 1;
}

bool LinkList_HeadInsert(LinkList &L, ElemType e)
{
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = e;
    p->next = L->next;
    L->next = p;
    return true;
}

bool LinkList_TailInsert(LinkList &L)
{
    LinkList_InitList(L);
    LNode *q = L;
    LNode *p;
    ElemType e;
    cin >> e;
    while (e != 9999)
    {
        p = (LNode *)malloc(sizeof(LNode));
        p->data = e;
        q->next = p;
        q = p;
        cin >> e;
    }
    q->next = NULL;
    return true;
}

bool LinkList_Insert_Location(LinkList &L, int i, ElemType e)
{
    if (i < 0 || i > LinkList_ListLength(L))
    {
        cout << "Cross the border!" << endl;
        return false;
    }
    LNode *p = L;
    int j = 0;
    while (p->next && j < i)
    {
        p = p->next;
        j++;
    }
    LNode *q = (LNode *)malloc(sizeof(LNode));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return true;
}

bool LinkList_Insert_beforex(LinkList &L, ElemType x, ElemType y)
{
    LNode *p = L;
    while (p->next)
    {
        if (p->next->data == x)
        {
            break;
        }
        p = p->next;
    }
    if (p->next == NULL)
    {
        cout << "x is not exist!" << endl;
        return false;
    }
    LNode *q = (LNode *)malloc(sizeof(LNode));
    q->data = y;
    q->next = p->next;
    p->next = q;
    return true;
}

bool LinkList_Delete_X(LinkList &L, ElemType x)
{
    LNode *p = L;
    LNode *temp;
    while (p->next)
    {
        if (p->next->data == x)
        {
            temp = p->next;
            p->next = temp->next;
            free(temp);
        }
        else
        {
            p = p->next;
        }
    }
    return true;
}

bool LinkList_Delete_XY(LinkList &L, ElemType x, ElemType y)
{
    LNode *p = L;
    LNode *temp;
    while (p->next && p->next->data < y)
    {
        if (p->next->data > x)
        {
            temp = p->next;
            p->next = p->next->next;
            free(temp);
        }
        else
        {
            p = p->next;
        }
    }
    return true;
}

bool LinkList_Reverse(LinkList &L)
{
    if (L->next == NULL)
    {
        cout << "LinkList is NULL!" << endl;
        return false;
    }
    LNode *p = L->next->next;
    LNode *q;
    L->next->next = NULL;
    while (p)
    {
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
    return true;
}

bool LinkList_Sort(LinkList &L)
{
    LNode *p = L->next;
    LNode *q = p->next;
    LNode *k;
    p->next = NULL;
    while (q)
    {
        k = q->next;
        if (q->data <= p->data)
        {
            q->next = p;
            L->next = q;
        }
        else
        {
            while (p->next != NULL && p->next->data < q->data)
            {
                p = p->next;
            }
            q->next = p->next;
            p->next = q;
            p = L->next;
        }
        q = k;
    }
    return true;
}