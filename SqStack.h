#define MaxSize 50

using namespace std;

typedef struct{
	BiTNode *data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack &S)
{
	S.top = -1;
}

bool StackEmpty(SqStack S)
{
	if(S.top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Push(SqStack &S, BiTNode *x)
{
	if(S.top == MaxSize - 1)
	{
		return false;
	}
	S.data[++S.top] = x;
	return true;
}

bool Pop(SqStack &S, BiTNode *&x)
{
	if(S.top == -1)
	{
		return false;
	}
	x = S.data[S.top];
	S.top--;
	return true;
}

bool GetTop(SqStack &S, BiTNode *&x)
{
	if(S.top == -1)
	{
		return false;
	}
	x = S.data[S.top];
	return true;
}







