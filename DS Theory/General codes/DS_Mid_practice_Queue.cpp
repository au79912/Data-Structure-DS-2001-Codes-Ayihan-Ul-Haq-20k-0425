#include <iostream>

using namespace std;

class Queue
{
	private:
		struct node
		{
			int data;
			node *next;

			node()
			{
				data=0;
				next=NULL;
			}
			node(int d)
			{
				data=d;
				next=NULL;
			}
		};
		node *front;
		node *rear;

	public:
		node *temp;
		Queue()
		{
			front=rear=NULL;
		}

		void enqueue(int d)
		{
			temp=new node(d);
			if(rear==NULL)
			{
				front=rear=temp;
				return;
			}
			else
			{
				rear->next=temp;
				rear=temp;
			}
		}

		void dequeue()
		{
			if(front==NULL)
			{
				cout<<"Queue is empty";
				return;
			}
			else
			{
				temp=front;
				front=front->next;
				delete temp;
			}
		}

		void display()
		{
			if(front==NULL)
			{
				cout<<"Queue is empty";
				return;
			}
			else
			{
				temp=front;
				while(temp!=NULL)
				{
					cout<<temp->data<<" ";
					temp=temp->next;
				}
			}
		}
};

int main(int argc, char const *argv[])
{
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);

	q.display();

	cout<<endl;

	q.dequeue();
	q.dequeue();

	q.display();

	return 0;
}