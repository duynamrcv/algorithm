#include <iostream>

using namespace std;

void insertion_sort(int arr[], int len)
{
	for(int i = 1; i < len; i++)
	{
		int key = arr[i];
		//insert arr[i] into the sorted sequence arr[0 .. i - 1]
		int j = i - 1;
		while(j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
<<<<<<< HEAD
    return;
=======
	return;
>>>>>>> 87849e2f625eb6a53364c0bab21d991b177bfc21
}

int main()
{
	int arr[10] = {2, 3, 1, 0, 9, 6, 8, 4, 5, 7};
<<<<<<< HEAD
    insertion_sort(arr, 10);
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
=======
	insertion_sort(arr, 10);
	for(int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
>>>>>>> 87849e2f625eb6a53364c0bab21d991b177bfc21
	return 0;
}
