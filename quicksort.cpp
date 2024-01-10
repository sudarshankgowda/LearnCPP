#include<iostream>
using namespace std;
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low -1;

    for (int j = low; j <= high; j++)
    {
        if(arr[j] < pivot)
        {
            ++i;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i+1;
}

int quicksort(int arr[], int low, int high){
    if (low < high){
        int pivotIndex = partition(arr, low, high);

        //Recursively sort the subarrays
        quicksort(arr, low, pivotIndex -1);
        quicksort(arr, pivotIndex+1, high);
    }
}

int main()
{
    int myarray[]= {5,1,9,3,7};
    int length = sizeof(myarray)/sizeof(myarray[0]);

    quicksort(myarray, 0, length -1);
    std::cout << "Sorted array is : " << std::endl;

    for (int i = 0; i < length; i++)
    {
        std::cout << myarray[i] << " " ;
    }
    return 0;
}

