#include<iostream>

using namespace std;

class simpleClass{
private:
    int y;
public:
    simpleClass()
    {
        y = 0;
    }
    void SetValues(int a)
    {
        y = a;
    }

    void printValues()
    {
        cout << "y Value = " << y << endl;
    }
};

int main()
{
    simpleClass M;
    M.printValues();
    M.SetValues(19);
    M.printValues();
    return 0;
}
