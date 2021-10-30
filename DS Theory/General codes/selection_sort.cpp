#include <iostream>

using namespace std;

void sort(int *arr, int n)
{
	int l;
	int m;
	int k;

	for(int i=0;i<n;i++)
	{
		l=i;
		for(int j=i+1;j<n;j++)
		{
			
		}
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