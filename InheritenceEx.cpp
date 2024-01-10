#include<iostream>
#include<vector>
using namespace std;
class shape{
public:
    virtual void draw() const {
        cout << "Drawing generic shape" << endl;
    }
};

class circle: public shape{
    public:
        void draw() const override{
            cout << "Drawing circle shape" << endl;
        }
};

class square: public shape{
    public:
        void draw() const override{
            cout << "Drawing square shape" << endl;
        }
};

int main()
{
    circle myCircle;
    square mySquare;

    myCircle.draw();
    mySquare.draw();

    std::vector<shape *> shapes;
    shapes.push_back(&myCircle);
    shapes.push_back(&mySquare);

    for(const auto & shape: shapes)
    {
        shape->draw();
    }
    return 0;
}
