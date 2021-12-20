#include <iostream>

using namespace std;

int result = 0;
int arrog[3][3];

void checker(int arr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (arr[i][0] == 1 && arr[i][1] == 1 && arr[i][2] == 0)
		{
			result = 1;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (arr[0][i] == 1 && arr[1][i] == 1 && arr[2][i] == 0)
		{
			result = 1;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (arr[0][i] == 1 && arr[1][i] == 1 && arr[2][i] == 0)
		{
			result = 1;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (arr[i][0] == 1 && arr[i][1] == 1 && arr[i][2] == 0)
		{
			result = 1;
		}
	}

	// diagonal check
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j)
			{
				if (arr[i][j] == 1 && arr[i + 1][j + 1] == 1 && arr[i + 2][j + 2] == 0)
				{
					result = 1;
				}
				if (arr[i][j] == 1 && arr[1][1] == 1 && arr[2][0] == 0)
				{
					result = 0;
				}
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (arr[i][0] == 2 && arr[i][1] == 2 && arr[i][2] == 0)
		{
			if (result == 1)
			{
				result = 2;
				return;
			}
			else
			{
				result = 1;
				return;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (arr[0][i] == 2 && arr[1][i] == 2 && arr[2][i] == 0)
		{
			if (result == 1)
			{
				result = 2;
				return;
			}
			else
			{
				result = 1;
				return;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (arr[0][i] == 2 && arr[1][i] == 2 && arr[2][i] == 0)
		{
			if (result == 1)
			{
				result = 2;
				return;
			}
			else
			{
				result = 1;
				return;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (arr[i][0] == 2 && arr[i][1] == 2 && arr[i][2] == 0)
		{
			if (result == 1)
			{
				result = 2;
				return;
			}
			else
			{
				result = 1;
				return;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j)
			{
				if (arr[i][j] == 2 && arr[i + 1][j + 1] == 2 && arr[i + 2][j + 2] == 0)
				{
					if (result == 1)
					{
						result = 2;
						return;
					}
					else
					{
						result = 1;
						return;
					}
				}
				if (arr[i][j] == 2 && arr[1][1] == 2 && arr[2][0] == 0)
				{
					if (result == 1)
					{
						result = 2;
						return;
					}
					else
					{
						result = 1;
						return;
					}
				}
			}
		}
	}
}

void invalid(int arr[3][3])
{
	int a = 0;
	int b = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] == 1)
			{
				a++;
			}
			if (arr[i][j] == 2)
			{
				b++;
			}
		}
	}

	if (a != b + 1 && a + 1 != b)
	{
		if(a==b)
		{
			return;
		}
		cout << "-1";
		exit(0);
	}
}

int main(int argc, char const *argv[])
{
	int arr[3][3]; // array for tic tac toe

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j]; // fill the tic tac toe board
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arrog[i][j] = arr[i][j];
		}
	}

	// print_diagonal(arr);
	invalid(arr);
	// // check(arr);
	checker(arr);

	cout << result << endl;

	return 0;
}