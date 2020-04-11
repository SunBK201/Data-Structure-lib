#define MaxSize 50

typedef struct{
	BiTNode *data[MaxSize];
	int front;
	int rear;
}SqQueue;

void InitQueue(SqQueue &Q)
{
	Q.rear = Q.front = 0;
}

bool IsEmpty(SqQueue Q)
{
	if(Q.rear == Q.front)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool EnQueue(SqQueue &Q, BiTNode *x)
{
	if((Q.rear + 1) % MaxSize == Q.front)
	{
		return false;
	}
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}

bool DeQueue(SqQueue &Q, BiTNode * &x)
{
	if(Q.rear == Q.front)
	{
		return false;
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}
