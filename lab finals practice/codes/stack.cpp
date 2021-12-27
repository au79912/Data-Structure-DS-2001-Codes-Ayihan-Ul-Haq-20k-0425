#include <iostream>

using namespace std;

class stack
{
	private:
		struct node
		{
			int data;
			node *next;

			node(int d)
			{
				data=d;
				next=NULL;
			}

			node()
			{
				data=0;
				next=NULL;
			}
		};
		node *top;

	public:
		stack()
		{
			top=NULL;
		}

		void push(int d)
		{
			node *temp= new node(d);
			temp->next=top;
			top=temp;
		}

		void pop()
		{
			int data;
			if (top==NULL)
			{
				cout<<"Stack is empty";
				return;
			}
			node *temp = top;
			data=temp->data;
			top=top->next;
			delete temp;
			cout<<"popped element is : "<<data<<endl;
			return;
		}

		bool isEmpty()
		{
			return top==NULL;
		}

		int peak()
		{
			if(top == NULL)
			{
				cout<<"stack is empty";
				return 0;
			}
			return top->data;
		}

		void display()
		{
			node *temp = top;
			if(temp ==NULL)
			{
				cout << "stack is empty";
			}
			while(temp != NULL)
			{
				cout<<temp->data<<" ";
				temp = temp->next;
			}
		}
};

int main(int argc, char const *argv[])
{
	stack s;

	for (int i =0;i<10;i++)
	{
		s.push(i);
	}

	s.display();

	s.pop();
	s.pop();

	s.display();
	
	return 0;
}