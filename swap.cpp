#include<iostream>
using namespace std;
void swappingFun(int *p, int *q)
{
    if ( a && b)
    {
        int m;
        m=*p;
        *p=*q;
        *q=m;
    }
}

int main()
{
    int x = 10, y = 20;
    swappingFun(&x, &y);
    cout<< "x = " << x << endl;
    cout<< "y = " << y << endl;
    return 0;
}
