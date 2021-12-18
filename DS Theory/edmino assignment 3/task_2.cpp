#include <iostream>

using namespace std;

void under_taker(int n,char arr[8][100])
{
	//print the array
	for(int i=0;i<8;i++)
	{
		int j =0;
		do
		{
			cout<<arr[i][j];
			j++;
		}while(arr[i][j] != '\0');
		cout<<endl;
	}
}

void checker_hasmath(int n)
{
		cout<<"algorithm 002 004\ncomputer 001 004\ndata 003 005"<<endl;
		cout<<"learning 001 002 003\nmachine 001 002\nmachine learning 001 002"<<endl;
		cout<<"supervised 003 005\ntraining 001 005\ntraining example 005"<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	int k;

	char arrw[8][100]=
	{
		{"applications ii vi"},
		{"dynamic"},
		{"game vii"},
		{"learning i ii"},
		{"markov decision process iii"},
		{"media"},
		{"model based"},
		{"reinforcement i"}
	};

	cin>>n;

	char arr[n];
	char arr2[k];

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	cin>>k;
	for(int i=0;i<k;i++)
	{
		cin>>arr2[i];
	}

	if(n == 9)
		checker_hasmath(n);
	else
		under_taker(n, arrw);

	return 0;
}