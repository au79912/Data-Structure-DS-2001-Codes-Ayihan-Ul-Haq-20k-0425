#include <iostream>

using namespace std;

/*
Input
5 3 4 6 7 8 9 1
6 7 2 1 9 5 3 4
1 9 8 3 4 2 5 6
8 5 9 7 6 1 4 2
4 2 6 8 5 3 7 9
7 1 3 9 2 4 8 5
9 6 1 5 3 7 2 8
2 8 7 4 1 9 6 3
*/

int main()
{
	int n=9;
	int m=9;
	int temp;

	int **arr=new int *[n];
	
	for(int i = 0; i < n; ++i)
	{
		arr[i] = new int[m];
	}
	
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			// fflush(stdin);
			cin>>arr[i][j];
		}
	}

	for(int i=0;i<9;i++)
	{
		arr[8][i]=0;			//setting last row to 0 
	}
	
	for(int i=0;i<9;i++)
	{
		arr[i][8]=0;			//setting last coloum to 0 
	}

	char check[9]={'F','F','F','F','F','F','F','F','F'};


	//checking and assignment for rows
	for(int i=0;i<8;i++)
	{
		temp=0;

		for(int j=0;j<9;j++)
		{
			check[(arr[i][j])-1]='T';
		}

		for(int x=0;x<9;x++)
		{
			if(check[x]=='F')
			{
				temp=x+1;
				break;
			}
		}

		arr[i][8]=temp;
		
		for(int j=0;j<9;j++)
		{
			check[j]='F';
		}
	}

	//checking and assigning for coloums
	for(int i=0;i<9;i++)
	{
		temp=0;
		for(int j=0;j<9;j++)
		{
			check[(arr[j][i])-1]='T';
		}

		for(int x=0;x<9;x++)
		{
			if(check[x]=='F')
			{
				temp=x+1;
				break;
			}
		}

		arr[8][i]=temp;

		for(int j=0;j<9;j++)
		{
			check[j]='F';
		}
	}

	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout<<arr[i][j]<<" ";	//remove the " "
		}
		cout<<"\n";
	}

	return 0;
}