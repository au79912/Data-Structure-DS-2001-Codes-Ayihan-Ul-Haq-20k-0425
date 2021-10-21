#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node *next;
		node *prev;
	
		node()
		{
			data=0;
			next=NULL;
			prev=NULL;
		}
		
		node(int data)
		{
			this->data=data;
			next=NULL;
			prev=NULL;
		}
};

class linkedlist
{
	node *head;
	node *tail;
	node *last;
	node *temp;
	node *temp;
	node *tailp;
	
	public:
		linkedlist()
		{
			head=NULL;
			tail=NULL;
		}
		
		
		void insert(int data)
		{
			node *n=new node(data);
			
			if(head==NULL)
			{
				head=temp;
				tail=head;
				return;
			}
			
			tail->next=n;
			n->prev=tail;
			
			tail=tail->next;
			last=tail;
		}
		
		void insert_anypos(int data, int pos)
		{
			int count = pos;
			node* newNode = new node(data);
			tail = head;
			while (count != 0)
			{
				tail = tail->next;
				count = count - 1;
				temp = tail;
			}
			
			temp = tail->next;
			tail->next = newNode;
			newNode->next = temp;
			newNode->prev = tail;
			temp->prev = newNode;
		}
		
		void del_node(int data)
		{
			 tail = head;
			while (tail != NULL)
			{
				if (tail->data == data)
				{
					break;
				}
		
				temp = tail;
				tail = tail->next;
			}
				tailp= tail->next ;
				temp->next = tailp;
				tailp->prev = temp;
		}
		
		void display()
		{
			cout << endl;
			temp = head;
			while (temp != NULL)
			{
				cout << " " << temp->data;
				temp = temp->next;
			}
		}
};



int main()
{
	linkedlist list;
	
	list.insert(10);
	list.insert(312);
	list.insert(34);
	list.insert(61);
	list.display();
	list.insert_anypos(2, 1);
	list.display();
	list.del_node(2);
	list.display();
	
	return 0;
}