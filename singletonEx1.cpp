#include<iostream>
using namespace std;

class Singleton{
private:
    static Singleton* instance;
    Singleton(){}
    Singleton(const Singleton& )
    {
        cout<< "Singleton copy constructor" << endl;
    }
    Singleton& operator = (const Singleton&){
    cout << "Singleton assignment operator " << endl;
    }
public:
    static Singleton * getInstance(){
        if(instance == nullptr)
        {
            instance = new Singleton();
        }
        return instance;
    }
    void showMessage(){
        cout << "Hello, from the Singleton" << endl;
    }
};
Singleton* Singleton::instance = nullptr;

int main()
{
    Singleton * singletonInstance1 = Singleton::getInstance();
    singletonInstance1->showMessage();

    //Singleton singletonInstance2 = *singletonInstance1;
    Singleton singletonInstance3;
    singletonInstance3 = *singletonInstance1 ;

    return 0;
}
