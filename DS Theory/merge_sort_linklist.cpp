#include <iostream>

using namespace std;

class node
{
public:
	int data;
	node *next;
	node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};


node* joinll(node* h1 ,node* h2)
{
	if(h1==NULL)
{
	return h2 ;
}

	if(h2 == NULL)
	{
		return h1 ;
	}
	
	node * head ;
	node* tail ;
	
	if(h1->data <= h2->data)
	{
		head = h1 ;
		tail = h1 ;
		h1=h1->next ;
	}
	else
	{
		head = h2 ;
		tail = h2 ;
		h2=h2->next ;
	
	}
	
	
	while(h1!=NULL && h2!=NULL)
	{
		if(h1->data <= h2->data)
	{
		tail->next = h1 ;
		tail = h1 ;
		h1=h1->next ;
			
	}
		else
	{
	tail->next = h2 ;
		tail = h2 ;
		h2=h2->next ;
	
	}
		
		
	}
	
	if(h1==NULL)
	{
		tail->next = h2 ;
	}
	else
	{
	tail->next = h1 ; 
	}
	
	return head ;
}
node* mergeSort(node *head) {
	
	if(head==NULL || head->next==NULL)
	{
		return head ;
	}
	
	node* slow = head ;
	node*fast = head->next ;

	while(fast!=NULL && fast->next!=NULL)
	{
		slow = slow->next ;
		fast =fast->next->next ;
	}
	node*h2 = slow->next ;
	slow->next =NULL ;
	
head = mergeSort(head) ;
h2 = mergeSort(h2) ; 
	
	return joinll(head , h2) ;
}


node *takeinput()
{
	int data;
	cin >> data;
	node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		node *newnode = new node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(node *head)
{
	node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	while (t)
	{
		node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}