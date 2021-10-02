using namespace std;

#include <iostream> 

class ShahbazNode 
{

	public:
	int data;
	ShahbazNode* next;
	ShahbazNode* prev;

	ShahbazNode()
	{
		data = 0;
		next = NULL;
		prev = NULL;
	}

	// Parameterised Constructor
	ShahbazNode(int data)
	{
		this->data = data;
		this->next = NULL;
		this->prev= NULL;
	}
};

class Linkedlist 
{
	public:

	ShahbazNode* head;
	ShahbazNode* tail;
	ShahbazNode* tailp;
	ShahbazNode* tmp;
	ShahbazNode* Last;
	
	// Default constructor
	Linkedlist()
	{
		head = NULL;
		tail = NULL;
		Last = NULL;
	}

	void insertNode(int);
	void insertNodeAny(int, int);
	void printList();
	void deleteNode(int);
	void mergesort();
};

void Linkedlist::insertNode(int data)
{
	// Create the ShahbaznewNode.//Take Starting address=1001
	ShahbazNode* newNode = new ShahbazNode(data);

	//assinging this Node to as a Head
	if (head == NULL) {
		head = newNode;
		tail = head;

		return;
	}

	// Insert in the forword direction 1>2>3>4 
	tail->next = newNode;
	newNode->prev = tail;
	tail = tail->next;
	Last = tail;
	cout <<"Shahbaz" << Last->data;
}

void Linkedlist::insertNodeAny(int data, int position)
{
	int count = position;
	// Create the ShahbaznewNode.//Take Starting address=1001
	ShahbazNode* newNode = new ShahbazNode(data);
	tail = head;
	while (count != 0)
	{
		cout << endl << "Yes";
		tail = tail->next;
		count = count - 1;
		tmp = tail;
	}
	tmp = tail->next;
	tail->next = newNode;
	newNode->next = tmp;
	newNode->prev = tail;
	tmp->prev = newNode;
}

void Linkedlist::deleteNode(int data1)
{
	tail = head;

	while (tail->next != NULL)
	{
		//cout <<endl<< tail->data;
		if (tail->data == data1)
		{
			//        cout << "Yahoo";
			break;
		}

		tmp = tail;
		tail = tail->next;
	}
	tailp= tail->next ;
	tmp->next = tailp;
	tailp->prev = tmp;
}

void Linkedlist::printList()
{
	cout << endl;
	tmp = head;
	while (tmp != NULL)
	{
		cout << " " << tmp->data;
		tmp = tmp->next;
	}

	// cout << endl;
	// tmp = Last;

	// while (tmp!=NULL)
	// {
	// 	cout << " " << tmp->data;
	// 	tmp = tmp->prev;
	// }
}

void Linkedlist::mergesort()
{
	int count=0;
	tmp=head;
	while(tmp!=NULL)
	{
		count++;
		tmp=tmp->next;
	}

	tmp=head;

	int count2=0;
	while(count2!=count/2+1)
	{
		cout<<endl;
		// cout<<tmp->data<<" ";
		count2++;
		tmp=tmp->next;
	}

	Linkedlist newlist;
	for(int i=0;i<count;i++)
	{
		if(head->data>tmp->data)
		{
			newlist.insertNode(tmp->data);
			tmp=tmp->next;
		}
		else
		{
			newlist.insertNode(head->data);
			head=head->next;
		}
	}

	newlist.printList();
	// int datatemp;
	// for(int i=0;i<3;i++)
	// {
	// 	datatemp=head->data;
	// 	head=head->next;
	// 	if(datatemp>head->data)
	// 	{
	// 		swap(datatemp,head->data);
	// 	}
	// }
	
}

int main()
{
	Linkedlist list;

	// Inserting nodes
	list.insertNode(13);
	list.insertNode(21);
	list.insertNode(3);
	list.insertNode(15);
	list.insertNode(2);
	list.insertNode(1);

	// list.printList();
	
	// list.insertNodeAny(7, 2);
	
	// list.printList();
	
	// list.deleteNode(2);
	list.mergesort();
	
	// list.printList();
}