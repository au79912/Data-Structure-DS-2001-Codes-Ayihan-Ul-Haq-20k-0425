#include <iostream>
#include <cstring>

using namespace std;

void sortStrings(char arr[][100], int n)
{
	char temp[100];

	for (int i=0; i<n-1; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			if (strcmp(arr[i], arr[j]) > 0)
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}

int main()
{
	char arr[][100] = {"hello","world","this","is","ayihan"};
	int n = sizeof(arr)/sizeof(arr[0]);

	sortStrings(arr, n);

	for (int i=0; i<n; i++)
	{
		cout<<arr[i]<<endl;
	}
	return 0;
}