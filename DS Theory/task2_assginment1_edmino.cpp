#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int i;
	int j;
	int k;
	int start=0;
	int end=0;
	int temp=0;

	cin>>i;
	int *arr=new int[i];

	for(k=0;k<i;k++)
	{
		cin>>arr[k];
	}

	int max=-2147483647;
	int maxend=0;

	for(j=0;j<i;j++)
	{
		maxend+=arr[j];

		if (max<maxend)
		{
			max=maxend;
			start=temp;
			end=j;
		}

		if(maxend<0)
		{
			maxend=0;
			temp=j+1;
		}
	}

	for(int j=start;j<end+1;j++)
	{
		cout<<arr[j]<<" ";
	}
	cout<<endl<<max;
	return 0;
}