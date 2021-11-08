#include <iostream>

using namespace std;

template <class T>
class node
{
	public:
		node *next;
		node *prev;
		node *ID;
		T data;
		node()
		{
			next = NULL;
			prev = NULL;
		}
		node(T ID)
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
		
};

int main(int argc, char const *argv[])
{
	
	return 0;
}