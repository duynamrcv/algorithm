#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

void createRandomArray(int arr[], int len);
int partition(int arr[], int len, int low, int high);
void quickSort(int arr[], int len, int low, int high);
void showValue(int value);
void showArray(int arr[], int len);
void showMember(int pivot, int low, int high);

int main()
{
    system("cls");
    int len = 12;
    int arr[len];
    createRandomArray(arr, len);
    quickSort(arr, len, 0, len-1);
    // Done, show sorted array
    cout << "Done!" << endl;
    cout << "The sorted array:" << endl;
    showArray(arr, len);
    return 0;
}

void createRandomArray(int arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        arr[i] = rand() % (2*len) + 1;
    }
}

int partition(int arr[], int len, int low, int high)
{
    int pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
    while(true)
    {
        while(left <= right && arr[left] < pivot) left++; // Find value that >= arr[pivot]
        while(right >= left && arr[right] > pivot) right--; // Find value that <= arr[pivot]
        if (left >= right) break; // Condition to exit loop
        
        //show pivot, two swap value
        showArray(arr, len);
        cout << endl << endl;
        showMember(pivot, arr[left], arr[right]);
        getch();     
        
        swap(arr[left], arr[right]); // swap two value
        
        cout << endl << endl;
        showArray(arr, len);
        getch();
        system("cls");
        
        left++; // increase left index
        right--; // decrease right index
    }

    showArray(arr, len);
    cout << endl << endl;
    cout << "Swap " << arr[left] << " and " << arr[high] << endl;
    getch();

    swap(arr[left], arr[high]);

    cout << endl << endl;
    showArray(arr, len);
    getch();
    system("cls");
    return left;
}

void quickSort(int arr[], int len, int low, int high)
{
    if(low < high)
    {
        int p = partition(arr, len, low, high);

        quickSort(arr, len, low, p - 1);
        quickSort(arr, len, p + 1, high);
    }
}

void showValue(int value)
{
    cout << value << "\t";
    for(int i = 0; i < value; i++) cout << "#";
    cout << endl;
}

void showArray(int arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        cout << i << "\t";
        showValue(arr[i]);
    }
}

void showMember(int pivot, int left, int right)
{
    cout << "Pivot value: " << pivot << endl;
    cout << "Swap " << left << " with " << right << endl;
}