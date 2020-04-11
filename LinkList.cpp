//LinkList
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode, *LinkList;

typedef struct DNode{
	int data;
	struct DNode *prior;
	struct DNode *next;
	int freq = 0;
}DNode, *DLinkList;

int ListLength(LinkList L)
{
	LNode *p = L->next; 
	int length = 0;
	while(p)
	{
		length++;
		p = p->next;
	}
	return length;
} 

int Max(LinkList L)
{
	LNode *p = L->next;
	LNode *max = L->next;
	if(!p)
	{
		return -1;
	}
	while(p->next)
	{
		p = p->next;
		if(max->data < p->data)
		{
			max = p;
		}
	}
	return max->data;
}

LinkList List_HeadInsert(LinkList &L)
{
	LNode *s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d", &x);
	while(x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}

LinkList List_TailInsert(LinkList &L)
{
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode *s, *r = L;
	scanf("%d", &x);
	while(x != 9999)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x); 
	}
	r->next = NULL;
	return L;
}

void Print_List(LinkList L)
{
	LNode *p = L->next;
	while(p != NULL)
	{
		cout << p->data;
		p = p->next;
	}
}

//p38 1.

void Del_X_Recursive(LinkList &L, int x)
{
	LNode *p;
	if(L == NULL)
	{
		return;
	}
	if(L->data == x)
	{
		p = L;
		L = L->next;
		free(p);
		Del_X_Recursive(L, x);
	}
	else
	{
		Del_X_Recursive(L->next, x);
	}
}

//p38 2.
void Del_X(LinkList &L, int x)
{
	LNode *p = L, *r;
	while(p->next != NULL)
	{
		if(p->next->data == x)
		{
			r = p->next;
			p->next = r->next;
			free(r);
		}
		else
		{
			p = p->next;
		}
	}
}

//p38 3.
void R_Print(LinkList L)
{
	if(L->next != NULL)
	{
		R_Print(L->next);	
	}
	cout << (L->data);
}

//p38 p4.
void Delete_Min(LinkList &L)
{
	LNode *minpre = L, *min;
	LNode *p = L->next;
	for(; p->next != NULL; p = p->next)
	{
		if(p->next->data < minpre->next->data)
		{
			minpre = p;
		}
	}
	min = minpre->next;
	minpre->next = min->next;
	free(min);
}

void Delete_Max(LinkList &L)
{
	LNode *maxpre = L, *max;
	LNode *p = L->next;
	for(; p->next != NULL; p = p->next)
	{
		if(p->next->data > maxpre->next->data)
		{
			maxpre = p;
		}
	}
	max = maxpre->next;
	maxpre->next = max->next;
	free(max);
}

//p38 p5.
LinkList Reverse(LinkList L)
{
	if(L->next == NULL)
	{
		return L;
	}
	LNode *p = Reverse(L->next);
	L->next->next = L;
	L->next = NULL;
	return p;
}

LinkList Reverse_1(LinkList L)
{
	LNode *p, *r;
	p = L->next;
	L->next = NULL;
	while(p != NULL)
	{
		r = p->next;
		p->next = L->next;
		L->next = p;
		p = r;
	}
	return L;
}

