#include <iostream>

using namespace std;


void insertionsort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			swap(arr[j+1],arr[j]);
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void printarr(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = { 2, 11, 5, 45, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	insertionsort(arr, n);
	printarr(arr, n);

	return 0;
}