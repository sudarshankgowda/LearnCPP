#include<iostream>
using namespace std;
class myclass{
private:
    int data;
public:
    myclass(){}
    myclass(int value): data(value){}
    myclass(myclass &obj){
        data = obj.data;
    }
    void display()
    {
        std::cout << "Data = " << data << std::endl;
    }
};

int main()
{
    myclass obj1;
    myclass obj2(30);
    myclass obj3=obj2;

    obj2.display();
    obj3.display();
    return 0;
}
