#include <iostream>

using namespace std;

class node
{
	public:
		int data;
		node *next;
		node *prev;

		node()
		{
			data = 0;
			next = NULL;
			prev = NULL;
		}

		node(int d)
		{
			data = d;
			next = NULL;
			prev = NULL;
		}
};

class queue
{
	private:
		node *front;
		node *rear;

	public:
		queue()
		{
			front = NULL;
			rear = NULL;
		}

		void enqueue(int data)
		{
			node *newnode = new node(data);

			if (front == NULL)
			{
				front = newnode;
				rear = newnode;
				return;
			}

			rear->next = newnode;
			newnode->prev = rear;
			rear = newnode;
		}

		void dequeue()
		{
			if (front == NULL)
			{
				cout << "Queue is empty" << endl;
				return;
			}

			node *temp = front;
			front = front->next;
			delete temp;
		}

		void display()
		{
			if (front == NULL)
			{
				cout << "Queue is empty" << endl;
				return;
			}

			node *temp = front;

			while (temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
};


int main(int argc, char const *argv[])
{
	queue q;
	for (int i = 0; i < 10; ++i)
	{
		q.enqueue(i);
	}

	q.display();

	q.dequeue();
	q.display();

	return 0;
}