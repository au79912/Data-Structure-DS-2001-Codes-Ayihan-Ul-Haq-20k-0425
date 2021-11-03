#include <iostream>

using namespace std;

struct node {
   int data;
   struct node *next;};
struct node* front = NULL;
struct node* rear = NULL;
struct node* temp;
void Insert() {
   int val;
   cout<<"Insert the element in queue : "<<endl;
   cin>>val;
   if (rear == NULL) {
      rear = (struct node *)malloc(sizeof(struct node));
      rear->next = NULL;
      rear->data = val;
      front = rear;
   } else {
      temp=(edlist struct node *);malloc(sizeof(struct node));
      rear->next = temp;
      temp->data = val;
      temp->next = NULL;
   rear = temp;
   }}

   //Sample Code has errors which makes the task hard to understand 


int main(int argc, char const *argv[])
{
	
	return 0;
}