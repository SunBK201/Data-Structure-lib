#include <iostream>
#include "dslib.h"

using namespace std;

int main()
{
    SqList<double> L;
    SqList<double> K;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.data[3] = 4;
    L.length = 4;
    K.data[0] = 5;
    K.data[1] = 6;
    K.data[2] = 33;
    K.data[3] = 1;
    K.length = 4;
    SqList<double> R = L.SqList_Merge(K);
    R.SqList_PrintList();
    cout << R.SqList_Mode() << endl;
    R.SqList_PrintList();
}
