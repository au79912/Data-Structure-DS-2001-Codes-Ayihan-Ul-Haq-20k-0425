#include <iostream>

using namespace std;

int checker(int arr)
{
	int result =0;

	//check if there are two 
}

int invalid (int arr)
{
	int a=0;
	int b=0;

	for (int i =0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			if (arr[i][j]==1)
			{
				a++;
			}
			if (arr[i][j]==2)
			{
				b++;
			}
		}
	}

	if (a!=b||b!==a)
	{
		return -1;
	}
	else 
	{
		return 0;
	}
}

int main(int argc, char const *argv[])
{
	int arr[3][3];

	for (int i=0;i<3;i++)
	{
		for (int j =0;j<3;j++)
		{
			cin>>arr[i][j];
		}
	}

	if(invalid(arr)==-1)
	{
		cout<<"-1";
	}
	else
	{
		checker(arr);
	}

	return 0;
}