#include <iostream>

using namespace std;

class node
{
public:
	node *left;
	node *right;
	int data;

	node()
	{
		left = NULL;
		right = NULL;
		data = 0;
	}

	node(int data)
	{
		left = NULL;
		right = NULL;
		this->data = data;
	}
};

class BST
{
	public:
		node *root;
		node *temp;

		BST()
		{
			root = NULL;
		}

		void insert(int data)
		{
			node *newnode = new node(data);

			if(root == NULL)
			{
				root = newnode;
				return;
			}

			temp = root;

			while(temp!=NULL)
			{
				if(data > temp->data)
				{
					if (temp->right == NULL)
					{
						temp->right = newnode;
						return;
					}
					else
					{
						temp = temp->right;
					}
				}

				else if(data< temp->data)
				{
					if(temp->left==NULL)
					{
						temp->left = newnode;
						return;
					}
					else
					{
						temp=temp->left;
					}
				}

				else
				{
					cout<<"Duplicate data"<<endl;
					return;
				}
			}
		}

		node *minValueNode(node *root)
		{
			node *temp = root;

			while(temp->left!=NULL)
			{
				temp = temp->left;
			}

			return temp;
		}

		node *maxValueNode(node *root)
		{
			node *temp = root;

			while(temp->right!=NULL)
			{
				temp = temp->right;
			}

			return temp;
		}

		void deleteNode(int data)
		{
			node *temp = root;
			node *parent = root;

			while(temp->data!=data)
			{
				parent = temp;

				if(data > temp->data)
				{
					temp = temp->right;
				}
				else
				{
					temp = temp->left;
				}
			}

			if(temp->left==NULL && temp->right==NULL)
			{
				if(temp==root)
				{
					root = NULL;
				}
				else if(parent->left==temp)
				{
					parent->left = NULL;
				}
				else
				{
					parent->right = NULL;
				}
			}

			else if(temp->left==NULL)
			{
				if(temp==root)
				{
					root = temp->right;
				}
				else if(parent->left==temp)
				{
					parent->left = temp->right;
				}
				else
				{
					parent->right = temp->right;
				}
			}

			else if(temp->right==NULL)
			{
				if(temp==root)
				{
					root = temp->left;
				}
				else if(parent->left==temp)
				{
					parent->left = temp->left;
				}
				else
				{
					parent->right = temp->left;
				}
			}
			
			else
			{
				node *successor = minValueNode(temp->right);
				temp->data = successor->data;
				deleteNode(successor->data);
			}
		}

		void inorder(node *printer)
		{
			if(printer!=NULL)
			{
				inorder(printer->left);
				cout<<printer->data<<" ";
				inorder(printer->right);
			}
		}

		void search(int data)
		{
			node *temp = root;

			while(temp!=NULL)
			{
				if(data > temp->data)
				{
					temp = temp->right;
				}
				else if(data < temp->data)
				{
					temp = temp->left;
				}
				else
				{
					cout<<"Found"<<endl;
					return;
				}
			}

			cout<<"Not Found"<<endl;
		}
};

int main(int argc, char const *argv[])
{
	BST bst;
	int arr[10];

	for (int i=0 ; i<10;i++)
	{
		cin>>arr[i];
		bst.insert(arr[i]);
	}

	bst.inorder(bst.root);
	cout<<endl;

	bst.deleteNode(5);
	bst.inorder(bst.root);
	cout<<endl;
	return 0;
}