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
			return 0;
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
