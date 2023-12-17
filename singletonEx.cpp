#include<iostream>
using namespace std;

class Singleton {
private :
    static Singleton *instance;
    Singleton(){}
    Singleton(const Singleton & );
    Singleton& operator = (const Singleton&);

public:
    static Singleton* getInstance(){
        if (instance == nullptr){
            instance = new Singleton();
        }
        return instance;
    }
    void showMessage(){
        cout << "Hello, I am Singleton !" << endl;
    }
};
Singleton* Singleton::instance = nullptr;

int main()
{
    Singleton *singletonInstance1 = Singleton::getInstance();
    singletonInstance1->showMessage();

    Singleton *singletonInstance2 = Singleton::getInstance();

    cout << (singletonInstance1 == singletonInstance2 ? "true":"false") << endl;

    return 0;
}
