#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int num;
	int count=0;
	
	cout<<"Enter a positive integer : ";cin>>num;

	if(num == -1)
	{
		exit;
	}

	int n=num;
	
	for(int i=1; i<n; i++)
	{
		if(num%i!=0)
		{
			;
		}
		else
		{
			cout<<i<<" is a factor of "<<num<<endl;

			count+=i;
		}
	}

	cout<<"The sum of the factores is : "<<count;

	return 0;
}