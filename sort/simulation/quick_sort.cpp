#include <iostream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

void simulation(int arr[], int len, int part, int high)
{
    sleep(1);
    system("clear");
    for(int i = 0; i < len; i++)
    {
        cout << arr[i];
        if(i == part) cout << "* ";
        else if(i == high) cout << "/ ";
        else cout << "  ";
        for(int j = 0; j < arr[i]; j++)
        {
            cout << "#";
        }
        cout << endl;
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        //if current element <= pivot
        if(arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, int len)
{
    if(low < high)
    {
        int p = partition(arr, low, high);

        simulation(arr, len, p, high);

        quickSort(arr, low, p - 1, len);
        quickSort(arr, p + 1, high, len);
    }
}

int main()
{
    int arr[10] = {1, 6, 8, 2, 5, 4, 9, 0, 3, 7};
    quickSort(arr, 0, 9, 10);
    return 0;
}
