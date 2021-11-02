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
				cout<<x<<" Pushed into stack"<<endl;
				return true;
			}
		}

		int pop()
		{
			if(top<0)
			{
				cout<<"stack Underflow";
				return 0;
			}

			else
			{
				int x=a[top--];
				return x;
			}
		}

		int peak()
		{
			if(top<0)
			{
				cout<<"Stack is empty";
				return 0;
			}
			else
			{
				int x=a[top];
				return x;
			}
		}

		bool isempty()
		{
			return (top<0);
		}

		void print()
		{
			while(!this->isempty())
			{
				cout<<this->peak()<<" ";
				this->pop();
			}
		}
};

int main(int argc, char const *argv[])
{
	stack stack;
	int arr[10];

	for(int i=0;i<10;i++)
	{
		cout<<"enter the element in the "<<i+1<<" position of the stack : ";
		cin>>arr[i];
		stack.push(arr[i]);
	}

	stack.print();
	stack.peak();

	return 0;
}