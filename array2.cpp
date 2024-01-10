#include<iostream>

int linear_search(const int arr[], int length, int target)
{
    for (int i =0; i < length; i++)
    {
        if (arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main()
{
    int myarray[]= {1,4,3,7,5,9,6};

    int target = 19;

    int index = linear_search(myarray, sizeof(myarray)/sizeof(myarray[0]), target);

    if (index != -1){
        std::cout << "The target element found at position : " << index << std::endl;
    }
    else{
        std::cout << "The target element is not found in the array" << std::endl;
    }
    return 0;
}
