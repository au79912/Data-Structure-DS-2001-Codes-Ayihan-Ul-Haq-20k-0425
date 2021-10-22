#include <iostream>

using namespace std;

void maze(int arr[4][4], int i, int j)
{
	char pos;

	if (arr[i][j]==6)
	{
		cout<<"You have reached your destination";
	}

	else
	{
		cout<<endl<<"F - move forwards"<<endl<<"D - move down"<<endl<<"B - move back";
		cin>>pos;
		if(pos=='f'||pos=='F')
		{
			j++;

			if (arr[i][j]==0)
			{
				cout<<"Can not move there"<<endl;
				j--;
				maze(arr, i, j);
			}
			else
			{
				maze(arr, i, j);
			}
		}

		else if (pos=='d'||pos=='D')
		{
			i++;
			if (arr[i][j]==0)
			{
				cout<<"Can not move there"<<endl;
				i--;
				maze(arr, i, j);
			}
			else
			{
				maze(arr, i, j);
			}
		}

		else if(pos=='b'||pos=='B')
		{
			j--;
			if (arr[i][j]==0)
			{
				cout<<"Can not move there"<<endl;
				j++;
				maze(arr, i, j);
			}
			else
			{
				maze(arr, i, j);
			}
		}
	}
	
}

// void position(int arr, int i, int j)
// {

// }

int main(int argc, char const *argv[])
{
	int arr[4][4]=
	{
		{1,0,0,0},
		{1,1,0,1},
		{0,1,0,0},
		{1,1,1,6}
	};

	int i=0,j=0;

	for (int k=0;k<4;k++)
	{
		for (int n=0; n<4; n++)
		{
			if (arr[k][n]==1||arr[k][n]==6)
			{
				cout<<"  ";
			}
			else
			{
				cout<<"| |";
			}
		}
		cout<<endl;
	}

	maze(arr,i,j);
	return 0;
}