#include <iostream>

using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int len1 = mid - left + 1;
    int len2 = right - mid;

    //create temp arrays
    int l_arr[len1], r_arr[len2];

    //copy data to temp arrays
    for(i = 0; i < len1; i++) l_arr[i] = arr[left + i];
    for(j = 0; j < len2; j++) r_arr[j] = arr[mid + 1 + j];
    
    //merge the temp arrays back
    i = 0, j = 0, k = left;
    while(i < len1 && j < len2)
    {
        if(l_arr[i] <= r_arr[j])
        {
            arr[k] = l_arr[i];
            i++;
        }
        else
        {
            arr[k] = r_arr[j];
            j++;
        }
        k++;
    }

    while(i < len1)
    {
        arr[k] = l_arr[i];
        k++, i++;
    }

    while(j < len2)
    {
        arr[k] = r_arr[j];
        j++, k++;
    }
    return;
}

void mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right - 1)/2;

        //sort two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
    return;
}

int main()
{
    int arr[10] = {2, 0, 9, 8, 6, 1, 3, 7, 5, 4};
    mergeSort(arr, 0, 9);
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
