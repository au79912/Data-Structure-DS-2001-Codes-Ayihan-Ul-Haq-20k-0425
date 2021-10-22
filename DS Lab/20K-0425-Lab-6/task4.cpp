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
			this->next=NULL;
			this->prev=NULL;
		}
};

class linkedlist
{
	public:
		node *head;
		node *tail;
		linkedlist()
		{
			head=NULL;
		}
		
		void insert(int data)
		{
			if(head==NULL)
			{
				node *temp=new node(data);
				temp->next=temp;
				head=temp;
				return;
			}
			
			node *temp=new node();
			temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			
			node *newnode=new node(data);
			
			temp->next=newnode;
			newnode->next=head;
		}
		
		
		void insert_any(int data, int pos)
		{
			if(pos==0)
			{
				this->insert1(data);
			}
		
			
			
			if(pos==this->length()-1)
			{
				this->insert(data);
			}
			
			int count=0;
			node *temp=new node();
			temp=head;
			
			while(count!=pos){
				count++;
				temp=temp->next;
			}
			
			node *newnode=new node(data);
			newnode->next=temp->next;
			temp->next=newnode;
		}

		void delete_any(int pos)
		{
			if(pos==0)
			{
				node *temp=new node();
				temp=head;
				
				temp=temp->next;
				head=temp;
			}
			
			if(pos==this->length()-1)
			{
				node *temp=new node();
				temp=head;
				while(temp->next!=head)
				{
					if(temp->next->next==head)
					{
						break;
					}
					temp=temp->next;
				}
				
				temp->next=head;
			}

			node *temp=new node();
			node *temp2=new node();
			temp=head;
			temp2=head;
			int count=0;
			
			while(count!=pos){
				count++;
				temp2=temp;
				temp=temp->next;
			}
			
			temp2->next=temp->next;
		}
		
		int length()
		{
			int count=1;
			node *temp=new node();
			temp=head;
			
			while(temp->next!=head)
			{
				count++;
				temp=temp->next;
			}
			
			return count;
		}
		
		void display()
		{
			node *temp=new node();
			temp=head;
			
			for(int i=0;i<this->length();i++)
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
		
		void insert1(int data)
		{
			node *newnode=new node(data);
			newnode->next=head;
			
			node *temp1=head;
			
			while(temp1->next!=head)
			{
				temp1=temp1->next;
			}
			
			temp1->next=newnode;
			head=newnode;
		}

		void connect(linkedlist &l)
		{
			node *newnode =new node();
			newnode=l.head;
			
			for(int i=0;i<l.length();i++)
			{
				this->insert(newnode->data);
				newnode=newnode->next;
			}
		}
};

int main()
{
	linkedlist L;

	L.insert(12);
	L.insert(18);
	L.insert(90);

	linkedlist M;
	M.insert(18);
	M.insert(14);
	M.insert(22);

	L.connect(M);
	L.display();
}