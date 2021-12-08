#include <iostream>

using namespace std;

//recursive approach for winner in tic tac toe
int winner(char board[3][3])
{
	//checking rows
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			if (board[i][0] == 'X')
				return 1;
			else if (board[i][0] == 'O')
				return 2;
		}
	}

	//checking columns
	for (int i = 0; i < 3; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{
			if (board[0][i] == 'X')
				return 1;
			else if (board[0][i] == 'O')
				return 2;
		}
	}

	//checking diagonals
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		if (board[0][0] == 'X')
			return 1;
		else if (board[0][0] == 'O')
			return 2;
	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		if (board[0][2] == 'X')
			return 1;
		else if (board[0][2] == 'O')
			return 2;
	}

	//checking for draw
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == '_')
				return 0;
		}
	}

	return -1;
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