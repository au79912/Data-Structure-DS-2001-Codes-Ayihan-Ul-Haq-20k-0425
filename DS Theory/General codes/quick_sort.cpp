#include <iostream>

using namespace std;

//quick sort
void quick_sort(int *arr, int left, int right)
{
	if (left < right)
	{
		int pivot = arr[right];
		int i = left - 1;
		int j = right;
		while (true)
		{
			while (arr[++i] < pivot);
			while (arr[--j] > pivot);
			if (i >= j)
				break;
			swap(arr[i], arr[j]);
		}
		swap(arr[i], arr[right]);
		quick_sort(arr, left, i - 1);
		quick_sort(arr, i + 1, right);
	}
}



void printArray(int arr[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

// Driver Code
int main() 
{ 
	int arr[] = {10, 7, 8, 9, 1, 5}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	quick_sort(arr, 0, n - 1); 
	cout << "Sorted array: \n"; 
	printArray(arr, n); 
	return 0; 
} 
