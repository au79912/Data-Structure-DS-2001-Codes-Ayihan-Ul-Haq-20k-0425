#include <iostream>

using namespace std;

//node class for BST
class Node
{
public:
	int data;
	Node *left;
	Node *right;

	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}

	Node()
	{
		this->data = 0;
		this->left = NULL;
		this->right = NULL;
	}

	~Node()
	{
		delete this->left;
		delete this->right;
	}
};


//BST class
class BST
{
public:
	Node *root;

	BST()
	{
		this->root = NULL;
	}

	~BST()
	{
		delete this->root;
	}

	//insert node into BST
	void insert(int data)
	{
		Node *newNode = new Node(data);
		if (this->root == NULL)
		{
			this->root = newNode;
			return;
		}
		Node *temp = this->root;
		while (true)
		{
			if (data < root->data)
			{
				if (root->left == NULL)
				{
					root->left = newNode;
					return;
				}
				else
				{
					temp = root->left;
				}
			}
			else
			{
				if (root->right == NULL)
				{
					root->right = newNode;
					return;
				}
				else
				{
					temp = root->right;
				} 
			}
		}
	}

	//search for node in BST
	bool search(int data)
	{
		Node *current = this->root;
		while (current != NULL)
		{
			if (data == current->data)
				return true;
			else if (data < current->data)
				current = current->left;
			else
				current = current->right;
		}
		return false;
	}

	//delete node from BST
	void deleteNode(int data)
	{
		Node *current = this->root;
		Node *parent = NULL;
		while (current != NULL)
		{
			if (data == current->data)
				break;
			else if (data < current->data)
			{
				parent = current;
				current = current->left;
			}
			else
			{
				parent = current;
				current = current->right;
			}
		}
		if (current == NULL)
			return;
		if (current->left == NULL && current->right == NULL)
		{
			if (parent == NULL)
				this->root = NULL;
			else if (parent->left == current)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		else if (current->left == NULL)
		{
			if (parent == NULL)
				this->root = current->right;
			else if (parent->left == current)
				parent->left = current->right;
			else
				parent->right = current->right;
		}
		else if (current->right == NULL)
		{
			if (parent == NULL)
				this->root = current->left;
			else if (parent->left == current)
				parent->left = current->left;
			else
				parent->right = current->left;
		}
		else
		{
			Node *successor = current->right;
			Node *successorParent = current;
			while (successor->left != NULL)
			{
				successorParent = successor;
				successor = successor->left;
			}
			if (successorParent->left == successor)
				successorParent->left = successor->right;
			else
				successorParent->right = successor->right;
			current->data = successor->data;
		}
	}

	//print BST recursively
	void print(Node *node)
	{
		if (node == NULL)
			return;
		print(node->left);
		cout << node->data << " ";
		print(node->right);
	}
};

//main function
int main()
{
	int arr[5];
	int d;
	BST bst;

	for(int i=0; i<5; i++)
	{
		cin>>arr[i];
		bst.insert(arr[i]);
	}

	bst.print(bst.root);

	cout<<endl;

	bst.deleteNode(5);
	bst.print(bst.root);

	return 0;
}