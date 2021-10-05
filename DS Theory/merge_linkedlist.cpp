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

	
};

int main(int argc, char const *argv[])
{
	linkedlist list;


	return 0;
}