#include<iostream>

int main(){
    auto add = [](int a, int b)->int {return a+b;};
    int result = add(4, 8);

    std::cout << "Result of addition = " << result << std::endl;

    return 0;
}
