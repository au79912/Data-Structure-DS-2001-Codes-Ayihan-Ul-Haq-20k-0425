#include <iostream>

using namespace std;

void sort(int arr[], int n)
{
	int i, key, j;

	for (i=1;i<n;i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}

	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
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

	sort(arr,size);

	return 0;
}