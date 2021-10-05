#include <iostream>

using namespace std;

void printUnsorted(int arr[], int n)
{
int m = 0, x = n-1, i, max, min;

for (m = 0; m < n-1; m++)
{
	if (arr[m] > arr[m+1])
	break;
}
if (m == n-1)
{
	cout << "array is sorted";
	return;
}


for(x = n - 1; x > 0; x--)
{
	if(arr[x] < arr[x-1])
	break;
}

max = arr[m]; min = arr[m];
for(i = m + 1; i <= x; i++)
{
	if(arr[i] > max)
	max = arr[i];
	if(arr[i] < min)
	min = arr[i];
}

for( i = 0; i < m; i++)
{
	if(arr[i] > min)
	{
	m = i;
	break;
	}
}

for( i = n -1; i >= x+1; i--)
{
	if(arr[i] < max)
	{
	x = i;
	break;
	}
}
	
cout << "The unsorted subarray position is "<< m << " and " << x;
return;
}

int main()
{
	int arr[] = {0, 1, 15, 25, 6, 7, 30, 40, 50};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	printUnsorted(arr, arr_size);
	getchar();
	return 0;
}