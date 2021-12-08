#include <iostream>

using namespace std;

void puzzle(int arr[3][3])
{
	//result of tic tac toe
	int result = 0;
	//check for horizontal win
	for (int i = 0; i < 3; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2])
		{
			result = arr[i][0];
		}
	}
	//check for vertical win
	for (int i = 0; i < 3; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i])
		{
			result = arr[0][i];
		}
	}
	//check for diagonal win
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
	{
		result = arr[0][0];
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
	{
		result = arr[0][2];
	}
	//check for draw
	if (result == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (arr[i][j] == 0)
				{
					result = -1;
				}
			}
		}
	}
	//print result
	cout<<result<<endl;
}

int main(int argc, char const *argv[])
{
	int arr[3][3];

	for(int i=0; i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>arr[i][j];
		}
	}

	puzzle(arr);
	return 0;
}