#include<iostream>
#include<cstdio>

#define MaxSize 100

using namespace std; 

typedef struct{
	int data[MaxSize] = {1, 2, 3, 8, 1};
	int length = 5;
}SqList;


bool ListInsert(SqList &L, int i, int e)   //1 <= i <= L.length + 1
{
	if(i < 1 || i > L.length + 1 || L.length >= MaxSize)
	{
		return false;
	}
	for(int j = L.length; j >= i; j--)
	{
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	
	return true;
}

bool ListDelete(SqList &L, int i, int &e)
{
	if(i < 1 || i > L.length)
	{
		return false;
	}
	e = L.data[i - 1];
	for(int j = i; j < L.length; j++)
	{
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}

int LocateElem(SqList L, int e)
{
	for(int i = 0; i < L.length; i++)
	{
		if(L.data[i] == e)
		{
			return i + 1;
		}
	}
	return 0;
}

int Max(SqList L)
{
	int i;
	int max = 0;
	for(i = 0; i < L.length; i++)
	{
		if(L.data[i] > L.data[max])
		{
			max = i;
		}
	}
	return L.data[max];
}

void DeleteMax(int s[], int n)
{
	int i;
	int max = 0;
	int length = sizeof(s) / sizeof(int); 
	for(i = 0; s[i] < length; i++)
	{
		if(s[i] > s[max])
		{
			max = i;
		}
	}
	s[max] = s[length - 1];
	length--;
}


int main()
{
	SqList L;
	int s[] = {1,2,3,4,8,4,0};
	DeleteMax(L.data,2);
	for(int i = 0; i < L.length; i++)
	{
		cout << L.data[i];
	}
	cout << endl;
}
