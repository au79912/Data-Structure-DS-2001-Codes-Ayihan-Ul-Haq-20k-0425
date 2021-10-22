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
			
			//need to fix (insert circular)

			// if(tail->next==head)
			// {
			// 	temp=head->next;
			// 	while(temp!=head)
			// 	{
			// 		temp=temp->next;
			// 	}
			// 	tail->next=newnode;
			// 	newnode->prev=tail;
			// 	tail=tail->next;
			// 	tail->next=head;
			// } 

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
			return count;
		}

		void reverse()
		{
			node<T> *n = new node<T>();
			n=this->head;
			
			// node *temp=new node();
			temp=this->head;
			
			for(int i=0;i<this->lenth();i++)
			{
				while(n!=NULL)
				{
					swap(temp->data,n->data);
				}
				temp=temp->next;
				n=temp;
			}
		}

		bool operator==(linkedlist<T> &obj)
		{
			if(this->lenth()==obj.lenth())
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		void deletenode(int data1)
		{
			tail = head;
			while (tail != NULL)
			{
				if (tail->data == data1)
				{
					break;
				}
				temp = tail;
				tail = tail->next;
			}
			tail= tail->next ;
			temp->next = tail;
			tail->prev = temp;
		}

		void makecircular()
		{
			tail->next=head;
		}
};


int main(int argc, char const *argv[])
{
	linkedlist<int> list1;
	linkedlist<int> list2;
	
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
	
	// linkedlist<int> list2(list1);

	// list1.print();
	// cout<<endl;
	// list2.print();

	// list1.insert('q');
	// list2.insert(5);

	cout<<endl;
	list1.print();


	// list1.lenth();

	// list1.reverse();
	// list1.print();

	// cout<<endl;
	// list1.makecircular();
	// list1.insert(6);
	// list1.print();
}