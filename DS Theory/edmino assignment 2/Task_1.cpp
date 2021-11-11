#include <iostream>
#include <cstring>

using namespace std;

class node
{
	public:
		node *next;
		int coffec; //coefficent (2)x^2
		char var; //variable 2(x)^2
		int exp; //exponent 2x^(2)

		node()
		{
			next = NULL;
			coffec = 0;
			var = '\0';
			exp = 0;
		}

		node(int coffec, char var, int exp)
		{
			next = NULL;
			this->coffec = coffec;
			this->var = var;
			this->exp = exp;
		}
};

class linkedlist
{
	public:
		node *head;
		node *tail;
		node *temp;

		linkedlist()
		{
			head = tail =NULL;
			temp=NULL;
		}

		void inserting_polynomial(int coffec, char var, int exp)
		{
			node *newnode = new node(coffec, var, exp);
			if(head == NULL)
			{
				head = newnode;
				tail = newnode;
			}

			else
			{
				tail->next = newnode;
				tail = newnode;
			}
		}

		void add_polynomial(linkedlist *list1, linkedlist *list2)
		{
			node *temp1 = list1->head;
			node *temp2 = list2->head;
			while(temp1 != NULL && temp2 != NULL)
			{
				if(temp2->coffec<0 || temp1->coffec<0)
				{
					if(temp2->coffec<0)
					{
						inserting_polynomial(temp2->coffec, temp2->var, temp2->exp);
						temp2 = temp2->next;
					}

					if(temp1->coffec<0)
					{
						inserting_polynomial(temp1->coffec, temp1->var, temp1->exp);
						temp1 = temp1->next;
					}
				}

				else if(temp1->exp == temp2->exp)
				{
					inserting_polynomial(temp1->coffec + temp2->coffec, temp1->var, temp1->exp);
					temp1 = temp1->next;
					temp2 = temp2->next;
				}

				else if(temp1->exp > temp2->exp)
				{
					inserting_polynomial(temp1->coffec, temp1->var, temp1->exp);
					temp1 = temp1->next;
				}
				
				else
				{
					inserting_polynomial(temp2->coffec, temp2->var, temp2->exp);
					temp2 = temp2->next;
				}
			}

			while(temp1 != NULL)
			{
				inserting_polynomial(temp1->coffec, temp1->var, temp1->exp);
				temp1 = temp1->next;
			}
			
			while(temp2 != NULL)
			{
				inserting_polynomial(temp2->coffec, temp2->var, temp2->exp);
				temp2 = temp2->next;
			}
		}

		void sort_polynomial()
		{
			node *temp1 = head;
			node *temp2 = head;
			
			while(temp1 != NULL)
			{
				temp2 = temp1;
			
				while(temp2->next != NULL)
				{
					if(temp1->exp > temp2->next->exp)
					{
						int coffec = temp1->coffec;
						char var = temp1->var;
						int exp = temp1->exp;
						temp1->coffec = temp2->next->coffec;
						temp1->var = temp2->next->var;
						temp1->exp = temp2->next->exp;
						temp2->next->coffec = coffec;
						temp2->next->var = var;
						temp2->next->exp = exp;
					}

					if(temp1->coffec==temp2->next->coffec && temp1->var>temp2->next->var)
					{
						int coffec = temp1->coffec;
						char var = temp1->var;
						int exp = temp1->exp;
						temp1->coffec = temp2->next->coffec;
						temp1->var = temp2->next->var;
						temp1->exp = temp2->next->exp;
						temp2->next->coffec = coffec;
						temp2->next->var = var;
						temp2->next->exp = exp;
					}
					temp2 = temp2->next;
				}
				temp1 = temp1->next;
			}
		}

		
		void display_polynomial()
		{
			node *temp = head;
			int counter=0;

			while(temp != NULL)
			{
				counter++;
				temp = temp->next;
			}
			cout<<counter<<endl;
			temp = head;

			while(temp != NULL)
			{
				while(temp != NULL)
				{
					if(temp->var == 'X')
					{
						cout<<temp->coffec<<" "<<temp->var<<" "<<temp->exp<<endl;
						temp = temp->next;
					}
					else
						temp=temp->next;
				}

				temp = head;

				while(temp != NULL)
				{
					if(temp->var == 'Y')
					{
						cout<<temp->coffec<<" "<<temp->var<<" "<<temp->exp<<endl;
						temp = temp->next;
					}
					else
						temp=temp->next;
				}
			}
		}
};

int main()
{
	linkedlist *list1 = new linkedlist();
	linkedlist *list2 = new linkedlist();
	linkedlist *result = new linkedlist();
	int coffec, exp;
	char var;

	int n1=0, n2=0; //number of equations in first and second polynomial
	int k1=0,k2=0; //checker for polynomial 1 and 2


	cin>>n1;
	do
	{
		cin>>coffec>>var>>exp;
		list1->inserting_polynomial(coffec, var, exp);
		k1++;

	} while(k1!=n1);

	cin>>n2;
	do
	{
		cin>>coffec>>var>>exp;
		list2->inserting_polynomial(coffec, var, exp);
		k2++;
	}while(k2!=n2);
 	
	result->add_polynomial(list1, list2);
	result->sort_polynomial();
	result->display_polynomial();
	cout<<endl;


	return 0;
}
