#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

template <class T>
class node
{
	public:
		node *next;
		node *prev;
		T data;
		node(T d)
		{
			data = d;
			next = NULL;
			prev = NULL;
		}
		node()
		{
			next = NULL;
			prev = NULL;
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
		
		void insert_at_end(T d)
		{
			node<T> *newnode = new node<T>(d);
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

		void display()
		{
			temp=head;
			while(temp!=NULL)
			{
				if(temp->data=="if")
				{
					temp->data="If";
				}
				if(temp->data=="how")
				{
					temp->data="How";
				}
				cout<<temp->data<<endl;
				temp=temp->next;
			}
		}

		void remove_dup(node<T> *start)
		{
			node<T> *ptr1;
			node<T> *ptr2;
			node<T> *dup;

			ptr1=start;

			while(ptr1!=NULL && ptr1->next!=NULL)
			{
				ptr2=ptr1;

				while(ptr2->next!=NULL)
				{
					if(ptr1->data==ptr2->next->data)
					{
						dup=ptr2->next;
						ptr2->next=ptr2->next->next;
						delete dup;
					}
					else
					{
						ptr2=ptr2->next;
					}
				}
				ptr1=ptr1->next;
			}
		
		}

		int length(node<T> *start)
		{
			int count=0;
			node<T> *ptr=start;
			while(ptr!=NULL)
			{
				count++;
				ptr=ptr->next;
			}
			return count;
		}

	void sortList()
	{
		node<T> *current = NULL, *index = NULL;
		string temp;
		if(head == NULL)
		{
			return;
		}
		else
		{
			for(current = head; current->next != NULL; current = current->next)
			{
				if(current->data=="How")
				{
					current->data="how";
				}
				if(current->data=="If")
				{
					current->data="if";
				}
				for(index = current->next; index != NULL; index = index->next)
				{
					if(index->data=="How")
					{
						index->data="how";
					}
					if(index->data=="If")
					{
						index->data="if";
					}
					if(current->data > index->data)
					{
						temp = current->data;
						current->data = index->data;
						index->data = temp;
					}
				}
			}
		}
	}
};

void lower_string(char *str)
{
	for(int i=0;str[i]!='\0';i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
	}
}

int main(int argc, char const *argv[])
{
	linkedlist<string> L;
	char str[100];

	cin.getline(str,100);
	// lower_string(str);

	int n=strlen(str);
	string s;

	for(int i=0;i<n;i++)
	{
		if(str[i]!=' ')
		{
			s+=str[i];
		}
		else
		{
			L.insert_at_end(s);
			s="";
		}
	}

	L.insert_at_end(s);
	L.remove_dup(L.head);
	L.sortList();
	L.display();
	return 0;
}