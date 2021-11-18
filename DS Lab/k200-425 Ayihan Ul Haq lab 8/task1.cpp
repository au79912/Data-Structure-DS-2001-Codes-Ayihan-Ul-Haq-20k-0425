#include <iostream>

using namespace std;

class node
{
public:
	int data;
	node *next;
	node(int d)
	{
		data = d;
		next = NULL;
	}
};

//binary search tree
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
				curr = curr->next;
			else
				break;
		}
		if (prev == NULL)
		{
			root = temp;
			temp->next = curr;
		}
		else
		{
			prev->next = temp;
			temp->next = curr;
		}
	}
	void inorder(node *root)
	{
		if (root == NULL)
			return;
		inorder(root->next);
		cout << root->data << " ";
	}
	void preorder(node *root)
	{
		if (root == NULL)
			return;
		cout << root->data << " ";
		preorder(root->next);
	}
	void postorder(node *root)
	{
		if (root == NULL)
			return;
		postorder(root->next);
		cout << root->data << " ";
	}


};

bool isBST(node *root, int min, int max)
{
	if (root == NULL)
		return true;
	if (root->data < min || root->data > max)
		return false;
	return isBST(root->next, min, root->data) && isBST(root->next, root->data, max);
}

int main()
{
	BST bst;

	if (isBST(bst.root, -1000, 1000)==true)
		cout << "10 points" << endl;
	else
		cout << "0 points" << endl;

	return 0;
}