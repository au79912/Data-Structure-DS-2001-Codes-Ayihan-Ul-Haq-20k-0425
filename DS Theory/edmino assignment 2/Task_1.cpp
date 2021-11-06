#include <iostream>

using namespace std;

template <class T>
class node
{
	public:
		node *next;
		node *prev;
		T data;
		
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
		
		void insert_at_end(T data)
		{
			node<T> *newnode=new node<T>;
			newnode->data=data;
			newnode->next=NULL;
			newnode->prev=NULL;
			
			if(head==NULL)
			{
				head=newnode;
				tail=newnode;
			}
			else
			{
				tail->next=newnode;
				newnode->prev=tail;
				tail=newnode;
			}
		}

		void delete_at_end()
		{
			if(head==NULL)
			{
				cout<<"List is empty"<<endl;
			}
			else
			{
				temp=tail;
				tail=tail->prev;
				tail->next=NULL;
				delete temp;
			}
		}
};

int main(int argc, char const *argv[])
{
	
	return 0;
}