#include<iostream>
#define MaxSize 50
#define ElemType int

using namespace std;

typedef struct{
	ElemType data[MaxSize];
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

bool Push(SqStack &S, ElemType x)
{
	if(S.top == MaxSize - 1)
	{
		return false;
	}
	S.data[++S.top] = x;
	return true;
}

bool Pop(SqStack &S, ElemType &x)
{
	if(S.top == -1)
	{
		return false;
	}
	x = S.data[S.top--];
	return true;
}

bool GetTop(SqStack &S, ElemType &x)
{
	if(S.top == -1)
	{
		return false;
	}
	x = S.data[S.top];
	return true;
}


//p66 3.2
int Judge(char A[])
{
	int i = 0;
	int j = k = 0;
	while(A[i] != '\0')
	{
		switch(A[i])
		{
			case 'I': j++;
			break;
			case 'O': k++;
			if(k > j)
			{
				cout << "���зǷ�\n ";
				exit(0);
			} 
		}
	}
	if(j != k)
	{
		cout << "���зǷ�\n ";
		return false;
	}
	else
	{
		cout << "���кϷ� \n ";
		return true;
	}
} 


int main()
{
	
}




