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

		void delete_node(node *del, int data)
		{
			if(del == NULL)
			{
				cout<<"Node not found"<<endl;
				return;
			}

			if(data < del->data)
			{
				delete_node(del->left, data);
			}
			else if(data > del->data)
			{
				delete_node(del->right, data);
			}
			else
			{
				if(del->left == NULL && del->right == NULL)
				{
					delete del;
					del = NULL;
					return;
				}
				else if(del->left == NULL)
				{
					node *temp = del;
					del = del->right;
					delete temp;
					return;
				}
				else if(del->right == NULL)
				{
					node *temp = del;
					del = del->left;
					delete temp;
					return;
				}
				else
				{
					node *temp = minValueNode(del->right);
					del->data = temp->data;
					delete_node(del->right, temp->data);
				}
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
};

int main(int argc, char const *argv[])
{
	BST bst;
	int arr[5]={50,40,70,60,80};

	for (int i=0 ; i<5;i++)
	{
		bst.insert(arr[i]);
	}

	bst.inorder(bst.root);
	cout<<endl;

	bst.delete_node(bst.root, 50);
	bst.inorder(bst.root);
	cout<<endl;
	return 0;
}

