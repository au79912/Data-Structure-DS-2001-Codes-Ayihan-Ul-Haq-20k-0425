#include <iostream>

using namespace std;

#define MAX 1000 

class stack
{
	int top;
	
	public:
		int a[MAX];
		
		stack()
		{
			top =-1;
		}

		bool push(int x)
		{
			if(top>=(MAX-1))
			{
				cout<<"Stack overflow";
				return false;
			}

			else
			{
				a[++top]=x;
				cout<<x<<"Pushed into stack";
			}
		}
};

int main(int argc, char const *argv[])
{
	
	return 0;
}