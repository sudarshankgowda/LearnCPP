#include <iostream>

using namespace std;

int main()
{
    int sum=0;
    int A[]={1,2,5,8,9};

    for (auto x:A)
        sum += x;

    cout << "Sum = " << sum << endl;

    return 0;
}
