#include <iostream>

using namespace std;
class node {
public:
	int data;
	node* next;

	node()
	{
		data = 0;
		next = NULL;
	}

	// Parameterised Constructor
	node(int data)
	{
		this->data = data;
		this->next = NULL;
		this->prev= NULL;
	}
};
class Linkedlist {
	node* head;
	node* tail;
	node* tailp;
	node* tmp;
	node* Last;
public:
	// Default constructor
	Linkedlist()
	{
		head = NULL;
		tail = NULL;
		Last = NULL;
	}

	void insertNode(int);
	void insertNodeAny(int, int);

	void printList();

	void deleteNode(int);
};

int main(int argc, char const *argv[])
{
	return 0;
}