template <class ElemType>
class SqList
{
public:
    ElemType data[MaxSize];
    int length; //顺序表长度
public:
    void SqList_PrintList();                      //打印顺序表
    void SqList_BubbleSort();                    //顺序表由小到大冒泡排序
    void SqList_ListInsert(int i, ElemType e); //顺序插入1个数据
    void SqList_ListInsert_ToOrder(ElemType e); //在原顺序表有序的情况下，插入1个数据并保持有序
    void SqList_Reverse();                      //顺序表逆置
    void SqList_ReverseScope(int x, int y); // 指定范围内逆置
    ElemType SqList_DeleteMin(); //删除顺序表中最小值，并返回该最小值，空出的位置有最后一个元素填补
    void SqList_DeleteX(ElemType x); //删除所有值为x的元素
    void SqList_DeleteXY(ElemType x, ElemType y); //删除给定值x到y之间的元素, 0<=x<=y<length
    void SqList_DeleteSame();                     //删除重复的元素
    SqList SqList_Merge(SqList L);                  //合并顺序表
    int SqList_BinarySearch(ElemType e);            //二分查找指定元素，并返回查找元素的位置, 要求顺序表有序
    void SqList_RotateLeft(int p); //循环左移p个位置
    void SqList_RotateRight(int p); //循环右移p个位置
    ElemType SqList_Mode();         //返回顺序表中出现次数大于1/2的元素，摩尔投票法
};

template <class ElemType>
void SqList<ElemType>::SqList_PrintList() //打印顺序表
{
    for (int i = 0; i < length; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

template <class ElemType>
void SqList<ElemType>::SqList_ListInsert(int i, ElemType e) //顺序插入1个数据
{
    if (i < 0 || i > length - 1)
    {
        cout << "Visit Cross-Border!" << endl;
        exit(0);
    }
    if (length >= MaxSize)
    {
        cout << "Space is full!" << endl;
        exit(0);
    }
    int j;
    for (j = length; j > i; j--)
    {
        data[j] = data[j - 1];
    }
    data[j] = e;
    length++;
}

template <class ElemType>
void SqList<ElemType>::SqList_ListInsert_ToOrder(ElemType e) //在原顺序表有序的情况下，插入1个数据并保持有序
{
    if (length >= MaxSize)
    {
        cout << "Space is full!" << endl;
        exit(0);
    }
    int i = 0;
    while (data[i] < e && i < length)
    {
        i++;
    }
    for (int j = length; j > i; j--)
    {
        data[j] = data[j - 1];
    }
    data[i] = e;
    length++;
}

template <class ElemType>
void SqList<ElemType>::SqList_Reverse() //顺序表逆置
{
    ElemType temp;
    for (int i = 0, j = length - 1; i < j; i++, j--) //第一个元素与最和一个元素互换，第二个元素和倒数第二个元素互换，....依次直至i==j
    {
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
}

template <class ElemType>
ElemType SqList<ElemType>::SqList_DeleteMin() //删除顺序表中最小值，并返回该最小值，空出的位置有最后一个元素填补
{
    if(length == 0)
    {
        cout << "SqList's Length is 0 !";
        exit(0);
    }
    int min = 0; // 最小元素的位置 
    for (int i = 1; i < length; i++) //遍历整个顺序表，依次比较选出最小值
    {
        if(data[i] < data[min])
        {
            min = i;
        }
    }
    data[min] = data[length - 1]; //将最后一个元素覆盖掉最小值位置处
    length--;   
    return data[min];
}
template <class ElemType>
void SqList<ElemType>::SqList_DeleteX(ElemType x) //删除所有值为x的元素
{
    int j = 0;
    for (int i = 0; i < length; i++) 
    {
        if (data[i] != x)
        {
            data[j] = data[i];
            j++;
        }
    }
    length = j;
    return;
}

template <class ElemType>
void SqList<ElemType>::SqList_DeleteXY(ElemType x, ElemType y) //删除给定值x到y之间的元素
{
    if (y < x || length == 0)
    {
        cout << "SqList's Length is 0 !";
        exit(0);
    }
    int j = 0;
    for (int i = 0; i < length; i++)
    {
        if (data[i] < x || data[i] > y)
        {
            data[j] = data[i];
            j++;
        }
    }
    length = j;
}

template <class ElemType>
void SqList<ElemType>::SqList_DeleteSame() //删除重复的元素
{
    int j = 1;
    int flag;
    for (int i = 1; i < length; i++)
    {
        flag = 0;
        for (int k = 0; k < j; k++)
        {
            if(data[i] == data[k])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            data[j] = data[i];
            j++;
        }
    }
    length = j;
}

template <class ElemType>
SqList<ElemType> SqList<ElemType>::SqList_Merge(SqList L) //合并顺序表，并返回合并后的顺序表
{
    SqList<ElemType> R;
    if(MaxSize < length + L.length)
    {
        cout << "It's to long !";
        exit(0);
    }
    int i = 0;
    for (int j = 0; j < length; i++, j++)
    {
        R.data[i] = data[j];
    }
    for (int k = 0; k < L.length; k++, i++)
    {
        R.data[i] = L.data[k];
    }
    R.length = i;
    return R;
}

template <class ElemType>
void SqList<ElemType>::SqList_ReverseScope(int x, int y) // 指定范围内逆置, 0<=x<=y<length
{
    if(x < 0 || y >= length)
    {
        cout << "Input is invalid !";
        exit(0);
    }
    ElemType temp;
    for (int i = x, j = y; i < j; i++, j--)
    {
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
}

template <class ElemType>
void SqList<ElemType>::SqList_BubbleSort() //顺序表由小到大冒泡排序
{
    ElemType temp;
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - 1 - i; j++)
        {
            if(data[j] > data[j + 1])
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

template <class ElemType>
int SqList<ElemType>::SqList_BinarySearch(ElemType e) //二分查找指定元素，并返回查找元素的位置, 要求顺序表有序
{
    int left = 0;
    int right = length - 1;
    int mid;
    SqList_BubbleSort();
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(data[mid] == e)
        {
            return mid;
        }
        else if(data[mid] < e)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << e << "is not in SqList !";
}

template <class ElemType>
void SqList<ElemType>::SqList_RotateLeft(int p) //循环左移p个位置
{
    SqList_ReverseScope(0, p - 1);
    SqList_ReverseScope(p, length - 1);
    SqList_Reverse();
}

template <class ElemType>
void SqList<ElemType>::SqList_RotateRight(int p) //循环右移p个位置
{
    SqList_Reverse();
    SqList_ReverseScope(0, p - 1);
    SqList_ReverseScope(p, length - 1);
}

template <class ElemType>
ElemType SqList<ElemType>::SqList_Mode() //返回顺序表中出现次数大于1/2的元素，摩尔投票法
{
    ElemType c = data[0];
    int count = 1;
    for (int i = 1; i < length; i++)
    {
        if(data[i] == c)
        {
            count++;
        }
        else
        {
            if(count > 0)
            {
                count--;
            }
            else
            {
                c = data[i];
                count = 1;
            }
        }
    }
    count = 0;
    for (int i = 0; i < length; i++)
    {
        if(data[i] == c)
        {
            count++;
        }
    }
    if(count > length / 2)
    {
        return c;
    }
    else
    {
        cout << "null";
        exit(0);
    }
}
