#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* link;
};
 
struct Node* top;
 
// Utility function to add an element
// data in the stack insert at the beginning
void push(int data)
{
     
    // Create new node temp and allocate memory
    struct Node* temp;
    temp = new Node();
 
    // Check if stack (heap) is full.
    // Then inserting an element would
    // lead to stack overflow
    if (!temp)
    {
        cout << "\nHeap Overflow";
        exit(1);
    }
 
    // Initialize data into temp data field
    temp->data = data;
 
    // Put top pointer reference into temp link
    temp->link = top;
 
    // Make temp as top of Stack
    top = temp;
}

void display()
{
	struct Node* temp; 
	if (top == NULL)
	{
		cout << "\nStack Underflow";
		exit(1);
	}
	else
	{
		temp = top;
		cout<<"Forward";
		while (temp != NULL)
		{
			cout << temp->data << "-> ";
			temp = temp->link;
		}
	}
}

void pop()
{
	struct Node* temp;

	if (top == NULL)
	{
		cout << "\nStack Underflow" << endl;
		exit(1);
	}
	else
	{
		temp = top; 
		top = top->link;
		temp->link = NULL;
	}
}
 


int main(int argc, char const *argv[])
{
	Node stack;
	int arr[10];

	for(int i=0;i<10;i++)
	{
		cout<<"enter the element in the "<<i+1<<" position of the stack : ";
		cin>>arr[i];
		push(arr[i]);
	}

	display();
	pop();

	return 0;
}