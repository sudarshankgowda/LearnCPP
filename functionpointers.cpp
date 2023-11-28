#include<iostream>
using namespace std;
using BinaryOperation= double(*)(double, double);

double add(double a, double b)
{
    return a+b;
}
double sub(double a, double b)
{
    return a-b;
}
double mul(double a, double b)
{
    return a*b;
}
double div(double a, double b)
{
    if (b!=0){
        return a/b;
    }
    else{
        std::cerr<< "Divide by zero error" << endl;
        return 1;
    }
}
double PerformBinaryOperation(double x, double y, BinaryOperation operation)
{
    operation(x, y);
}

int main()
{
    int x, y;
    cout << "Enter the value for x and y: ";
    cin >> x >> y;
    char selectedoption;
    cout << "Select the operation ( +, -, *, / ): ";
    cin >> selectedoption;
    BinaryOperation selectedoperation=nullptr;
    switch(selectedoption)
    {
    case '+':
        selectedoperation=add;
        break;
    case '-':
        selectedoperation=sub;
        break;
    case '*':
        selectedoperation=mul;
        break;
    case '/':
        selectedoperation=div;
        break;
    default:
        cout << "Wrong option selected " << endl;
        return 1;
        break;
    }

    double result = PerformBinaryOperation(x, y,selectedoperation) ;
    cout << "Result : " << result << std::endl;

    return 0;
}
