#include <iostream>

using namespace std;

class node
{
	public:
		node *next;
		node *prev;
		string ID;
		int time;
		int quota;

		node()
		{
			next = NULL;
			prev = NULL;
			ID = "\0";
			time = 0;
			quota = 0;
		}
		node(string id, int t, int q)
		{
			next = NULL;
			prev = NULL;
			ID = id;
			time = t;
			quota = q;
		}
};

class linkedList
{
	node *head;
	node *tail;
	node *temp;

	public:
		linkedList()
		{
			head = NULL;
			tail = NULL;
		}

		void insert(string id, int t, int q)
		{
			node *temp = new node(id, t, q);
			if (head == NULL)
			{
				head = temp;
				tail = temp;
			}
			else
			{
				tail->next = temp;
				temp->prev = tail;
				tail = temp;
			}
		}

		void check_print()
		{
			temp = head;
			int n = temp->time;
			int m = temp->quota;
			while(head->time != 0)
			{
				if(temp->time != 0)
				{
					cout<<temp->ID<<endl;
					temp->time -= temp->quota;
				}
				temp = temp->next;
	
				if(temp->time != 0)
				{
					cout<<temp->ID<<endl;
					temp->time -= temp->quota;
				}
				temp = temp->next;

				if(temp->time != 0)
				{
					cout<<temp->ID<<endl;
					temp->time -= temp->quota;
				}
				n-=m;
				temp=head;
			}
		}
};

void tester(int something)
{
	cout<<"hello world";
}

int main(int argc, char const *argv[])
{
	linkedList l;
	int m;
	
	cin>>m;
	for(int i=0;i<m; i++)
	{
		string id;
		int t, q;
		cin>>id>>t>>q;
		l.insert(id, t, q);
	}
	l.check_print();
	return 0;
}
