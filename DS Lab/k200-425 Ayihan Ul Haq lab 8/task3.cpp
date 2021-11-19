#include <iostream>

using namespace std;

//node class for BST
class node
{
	public:
		int data;
		node *left;
		node *right;
		node(int d)
		{
			data = d;
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
		void insert(int d)
		{
			node *temp = new node(d);
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
				if (d < curr->data)
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
				if (d < prev->data)
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
			cout << root->data << " ";
			inorder(root->right);
		}

		void preorder(node *root)
		{
			if (root == NULL)
				return;
			cout << root->data << " ";
			preorder(root->left);
			preorder(root->right);
		}
};

//main function
int main()
{
	BST tree;
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);

	cout << "Inorder traversal of the given tree: ";
	tree.inorder(tree.root);

	cout << "\nPreorder traversal of the given tree: ";
	tree.preorder(tree.root);
	return 0;
}