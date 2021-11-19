#include <iostream>

using namespace std;

//node class for BST with key
class node
{
	public:
		int key;
		node *left;
		node *right;
		node(int k)
		{
			key = k;
			left = NULL;
			right = NULL;
		}
};

//BST class
class BST
{
	public:
		node *root;
		BST()
		{
			root = NULL;
		}
		void insert(int k)
		{
			node *temp = new node(k);
			if (root == NULL)
			{
				root = temp;
				return;
			}
			node *curr = root;
			node *prev = NULL;
			while (curr != NULL)
			{
				prev = curr;
				if (k < curr->key)
					curr = curr->left;
				else
					curr = curr->right;
			}
			if (prev == NULL)
			{
				root = temp;
				temp->left = curr;
			}
			else
			{
				if (k < prev->key)
					prev->left = temp;
				else
					prev->right = temp;
			}
		}
		void inorder(node *root)
		{
			if (root == NULL)
				return;
			inorder(root->left);
			cout << root->key << " ";
			inorder(root->right);
		}

		//delete node outside key
		void deleteNode(int k)
		{
			node *curr = root;
			node *prev = NULL;
			while (curr != NULL)
			{
				if (k == curr->key)
					break;
				prev = curr;
				if (k < curr->key)
					curr = curr->left;
				else
					curr = curr->right;
			}
			if (curr == NULL)
			{
				cout << "Node not found" << endl;
				return;
			}
			if (curr->left == NULL && curr->right == NULL)
			{
				if (prev == NULL)
					root = NULL;
				else
				{
					if (prev->left == curr)
						prev->left = NULL;
					else
						prev->right = NULL;
				}
				delete curr;
				return;
			}
			if (curr->left == NULL)
			{
				if (prev == NULL)
					root = curr->right;
				else
				{
					if (prev->left == curr)
						prev->left = curr->right;
					else
						prev->right = curr->right;
				}
				delete curr;
				return;
			}
			if (curr->right == NULL)
			{
				if (prev == NULL)
					root = curr->left;
				else
				{
					if (prev->left == curr)
						prev->left = curr->left;
					else
						prev->right = curr->left;
				}
				delete curr;
				return;
			}
			node *temp = curr->right;
			node *prev2 = NULL;
			while (temp->left != NULL)
			{
				prev2 = temp;
				temp = temp->left;
			}	
			curr->key = temp->key;
			if (prev2 == NULL)
				curr->right = temp->right;
			else
				prev2->left = temp->right;
			delete temp;
		}
};


//main function to test
int main()
{
	int i, j;
	BST bst;

	cout<<"Enter lower limit : ";
	cin>>i;

	cout<<"Enter upper limit : ";
	cin>>j;

	//insert 5 nodes
	for (int k = i; k <= j; k++)
		bst.insert(k);

	bst.deleteNode(i);
	bst.deleteNode(j);

}
