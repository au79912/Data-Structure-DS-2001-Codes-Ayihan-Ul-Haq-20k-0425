using namespace std;
#include <iostream> 

class ShahbazNode {
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
class Linkedlist {
	ShahbazNode* head;
	ShahbazNode* tail;
	ShahbazNode* tailp;
	ShahbazNode* tmp;
	ShahbazNode* Last;
public:
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

	while (tail != NULL)
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

	cout << endl;
	tmp = Last;

	while (tmp!=NULL)
	{
		cout << " " << tmp->data;
		tmp = tmp->prev;
	}



}

int main()
{
	Linkedlist list;

	// Inserting nodes
	list.insertNode(1);
	list.insertNode(2);
	list.insertNode(3);
	list.insertNode(5);
	list.printList();
	list.insertNodeAny(7, 2);
		list.printList();
		list.deleteNode(2);
		list.printList();







}