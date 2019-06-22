#include <iostream>

using namespace std;

//to heapify a subtree rooted with node i which is an index in arr[]
void heapify(int arr[], int len, int i)
{
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;

    //if left child is larger than parent
    if(l < len && arr[l] > arr[largest])
    {
        largest = l;
    }

    //if right child is larger than parent
    if(r < len && arr[r] > arr[largest])
    {
        largest = r;
    }

    if(largest != i)
    {
        swap(arr[i],arr[largest]);
        
        //recursively hapeify the affected sub tree
        heapify(arr, len, largest);
    }
}

void heapSort(int arr[], int len)
{
    //build heap
    for(int i = len / 2 - 1; i >= 0; i--)
    {
        heapify(arr, len, i);
    }

    for(int i = len - 1; i >= 0; i--)
    {
        //move current father to the end
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[10] = {5, 0, 9, 6, 7, 2, 1, 3, 8, 4};
    heapSort(arr, 10);
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
