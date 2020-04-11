#include<iostream>
#include<cstdlib>
#define ElemType int

typedef struct ThreadNode{
	ElemType data;
	struct ThreadNode *lchild, *rchild;
	int ltag, rtag;
}ThreadNode, *ThreadTree;

using namespace std;

void InThread(ThreadTree &p, ThreadTree &pre)
{
	
}

int main()
{
	int a = 110, *p;
	p = &a;
	int x = *(p++);
	cout << x;
	//p++;
	cout << *p;
	cout << a; 
}
