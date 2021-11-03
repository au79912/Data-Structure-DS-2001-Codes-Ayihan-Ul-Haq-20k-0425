#include <iostream>

using namespace std;

//selection sort
void selection_sort(int arr[], int n)
{
	int i, j, min_idx;
	for (i = 0; i < n-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}
		swap(arr[min_idx], arr[i]);
	}
}

int main(int argc, char const *argv[])
{
	int size;

	cout<<"Enter the size of the array : ";
	cin>>size;

	int *arr=new int[size];

	int n=size;
	
	for(int i=0; i<n; i++)
	{
		cout<<"Enter the Element in position "<<i+1<<" : ";
		cin>>arr[i];
	}

	selection_sort(arr,size);

	return 0;
}