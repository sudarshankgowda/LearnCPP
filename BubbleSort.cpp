#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n -1; i ++)
    {
        for( int j = 0; j < n -i -1; j++){
            if (arr[j] > arr[j +1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int arr[]= {1,2, 0, 3,5,6,7,4,8,9};
    int len = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, len);
    cout << "After sorting the elements are as follows \n";
    for(int i = 0; i < len; i++)
        cout << arr[i] << " ";

    return 0;
}

