#include <iostream>

using namespace std;

//stack with linked list
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
				next=NULL;
				data=0;
			}
		};
		node *top;

	public:
		stack()
		{
			top=NULL;
		}

		void push(int data)
		{
			node *temp= new node(data);
			temp->next=top;
			top=temp;
		}

		void pop()
		{
			int data;
			if(top==NULL)
			{
				cout<<"Stack is empty";
				return;
			}
			node *temp=top;
			data=temp->data;
			top=top->next;
			delete temp;
			cout<<"Popped element is "<<data<<endl;
			return;
		}

		bool isEmpty()
		{
			return top==NULL;
		}

		int peek()
		{
			if(top==NULL)
			{
				cout<<"stack is empty";
				return 0;
			}
			return top->data;
		}

		void display()
		{
			if(top ==NULL)
			{
				cout<<"Stack is empty";
				return;
			}
			node *temp=top;
			while(temp!=NULL)
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
};

int main()
{
	stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.display();

	cout<<endl;

	s.pop();


	s.display();
	return 0;
}