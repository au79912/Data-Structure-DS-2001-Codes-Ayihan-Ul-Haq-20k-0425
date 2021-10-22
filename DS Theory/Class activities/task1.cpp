// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

class dynamicarr
{
	public:
	int *forarr()
	{
		//hard coded for easier debugging

		int n=13; //remove "=13" if manual input is needed
		//Uncomment followung code for user input

		/*
		cout << "Enter the number of integers : ";
		cin >>n;

		int *arr = new int(n);

		for (int x = 0; x < n; x++)
		{
			fflush(stdin);
			cout << "Enter " << x << " value : ";
			cin >> arr[x];
			cout<<endl;
		}
		*/

		int *arr {new int[13]{6, 6, 7, 6, 9, 1, 9, 0, 0, 1, 4, 5, 1}}; //comment out this line if using user input

		deleting_duplicates(arr, n);
	}
	

	void deleting_duplicates(int *arr, int n)
	{
		vector<int> temp;

		for(int i=0; i<n; i++)
		{
			int flag =1;
			for (int k=0; k<i; k++)
			{
				if(arr[k]==arr[i])
				{
					flag =0;
					break;
				}
			}
			if (flag)
			{
				temp.push_back(arr[i]);
			}
		}

		n=temp.size();

		for(int i=0; i<n; i++)
		{
			arr[i]=temp[i];
		}

		dis(arr, n);
	}

	void dis(int *arr, int n)
	{
		for(int i=0; i<n; i++)
		{
			cout<< arr[i]<<" , ";
		}
	}
}obj;

int main(int argc, char const *argv[])
{
	obj.forarr();
	return 0;
}