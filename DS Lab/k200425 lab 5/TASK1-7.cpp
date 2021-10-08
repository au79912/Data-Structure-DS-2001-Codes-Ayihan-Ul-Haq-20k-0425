#include <iostream>

using namespace std;

class node
{
public:
  int data;
  node *next;

    node ()
  {
    data = 0;
    next = NULL;
  }

  node (int data)
  {
    this->data = data;
  }
};


class singlylinkedlist
{
public:
  node * head;
  node *tail;
  node *temp;

  singlylinkedlist ()
  {
    head = NULL;
    tail = NULL;
  }
  singlylinkedlist (node * n)
  {
    head = n;
  }

  void insertnode (int data)
  {
    node *newnode = new node (data);

    if (head == NULL)
      {
	head = newnode;
	tail = head;
      }

    tail->next = newnode;
    tail = tail->next;
  }

  void insertnodefirst (int data, int postion)
  {
    node *newnode = new node (data);

    int count = postion;
    tail = head;

    while (count != 0)
      {
	tail = tail->next;
	count = count - 1;
	temp = tail;
      }

    temp = tail->next;
    tail->next = newnode;
    newnode->next = temp;
  }

  void deletelast ()
  {
    node *newnode = new node ();

    if (head == NULL)
      {
	head->data = 0;
      }
    temp = head;
    while (temp->next != NULL)
      {
      temp = temp->next;
      }

    temp->data = 0;
  }

  void deleteany (int data, int postion)
  {
    node *newnode = new node(data);

    int count=postion;
    tail = head;

    while (count != 0)
      {
	tail = tail->next;
	count = count - 1;
	temp = tail;
      }



    tail = temp->next;
    tail->next = newnode;
    newnode = temp->next;
  }

  void printlist ()
  {
    cout << endl;
    temp = head;
    while (temp != NULL)
      {
	cout << " " << temp->data;
	temp = temp->next;
      }
  }

  void Updatelist (int position, int data)
  {
    temp = head;
    int count = 0;
    while (count != position)
      {
	temp = temp->next;
      }
    temp->data = data;
  }
  
  
  void sort(){
			singlylinkedlist elist;
            singlylinkedlist olist;
			
			node *n=new node();
			int ecount=0;
			int ocount=0;
			
			n=head;
			
			while(n!=NULL){
				if(n->data%2==0){
					elist.insertnode(n->data);
					n=n->next;
				}
				else{
					olist.insertnode(n->data);
					n=n->next;
				}
				
			}
		
			elist.printlist();
			olist.printlist();
			
			
		}
};



int
main ()
{
  singlylinkedlist list;
  int choice;
  cout << "Enter the what you want to do with the linked list"
    << "\n1)Intsert node at end"
    << "\n2)insert node at first"
    << "\n3)Delete last node"
    << "\n4)Display linked list"
    << "\n5)Update node"
    << "\n6)Delete first node" 
    << "\n7)Delete any node"
    <<"\n8)sort"
    << "\n : ";

  cin >> choice;

  if (choice == 1)
    {
      list.insertnode (5);
      list.insertnode (10);
      list.insertnode(15);
    }
  else if (choice == 2)
    {
      list.insertnodefirst (7, 1);
    }
  else if (choice == 3)
    {
      list.deletelast ();
    }
  else if (choice == 4)
    {
      list.printlist ();
    }
  else if (choice == 5)
    {
    list.Updatelist (2, 3);
    }
    else if (choice == 7)
    {
    list.deleteany (2, 3);
    }
    else if(choice==8)
    {
        list.sort();
    }
    else if(choice==6)
    {
        list.deleteany(0,0);
    }
    
    



  return 0;
}
