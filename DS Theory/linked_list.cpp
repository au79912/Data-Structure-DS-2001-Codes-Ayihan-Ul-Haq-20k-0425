//LL assignment
#include <iostream>

using namespace std;

class node
{
	public:
	int data;
	node *next;
	node *previous;
};

void printList(node *n)
{
	cout<<"Linked list : ";
	while (n != NULL) 
	{
		cout << n->data << " ";
		n = n->next;
	}
}

void compare(node *n, node *x)
{
	if(n->data!=x->data)
	{
		cout<<"is not a Palindrome";
		return;
	}
	n=n->next;
	x=x->previous;

	if(n->data!=x->data)
	{
		cout<<"is not a Palindrome";
		return;
	}

	else
	{
		cout<<"is a Palindrome";
		return;
	}
}



int main(int argc, char const *argv[])
{
	node *head= NULL;
	node *second= NULL;
	node *third= NULL;
	node *fourth= NULL;
	node *fifth= NULL;

	head= new node();
	second= new node();
	third= new node();
	fourth= new node();
	fifth= new node();

	int arr[4];

	int n=5;
	
	for(int i=0; i<n; i++)
	{
		cout<<"Enter the element in the linked list on position "<< i<<" : ";
		cin>>arr[i];
	}


	head->data= arr[0];
	head->next= second;
	head->previous= NULL;

	second->data= arr[1];
	second->next= third;
	second->previous= head;

	third->data= arr[2];
	third->next= fourth;
	third->previous= second;

	fourth->data= arr[3];
	fourth->next= fifth;
	fourth->previous= third;

	fifth->data= arr[4];
	fifth->next= NULL;
	fifth->previous=fourth;

	printList(head);
	compare(head, fifth);

	
	return 0;
}