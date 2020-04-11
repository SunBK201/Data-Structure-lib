#include<iostream>
#define MaxSize 50

using namespace std;

typedef struct{
	char ch[MaxSize];
	int length;
}SString;

int BF(SString str, SString substr)
{
	int i = 1, j = 1, k = i;
	while(i <= str.length && j <= substr.length)
	{
		if(str.ch[i] == substr.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			j = 1;
			i = ++k;
		}
	}
	if(j > substr.length)
	{
		return k;
	}
	else
	{
		retrun 0;
	}
}

void GetNext(SString substr, int next[])
{
	int i = 1, j = 0;
	next[1] = 0;
	while(i < substr.length)
	{
		if(j == 0 || substr.ch[i] == substr.ch[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

int mian()
{
	
} 
