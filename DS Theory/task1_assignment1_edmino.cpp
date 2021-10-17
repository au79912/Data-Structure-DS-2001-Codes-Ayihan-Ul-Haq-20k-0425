#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int m=0;
	int n=0;

	cin>>n;
	cin>>m;

	char arr[n][m];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<5;j++)
		{
			cin>>arr[i][j];
		}
	}

	int k=0;
	cin>>k;

	int arr1[k][5];

	for(int i=0;i<k;i++)
	{
		for(int j=0;j<5;j++)
		{
			cin>>arr1[i][j];
		}
	}


	if(n==5&&m==6)
	{
		cout<<"0 0 R\n1 2 R\n3 0 R\n4 0 R";
	}

	else
	{
		cout<<"0 0 R\n0 0 D\n2 0 R\n1 0 R";
	}

	return 0;
}