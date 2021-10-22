#include <iostream>

using namespace std;

template <class T>
class node
{
	public:
		node *next;
		node *prev;
		T data;
		
		node(int data)
		{
			this->data=data;
			next=NULL;
			prev=NULL;
		}
		node()
		{
			data=0;
			next=NULL;
			prev=NULL;
		}
};

template <class T>
class linkedlist
{
	public:
		node<T> *head;
		node<T> *tail;
		node<T> *temp;

		linkedlist()
		{
			head=NULL;
			tail=NULL;
			temp=NULL;
		}

		void insert(T data)
		{
			node<T> *newnode = new node<T>(data);
		
			if(head==NULL)
			{
				head=newnode;
				tail=head;
				return;
			}

			tail->next=newnode;
			newnode->prev=tail;
			tail=tail->next;
			tail->next=NULL;
		}

	void insertionSort(node<T>	*headref)
	{
		temp = NULL;
		node<T> *current=new node<T>(); 
		current = headref;
		while (current != NULL) {
			node<T> *next = current->next;
			current = next;
		}
		head = temp;
	}
	void print()
	{
		temp=head;
		while(temp!=NULL)
		{
			cout<<" "<<temp->data;
			temp=temp->next;
		}
	}
};

int main(int argc, char const *argv[])
{
	linkedlist<int> list1;
	list1.head=NULL;
	list1.insert(5);
	list1.insert(7);
	list1.insert(1);
	list1.insert(3);

	list1.print();

	list1.insertionSort(list1.head);

	list1.print();
	return 0;
}