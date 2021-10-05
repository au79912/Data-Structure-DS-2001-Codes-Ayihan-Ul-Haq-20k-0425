#include <iostream>
#include <list>

using namespace std;

class node
{
	public:
	int data;
	node *next;
	node *prev;

	node (int data)
	{
		this->data=data;
	}
};

class linkedlist
{
	public:
	node *head;
	node *tail;
	node *temp;

	linkedlist()
	{
		head = NULL;
		tail = NULL;
		temp=NULL;
	}

	void insert(int data)
	{
		node *newnode = new node(data);
		if (head==NULL)
		{
			head =newnode;
			tail=head;
			return;
		}

		tail->next=newnode;
		newnode->prev=tail;
		tail=tail->next;
	}

	void printlist()
	{
		int count;
		temp=head;
		while(count!=5);
		{
			cout<<temp->data<<", ";
			temp=temp->next;
			count++;
		}
	}
};

int main(int argc, char const *argv[])
{
	linkedlist list;

	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);

	list.printlist();

	return 0;
}