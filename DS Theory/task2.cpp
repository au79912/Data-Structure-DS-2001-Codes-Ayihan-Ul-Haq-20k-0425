// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

class arr
{
	public:
	int m;
	int *ar1;
	int *ar2;

	int *fillarr()
	{
		int n;
		int j;
		cout << "Enter the number of integers for first array : ";
		cin >> n;

		int *arr1 = new int(n);

		for (int x = 0; x < n; x++)
		{
			fflush(stdin);
			cout << "Enter " << x << " value : ";
			cin >> arr1[x];
			cout<<endl;
		}

		int y;
		cout << "Enter the number of integers for second array : ";
		cin >>y;

		int *arr2 = new int(y);

		for (int x = 0; x < y; x++)
		{
			fflush(stdin);
			cout << "Enter " << x << " value : ";
			cin >> arr2[x];
			cout<<endl;
		}

		ar1=arr1;
		ar2=arr2;
		size(arr1,arr2,y,n);
	}

	void size(int *arr1, int *arr2,int y, int n)
	{
		int low=100000;

		if (sizeof(arr1)>sizeof(arr2))
		{
			low=y;
		}
		else if (sizeof(arr1)<sizeof(arr2))
		{
			low=n;
		}
		else
		{
			low=n;
		}

		m=low;
	}

	void dublicate(int *arr1, int *arr2, int a)
	{
		for(int i=0;; i++)
		{
			for(int j=0;j<i;j++)
			{
				if(arr1[i]==arr2[j])
				{
					cout<<"arrays are not disjoint";
					return;
				}

				if(i==a && arr1[i]!=arr2[j])
				{
					cout<<"Arrays are disjoint";
					return;
				}
			}
		}
	}
}obj;


int main(int argc, char const *argv[])
{
	obj.fillarr();
	obj.dublicate(obj.ar1,obj.ar2,obj.m);
	return 0;
}