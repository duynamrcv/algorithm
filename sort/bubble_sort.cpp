#include <iostream>

using namespace std;

void bubbleSort(int arr[], int len)
{
    for(int i = 0; i < len - 1; i++)
    {
        for(int j = i; j < len; j++)
        {
            if(arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return;
}

int main()
{
    int arr[10] = {2, 5, 1, 6, 9, 3, 0, 8, 7, 4};
    
    bubbleSort(arr, 10);
    
    for(int i = 0; i < 10; i++)
    {  
        cout << arr[i] << " ";
    }
    return 0;
}
