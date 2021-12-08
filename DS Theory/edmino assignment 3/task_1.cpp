#include <iostream>

using namespace std;

void ttt(int arr[3][3])
{
	
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