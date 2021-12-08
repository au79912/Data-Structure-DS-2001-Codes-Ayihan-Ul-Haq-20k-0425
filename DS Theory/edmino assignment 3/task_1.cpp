#include <iostream>

using namespace std;

int result = 0;
int arrog[3][3];

void ttt(int arr[3][3])
{
	if(result == -1)
	{
		cout<<result<<endl;
		exit(0);
	}

	//for 1s
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(arr[i][j] == 0)
			{
				arr[i][j] = 1;
			}
		}
	}

	//check if there are 3 1s in a row horizontally, vertically or diagonally
	for(int i=0;i<3;i++)
	{
		if(arr[i][0] == 1 && arr[i][1] == 1 && arr[i][2] == 1)
		{
			result = 1;
			cout<<result<<endl;
			exit(0);
		}
		if(arr[0][i] == 1 && arr[1][i] == 1 && arr[2][i] == 1)
		{
			result = 1;
			cout<<result<<endl;
			exit(0);
		}
	}
	if(arr[0][0] == 1 && arr[1][1] == 1 && arr[2][2] == 1)
	{
		result = 1;
		cout<<result<<endl;
		exit(0);
	}
	if(arr[0][2] == 1 && arr[1][1] == 1 && arr[2][0] == 1)
	{
		result = 1;
		cout<<result<<endl;
		exit(0);
	}

	for (int i =0 ;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			arr[i][j]=arrog[i][j];
		}
	}

	//for 2s
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(arr[i][j] == 0)
			{
				arr[i][j] = 2;
			}
		}
	}

	//check if there are 3 2s in a row horizontally
	for(int i=0;i<3;i++)
	{
		if(arr[i][0] == 2 && arr[i][1] == 2 && arr[i][2] == 2)
		{
			if(result == 1)
			{
				result = 2;
				cout<<result<<endl;
				exit(0);
			}
			else
			{
				result = 1;
				cout<<result<<endl;
				exit(0);
			}
		}
		if(arr[0][i] == 2 && arr[1][i] == 2 && arr[2][i] == 2)
		{
			if(result == 1)
			{
				result = 2;
				cout<<result<<endl;
				exit(0);
			}
			else
			{
				result = 1;
				cout<<result<<endl;
				exit(0);
			}
		}
	}
	//check if there are 3 2s in a row vertically
	if(arr[0][0] == 2 && arr[1][1] == 2 && arr[2][2] == 2)
	{
		if(result == 1)
		{
			result = 2;
			cout<<result<<endl;
			exit(0);
		}
		else
		{
			result = 1;
			cout<<result<<endl;
			exit(0);
		}
	}
	if(arr[0][2] == 2 && arr[1][1] == 2 && arr[2][0] == 2)
	{
		if(result == 1)
		{
			result = 2;
			cout<<result<<endl;
			exit(0);
		}
		else
		{
			result = 1;
			cout<<result<<endl;
			exit(0);
		}
	}

	//check if there are 3 2s in a row diagonally
	if(arr[0][0] == 2 && arr[1][1] == 2 && arr[2][2] == 2)
	{
		if(result == 1)
		{
			result = 2;
			cout<<result<<endl;
			exit(0);
		}
		else
		{
			result = 1;
			cout<<result<<endl;
			exit(0);
		}
	}
	if(arr[0][2] == 2 && arr[1][1] == 2 && arr[2][0] == 2)
	{
		if(result == 1)
		{
			result = 2;
			cout<<result<<endl;
			exit(0);
		}
		else
		{
			result = 1;
			cout<<result<<endl;
			exit(0);
		}
	}
}

void invalid(int arr[3][3])
{
	int n = 0;
	int k=0;

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(arr[i][j] == 1)
			{
				n++;
			}
			if(arr[i][j] == 2)
			{
				k++;
			}
		}
	}

	if(n != k)
	{
		result = -1;
	}
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



	invalid(arr);
	ttt(arr);

	return 0;
}