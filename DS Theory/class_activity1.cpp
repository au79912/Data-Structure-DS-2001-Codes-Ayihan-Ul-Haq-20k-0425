// #include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;


//pattren
int rec(int n, int b)
{
	if (n < 5)
	{
		n++;
		cout<<n<<" ";
		rec(n,b);
	}

	if(n==5&&b>=0)
	{
		if(b==0)
		{
			abort();
		}
		cout<<b<<" ";
		b--;
		rec(n,b);
	}

	return 1;
}

int main()
{
	int n=0;
	int b=4;
	rec(n,b);
}



//power and base
int power_base(int b, int p)
{
	if(p==0)
	{
		return 1;
	}
	return b*power_base(b, p-1);
}

int main()
{
	int b;
	int p;
	int ans = 1;

	cout <<"Enter base : ";
	cin>>b;

	cout <<"Enter power : ";
	cin>>p;
	ans = power_base(b, p);
	
	cout << "ans is : "<<ans;
	return 0;
}



//bubble sort
void arrsort(int arr[], int n)
{
	if (n == 1)
	{
		for (int i=0; i<sizeof(arr); i++)
		{
			cout<<arr[i]<< " ";
		}
	}

	for (int i=0; i<n-1; i++)
	{
		if (arr[i] > arr[i+1])
		{
			swap(arr[i], arr[i+1]);
		}
	}
	arrsort(arr, n-1);
}


int main()
{
    int arr[]={17, 14, 12, 3, 90, 75, 2, 6};

    int n=sizeof(arr)/sizeof(arr[0]);
    arrsort(arr, n);

    return 0;
}