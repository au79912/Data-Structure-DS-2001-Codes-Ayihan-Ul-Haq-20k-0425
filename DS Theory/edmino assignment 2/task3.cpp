#include <iostream>

using namespace std;

template <class T>
class node
{
	public:
		node *next;
		node *prev;
		string ID;
		T data;
		int time;
		int quota;

		node()
		{
			next = NULL;
			prev = NULL;
		}
		node(string ID)
		{
			next = NULL;
			prev = NULL;
			this->ID = ID;
		}
		node(T data)
		{
			next = NULL;
			prev = NULL;
			this->data = data;
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

		void insert(string ID, int time, int quota)
		{
			node<T> *newnode = new node<T>(ID);
			newnode->time = time;
			newnode->quota = quota;
			if(head==NULL)
			{
				head = newnode;
				tail = newnode;
			}
			else
			{
				tail->next = newnode;
				newnode->prev = tail;
				tail = newnode;
			}
		}

		void checker()
		{
			if( )
		}
};

int main(int argc, char const *argv[])
{
	
	return 0;
}