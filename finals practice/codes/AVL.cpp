#include <iostream>

using namespace std;

class node
{
public:
	int key;
	node *left;
	node *right;
	int height;

	node()
	{
		key = 0;
		left = NULL;
		right = NULL;
		height = 1;
	}

	node(int key)
	{
		this->key = key;
		left = NULL;
		right = NULL;
		height = 1;
	}
};

class avl
{
public:
	node *root;

	avl()
	{
		root = NULL;
	}

	int height(node *n)
	{
		if (n == NULL)
			return 0;
		return n->height;
	}

	int max(int a, int b)
	{
		return (a > b) ? a : b;
	}

	node *rightrotate(node *temp)
	{
		node *x = temp->left;
		node *T2 = x->right;

		x->right = temp;
		temp->left = T2;

		temp->height = max(height(temp->left), height(temp->right)) + 1;
		x->height = max(height(x->left), height(x->right)) + 1;

		return x;
	}

	node *leftrotate(node *temp)
	{
		node *y = temp->left;
		node *T2 = y->right;

		y->left = temp;
		temp->right = T2;

		temp->height = max(height(temp->left), height(temp->right)) + 1;
		y->height = max(height(y->left), height(y->right)) + 1;

		return y;
	}

	int getbalance(node *temp)
	{
		if (temp == NULL)
			return 0;

		return height(temp->left) - height(temp->right);
	}

	node *insert(node *temp, int key)
	{
		if (root == NULL)
		{
			node *newnode = new node(key);
			root = newnode;
		}

		if (key < root->key)
		{
			root->left = insert(temp->left, key);
		}
		else if (key > root->key)
		{
			root->right = insert(temp->right, key);
		}

		else
			return temp;

		temp->height = 1 + max(height(temp->left), height(temp->right));

		int balance = getbalance(temp);

		if (balance > 1 && key < temp->left->key)
		{
			return rightrotate(temp);
		}

		if (balance > 1 && key < temp->left->key)
		{
			return leftrotate(temp);
		}

		// Left Right Case
		if (balance > 1 && key > temp->left->key)
		{
			temp->left = leftrotate(temp->left);
			return rightrotate(temp);
		}

		// Right Left Case
		if (balance < -1 && key < temp->right->key)
		{
			temp->right = rightrotate(temp->right);
			return leftrotate(temp);
		}
	}

	void preorder(node *root)
	{
		if (root == NULL)
		{
			return;
		}

		cout << root->key << " ";
		preorder(root->left);
		preorder(root->right);
	}
};

int main(int argc, char const *argv[])
{
	avl tree;

	for (int i = 0; i < 5; i++)
	{
		tree.insert(tree.root, i);
	}

	tree.preorder(tree.root);
	return 0;
}