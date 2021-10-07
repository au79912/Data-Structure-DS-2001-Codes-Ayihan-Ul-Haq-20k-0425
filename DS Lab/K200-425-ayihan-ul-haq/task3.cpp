#include <iostream>

using namespace std;
class node {
public:
	int data;
	node* next;
	int key;

	node()
	{
		data = 0;
		next = NULL;
		key = 0;
	}

	node(int data, int key)
	{
		this->data = data;
		this->next = NULL;
		this->key=key;
	}
};


class singlylinkedlist {
	node* head;
public:
	singlylinkedlist()
	{
		head = NULL;
	}

	singlylinkedlist(node *n)
	{
		head = n;
	}

	node keychec(int k)
	{
		node *temp;
		node *n;
		temp=head;
		// temp=temp->next;
		while(temp!=NULL)
		{
			if(k==temp->key)
			{
				cout<<"key already exists, Enter new key";
				exit;
			}
			else
			{
				temp=temp->next;
			}
		}
	}

	void appendnode(node *n,int data)
	{
		n->data=data;
		node *temp;
		if(head==NULL)
		{
			head=n;
		}
		else
		{
			temp=head;
			while(temp!=NULL)
			{
				temp=temp->next;
			}
			n=temp;
		}
	}
};

int main(int argc, char const *argv[])
{
	
	return 0;
}