#include<iostream>
using namespace std;
int main()
{
    int array[]={1,3,4,2,0,9,8,7,6,5};
    int lowest=0, secondlow=0;

    int numelements= sizeof(array)/sizeof(array[0]);
    if (numelements < 2){
        std::cerr << "Array should have at least two elements to find the second-lowest element." << std::endl;
        return 1;
    }

    lowest   = std::min(array[0], array[1]);
    secondlow = std::max(array[0], array[1]);

    for(int i=2; i < numelements; i++){
        if (array[i]<lowest){
            secondlow=lowest;
            lowest=array[i];
        }
        else if(array[i] < secondlow && array[i] != lowest){
            secondlow=array[i];
        }
    }
    cout << "Second highest element = " << secondlow << endl;
    cout << "First lowest element = " << lowest << endl;
    return 0;
}
