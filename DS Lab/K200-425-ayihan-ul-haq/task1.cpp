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
};

int main(int argc, char const *argv[])
{
	
	return 0;
}