//p39 6.
void Sort(LinkList &L)
{
	LNode *p = L->next, *pre;
	LNode *r = p->next;
	p->next = NULL;
	p = r;
	while(p != NULL)
	{
		r = p->next;
		pre = L;
		while(pre->next != NULL && pre->next->data < p->data)
		{
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
}

//7.
void RangeDelete(LinkList &L, int min, int max)
{
	LNode *p = L, *d;
	while(p->next = NULL)
	{
		if(p->next->data > min && p->next->data < max)
		{
			d = p->next;
			p->next = d->next;
			free(d);
		}
		else
		{
			p = p->next;
		}		
	}
}

//8.
LinkList Search_1st_Common(LinkList L1, LinkList L2)
{
	int len1 = ListLength(L1), len2 = ListLength(L2);
	LinkList longlist, shortlist;
	int dist;
	if(len1 > len2)
	{
		longlist = L1->next;
		shortlist = L2->next;
		dist = len1 - len2;
	}
	else
	{
		longlist = L2->next;
		shortlist = L1->next;
		dist = len2 - len1;
	}
	while(dist--)
	{
		longlist = longlist->next;
	}
	while(longlist != NULL)
	{
		if(longlist == shortlist)
		{
			return longlist;
		}
		else
		{
			longlist = longlist->next;
			shortlist = shortlist->next;
		}
	}
	return NULL;
} 

//9.
void Min_Delete(LinkList &head)
{
	while(head->next != NULL)
	{
		LNode *premin = head;
		LNode *pre = head;
		while(pre->next != NULL)
		{
			if(pre->next->data < premin->next->data)
			{
				premin = pre;
			}
			pre = pre->next;
		}
		LNode *d = premin->next;
		premin->next = d->next;
		free(d);
	}
	free(head);
}

//10.
LinkList DisCreat_1(LinkList &A)
{
	int i = 0;
	LinkList B = (LinkList)malloc(sizeof(LNode));
	B->next = NULL;
	LNode *ra = A, *rb = B;
	LNode *p;
	p = A->next;
	A->next == NULL;
	while(p != NULL)
	{
		i++;
		if(i % 2 == 0)
		{
			rb->next = p;
			rb = p;
		}
		else
		{
			ra->next = p;
			ra = p;
		}
		p = p->next;
	}
	ra->next = NULL;
	rb->next = NULL;
	return B;
}

//11.
LinkList Dis_Creat_2(LinkList &A)
{
	LinkList B = (LinkList)malloc(sizeof(LNode));
	B->next = NULL;
	LNode *p = A->next, *q;
	LNode *ra = A;
	while(p != NULL)
	{
		ra->next = p; 
		ra = p;
		p = p->next;
		q = p->next;
		p->next = B->next;
		B->next = p;
		p = q;
	}
	ra->next = NULL;
	return B;
} 

//12.
void Del_Same(LinkList &L)
{
	LNode *p = L->next, *q;
	if(p == NULL)
	{
		return;
	}
	while(p->next != NULL)
	{
		q = p->next;
		if(p->data == q->data)
		{
			p->next = q->next;
			free(q);
		}
		else
		{
			p = p->next;
		}
	}
} 

//13.
void MergeList(LinkList &La, LinkList &Lb)
{
	LNode *r, *pa = La->next, *pb = Lb->next;
	La->next = NULL;
	while(pa && pb)
	{
		if(pa->data <= pb->data)
		{
			r = pa->next;
			pa->next = La->next;
			La->next = pa;
			
			pa = r;
		}
		else
		{
			r = pb->next;
			pb->next = La->next;
			La->next = pb;
			
			pb = r;
		}
	}
	if(pa)
	{
		pb = pa;
	}
	while(pb)
	{
		r = pb->next;
		pb->next = La->next;
		La->next = pb;
		pb = r;
	}
	free(Lb);
}

//14.
void Get_Common(LinkList A, LinkList B)
{
	LNode *p = A->next, *q = B->next;
	LNode *r, *s;
	LinkList C = (LinkList)malloc(sizeof(LNode));
	r = C;
	while(p != NULL && q != NULL)
	{
		if(p->data < q->data)
		{
			p = p->next;
		}
		else if(p->data > q->data)
		{
			q = q->next;
		}
		else
		{
			s = (LNode*)malloc(sizeof(LNode));
			s->data = p->data;
			r->next = s;
			r = s;
			p = p->next;
			q = q->next;
		}
	}
	r->next = NULL;
}

//15.
LinkList Union(LinkList &la, LinkList &lb)
{
	LNode *pa = la->next;
	LNode *pb = lb->next;
	LNode *r = la;
	LNode *u;
	while(pa && pb)
	{
		if(pa->data == pb->data)
		{
			r->next = pa;
			r = pa;
			pa = pa->next;
			u = pb;
			pb = pb->next;
			free(u);
		}
		else if(pa->data < pb->data)
		{
			u = pa;
			pa = pa->next;
			free(u);
		}
		else
		{
			u = pb;
			pb = pb->next;
			free(u);
		}
	}
	while(pa)
	{
		u = pa;
		pa = pa->next;
		free(u);
	}
	while(pb)
	{
		u = pb;
		pb = pb->next;
		free(u);
	}
	r->next = NULL;
	free(lb);
	return la;
}

//16.
int Pattern(LinkList A, LinkList B)
{
	LNode *p = A;
	LNode *pre = p;
	LNode *q = B;
	while(p && q)
	{
		if(p->data == q->data)
		{
			p = p->next;
			q = q->next;
		}
		else
		{
			pre = pre->next;
			p = pre;
			q = B;
		}
	}
	if(q == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//17.
int Symmetry(DLinkList L)
{
	DNode *p = L->next, *q = L->prior;
	while(p != q && p->next != q)
	{
		if(p->data == q->data)
		{
			p = p->next;
			q = q->prior;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

//18.
LinkList Link(LinkList &h1, LinkList &h2)
{
	LNode *p, *q;
	p = h1;
	while(p->next != h1)
	{
		p = p->next;
	}
	q = h2;
	while(q->next != h2)
	{
		q = q->next;
	}
	p->next = h2;
	q->next = h1;
	return h1;
}

//19.
void Del_All(LinkList &L)
{
	LNode *p, *pre, *minp, *minpre;
	while(L->next != L)
	{
		p = L->next;
		pre = L;
		minp = p;
		minpre = pre;
		while(p != L)
		{
			if(p->data < minp->data)
			{
				minp = p;
				minpre = pre;
			}
			pre = p;
			p = p->next;
		}
		printf("%d", minp->data);
		minpre->next = minp->next;
		free(minp);
	}
	free(L);
}

//p20.
DLinkList Locate(DLinkList &L, int x)
{
	DNode *p = L->next, *q;
	while(p && p->data != x)
	{
		p = p->next;
	}
	if(!p)
	{
		printf("no found!\n");
		exit(0);
	}
	else
	{
		p->freq++;
		p->next->prior = p->prior;
		p->prior->next = p->next;
		q = p->prior;
		while(q != L && q->freq <= p->freq)
		{
			q = q->prior;
		}
		p->next = q->next;
		q->next->prior = p;
		p->prior = q;
		q->next = p;
	}
	return p;
}

//p66 4.
int dc(LinkList L, int n)
{
	int i;
	char s[n/2];
	LNode *p = L->next;
	for(int i = 0; i < n / 2; i++)
	{
		s[i] = p->data;
	}
	i--;
	if(n % 2 == 1)
	{
		p = p->next;
	}
	while(p != NULL && s[i] == p->data)
	{			
		i--;
		p = p->next;
	}
	if(i == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

int main()
{
	 LinkList L = List_TailInsert(L);
	 Print_List(L); 
	 printf("\n");
	 //R_Print(L); 
	 cout << endl;
	 Del_X(L, 3);
	 Print_List(L);
}
