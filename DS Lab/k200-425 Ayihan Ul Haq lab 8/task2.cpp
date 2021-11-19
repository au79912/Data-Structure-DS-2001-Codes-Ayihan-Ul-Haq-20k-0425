#include <iostream>

using namespace std;

//node class for binary tree
class node
{
	public:
		int key;
		string name;
		node *next;
		node *right;
		node *left;


		node(int key, string name)
		{
			this->key = key;
			this->name = name;
			this->right = NULL;
			this->left = NULL;
		}

		node()
		{
			this->key = 0;
			this->name = "\0";
			this->right = NULL;
			this->left = NULL;
		}
};


class binaryTree
{
	private:
		node *root;
		node *temp;
	
	public:
		void addNode(int key, string name)
		{
			node *newNode = new node(key, name);
			if(root == NULL)
			{
				root = newNode;
			}
			else
			{
				temp = root;
				while(temp != NULL)
				{
					if(key < temp->key)
					{
						if(temp->left == NULL)
						{
							temp->left = newNode;
							break;
						}
						else
						{
							temp = temp->left;
						}
					}
					else
					{
						if(temp->right == NULL)
						{
							temp->right = newNode;
							break;
						}
						else
						{
							temp = temp->right;
						}
					}
				}
			}
		}

		void printTree()
		{
			if(root == NULL)
			{
				cout << "Tree is empty" << endl;
			}
			else
			{
				temp = root;
				cout << "Tree: " << endl;
				cout << "Root: " << temp->name << endl;
				cout << "Left: ";
				if(temp->left == NULL)
				{
					cout << "NULL" << endl;
				}
				else
				{
					temp = temp->left;
					cout << temp->name << endl;
				}
				cout << "Right: ";
				if(temp->right == NULL)
				{
					cout << "NULL" << endl;
				}
				else
				{
					temp = temp->right;
					cout << temp->name << endl;
				}
			}
		}
};


int main()
{
	int arr[]={15, 10 , 20 , 8 , 12, 16  , 25};

	int n= sizeof(arr)/sizeof(arr[0]);

	binaryTree tree;


	for (int i = 0 ; i < n; i++)
	{
		tree.addNode(arr[i], "Node");
	}

	tree.printTree();
}