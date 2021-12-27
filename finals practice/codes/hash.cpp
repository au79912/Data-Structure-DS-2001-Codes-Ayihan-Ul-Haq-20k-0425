#include <iostream>

using namespace std;
const int table_size = 20;

class node
{
	public:
	int key;
	int data;
	node *next;

	node()
	{
		key = 0;
		next = NULL;
	}

	node(int key, int data)
	{
		this->key = key;
		this->data= data;
		next = NULL;
	}
};

class Hash
{
	node *table[table_size]; //make global const in table_size = number

	public:
		Hash()
		{
			for(int i=0;i<table_size;i++)
			{
				table[i]=NULL;
			}
		}

		int divisionHash(int data)
		{
			return data % table_size;
		}

		void insert(int key, int data)
		{
			node *newnode = new node(key, data);
			int index = divisionHash(key);

			if(table[index]==NULL)
			{
				table[index]=newnode;
				return;
			}

			node *temp= table[index];
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next =newnode ;
		}

		void search(int key)
		{
			int index = divisionHash(key);
			node *temp= table[index];

			while(temp!=NULL)
			{
				if(temp->key==key)
				{
					cout<<"\nData found at index "<<index<<" is "<<temp->data;
					return;
				}
				temp = temp->next;
			}

			cout<<"\nData not found";
		}

		void remove(int key)
		{
			int index = divisionHash(key);

			node *temp= table[index];
			node *prev=NULL;

			while(temp!=NULL)
			{
				if(temp->key==key)
				{
					if(prev==NULL)
					{
						table[index]=temp->next;
					}
					else
					{
						prev->next=temp->next;
					}
					cout<<"\nData deleted";
					return;
				}
				prev=temp;
				temp=temp->next;
			}
			cout<<"\nData not found";
		}

		bool is_empty()
		{
			for(int i=0;i<table_size;i++)
			{
				if(table[i]!=NULL)
				{
					return false;
				}
			}
			return true;
		}

		void display()
		{
			for(int i=0;i<table_size;i++)
			{
				node *temp=table[i];
				while(temp!=NULL)
				{
					cout<<"\n"<<temp->key<<" "<<temp->data;
					temp=temp->next;
				}
			}
		}
};


int main(int argc, char const *argv[])
{
	Hash h;
	int choice, key, data;

	do
	{
		cout<<"\n1. Insert";
		cout<<"\n2. Search";
		cout<<"\n3. Delete";
		cout<<"\n4. Display";
		cout<<"\n5. Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				cout<<"\nEnter key: ";
				cin>>key;
				cout<<"\nEnter data: ";
				cin>>data;
				h.insert(key, data);
				break;

			case 2:
				cout<<"\nEnter key: ";
				cin>>key;
				h.search(key);
				break;

			case 3:
				cout<<"\nEnter key: ";
				cin>>key;
				h.remove(key);
				break;

			case 4:
				h.display();
				break;

			case 5:
				break;

			default:
				cout<<"\nWrong choice";
		}
	}while(choice!=5);

	return 0;
}