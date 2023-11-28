#include<iostream>
using namespace std;
int main()
{
    int array[]={1,3,4,2,0,9,8,7,6,5};
    int highest=0, secondhighest=0;

    int numelements= sizeof(array)/sizeof(array[0]);
    if (numelements < 2){
        std::cerr << "Array should have at least two elements to find the second-highest element." << std::endl;
        return 1;
    }

    highest=std::max(array[0], array[1]);
    secondhighest=std::min(array[0], array[1]);

    for(int i=2; i < numelements; i++){
        if (array[i]>highest){
            secondhighest=highest;
            highest=array[i];
        }
        else if(array[i] > secondhighest && array[i] != highest){
            secondhighest=array[i];
        }
    }
    cout << "Second highest element = " << secondhighest << endl;
    return 0;
}
