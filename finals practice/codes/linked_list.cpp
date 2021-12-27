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

class linkedlist
{
public:
	node *head;
	node *temp;
	node *tail;

	linkedlist()
	{
		head = NULL;
		tail = NULL;
		temp = NULL;
	}

	void insert(int d)
	{
		node *newnode = new node(d);
		temp = head;

		if (temp == NULL)
		{
			head = newnode;
			tail = newnode;

			return;
		}

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newnode;
		newnode->prev = temp;
		tail = newnode;
	}

	void insert_start(int d)
	{
		temp = head;
		node *newnode = new node(d);

		if (temp = NULL)
		{
			head = newnode;
			tail = newnode;

			return;
		}

		newnode->next = head;
		head->prev = newnode;
		head = newnode;
	}

	int count()
	{
		temp = head;
		int count = 0;

		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}

		return count;
	}

	void delete_node(int d)
	{
		temp = head;

		if(temp == NULL)
		{
			cout<<"list is empty";
			return;
		}
		while(temp->data != d)
		{
			temp = temp->next;
		}

		if(temp == head)
		{
			head = temp->next;
			head->prev = NULL;
			delete temp;
			return;
		}

		if(temp == tail)
		{
			tail = temp->prev;
			tail->next = NULL;
			delete temp;
			return;
		}

		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
	}

	void print()
	{
		temp = head;

		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
};

int main(int argc, char const *argv[])
{
	linkedlist l;

	for(int i=0;i<10;i++)
	{
		l.insert(i);
	}

	l.print();
	cout<<endl;

	l.insert_start(100);
	l.print();
	cout<<endl;

	l.delete_node(5);
	l.print();
	cout<<endl;
	return 0;
}