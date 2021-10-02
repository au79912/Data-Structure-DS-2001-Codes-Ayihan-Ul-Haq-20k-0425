#include <iostream>

using namespace std;

void printarr(int *arr,int n);

void bubblesort(int *arr, int n)
{
	// int n=sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<n;i++)
	{
		for (int j = 0; j < i; j++)
		{
			if(arr[i]<arr[j])
			{
				cout<<"Position of element "<<arr[j]<<"changed with position of element"<<arr[i]<<endl;
				swap(arr[i],arr[j]);
			}
		}
		
	}
	printarr(arr,n);
}

void insertionsort(int *arr,int n)
{
	// int n=sizeof(arr)/sizeof(arr[0]);
	int i;
	int m;
	int j;

	for (i=1;i<n;i++)
	{
		m=arr[i];
		j=i-1;

		while (j>=0 && arr[j]>m)
		{
			cout<<"Position of element "<<arr[j]<<"changed with position of element"<<arr[j-1];
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=m;
	}
	printarr(arr,n);
}

void selectionsort(int *arr,int n)
{
	// int n=sizeof(arr)/sizeof(arr[0]);
	int i;
	int j;
	int temp;

	for (i = 0; i < n-1; i++)
	{
		temp=i;
		for (j=i+1;j<n;j++)
		if (arr[j]<arr[temp])
		{
			temp=j;
			cout<<"Position of element "<<arr[j]<<"changed with position of element"<<arr[i]<<endl;
		}
		swap(arr[temp], arr[i]);
	}
	printarr(arr,n);
}

void combsort(int *arr, int n)
{
	// int n=sizeof(arr)/sizeof(arr[0]);
	int v=n;
	for(int i=0;i<v;i++)
	{
		n=n/1.3;
		
		for(int j=0;j<i;j++)
		{
			if(arr[j]>arr[j+n] && j+n<=10)
			{
				cout<<"Position of element "<<arr[j]<<"changed with position of element"<<arr[i];
				swap(arr[j],arr[j+n]);
				cout<<endl<<endl;
			}
		}
	}
	printarr(arr,n);
}

int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; 
	int i = (low - 1);

	for (int j = low; j <= high- 1; j++) 
	{ 
		if (arr[j] <= pivot) 
		{ 
			i++;
			swap(arr[i], arr[j]); 
		} 
	} 
	swap(arr[i + 1], arr[high]); 
	return (i + 1); 
} 

void quicksort(int *arr, int low, int high, int n)
{
	// int n=sizeof(arr)/sizeof(arr[0]);
	low= 0;
	high= n-1;
	if (low < high) 
	{ 
		int pivot = partition(arr, low, high); 

		quicksort(arr, low, pivot - 1,n); 
		quicksort(arr, pivot + 1, high,n); 
	} 
	printarr(arr,n);
}



int main()
{
	int choice;
	int i;
	
	cout<<"Enter the size of the array : ";cin>>i;
	
	int n=i;
	int *arr=new int[n];

	for(int i=0; i<n; i++)
	{
		cout<<"Enter the element in position "<<i+1<<" : ";
		cin>>arr[i];
	}
	cout<<"Select the sorting algor : \n1)Bubble sort\n2)insertion sort\n3)selection sort\n4)comb sort\n5)Quick sort\nEnter your choice";
	cin>>choice;

	jump:
	if (choice==1)
	{
		bubblesort(arr,n);
	}
	else if(choice==2)
	{
		insertionsort(arr,n);
	}
	else if(choice==3)
	{
		selectionsort(arr,n);
	}
	else if(choice==4)
	{
		combsort(arr,n);
	}
	else if(choice==5)
	{
		quicksort(arr, 0, n-1,n);
	}
	else
	{
		cout<<"Wrong choice, select again\n";
		goto jump;
	}

	return 0;
}

void printarr(int *arr,int n)
{
	// int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"\n\nSorted array : ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}