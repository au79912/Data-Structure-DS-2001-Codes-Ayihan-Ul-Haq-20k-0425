#include <iostream>

using namespace std;

int main()
{
	int c=0;
	int m;

	cin>>m;

	int *arr=new int[m];

	for(int i=0;i<m;i++)
	{
		cin>>arr[i];
	}

	int temp;

	for (int i=0; i<m; i++)
	{
		for (int j=0;j<m;j++)
		{
			if (arr[i] > arr[j] && i<j && i!=j)
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
				c++;
			}
		}
	}

	cout<< c;

}