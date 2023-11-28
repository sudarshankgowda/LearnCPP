#include<iostream>
#include<map>
using namespace std;
int main()
{
    int array[10]= {1,3, 2, 5, 19, 10, 2, 2, 9, 1};
    map<int, int> countMap;

    for(int element:array){
        if(countMap.find(element) != countMap.end()){
            countMap[element]++;
        }
        else{
            countMap[element]=1;
        }
    }

    for (const auto& x : countMap) {
        std::cout << "Element " << x.first << ": " << x.second << " times" << std::endl;
    }

}
