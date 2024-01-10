#include<iostream>

int BinarySearch(int const array[], int length, int target)
{
    int low = 0;
    int high = length -1;
    int mid = 0;

    while (low <= high)
    {
        mid = (low+high)/2;

        if (array[mid] == target)
        {
            return mid;
        }
        else{
            if( array[mid] < target)
            {
                low = mid +1;
            }
            else
            {
                high = mid -1;
            }
        }
    }

    return -1;
}

int main()
{
    int array[]= {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int target = 5;
    int length = sizeof(array)/sizeof(array[0]);
    int index = BinarySearch(array, length, target);
    if (index != -1)
    {
        std::cout << "The target element found at position : "<< index << std::endl;
    }
    else{
        std::cout << "The target element is not found in array" << std::endl;
    }
    return 0;
}
