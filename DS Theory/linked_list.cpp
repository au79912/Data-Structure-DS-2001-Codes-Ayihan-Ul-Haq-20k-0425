#include <iostream>

using namespace std;

template <class T>
class node
{
	public:
		node *next;
		node *prev;
		T data;
		node(T data)
		{
			this->data=data;
		}
		node()
		{
			prev=NULL;
			next=NULL;
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
			temp=NULL;
			tail=NULL;
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

		void print()
		{
			temp=head;
			while(temp!=NULL)
			{
				cout<<" "<<temp->data;
				temp=temp->next;
			}
		}

		linkedlist(const linkedlist &cpy)
		{
			//deep copy
			head=NULL;
			temp=cpy.head;

			while (temp!=NULL)
			{
				this->insert(temp->data);
				temp=temp->next;
			}

			//for shallow copy
			// head=NULL;
			// *this=cpy;
		}

		int lenth()
		{
			temp=this->head;
			int count=0;
			while(temp!=NULL)
			{
				count++;
				temp=temp->next;
			}

			cout<<endl<<count;
			return count;
		}

		void reverse()
		{
			node<T> *n=new node<T>();
			n=head;
			
			// node *temp=new node();
			temp=head;
			
			for(int i=0;i<this->lenth();i++)
			{
				while(n!=NULL)
				{
					T tmp;
					tmp = temp->data;
					temp->data = n->data;
					n->data = tmp;
				}
				temp=temp->next;
				n=temp;
			}
		}
};


int main(int argc, char const *argv[])
{
	linkedlist<int> list1;
	
	int i;

	cout<<"Enter the Number of elements : ";
	cin>>i;
	
	int *array=new int[i];
	
	for(int j=0;j<i;j++)
	{
		fflush(stdin);
		cout<<"Insert node "<< j+1<< " : ";
		cin>>array[j];
		list1.insert(array[j]);
	}

	// linkedlist<char> list2(list1);

	// list1.print();
	// cout<<endl;
	// list2.print();

	// list1.insert('q');
	// list2.insert('p');

	// cout<<endl;
	// list1.print();
	// cout<<endl;
	// list2.print();

	// list1.reverse();
	list1.print();
	list1.lenth();
	return 0;
}