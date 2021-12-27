#include <iostream>

using namespace std;

//node class for a avl tree
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

//avl tree class
class avl
{
public:
	node *root;
	avl()
	{
		root = NULL;
	}
	// return height of tree
	int height(node *curr)
	{
		if (curr == NULL)
		{
			return 0;
		}
		else
		{
			int l = height(curr->left);
			int r = height(curr->right);
			if (l > r)
			{
				return l + 1;
			}
			else
			{
				return r + 1;
			}
		}
	}

	// return balance factor of tree
	int balance(node *curr)
	{
		if (curr == NULL)
		{
			return 0;
		}
		else
		{
			int l = height(curr->left);
			int r = height(curr->right);
			return l - r;
		}
	}

	// rotate left
	node *rotate_left(node *curr)
	{
		node *temp = curr->right;
		curr->right = temp->left;
		temp->left = curr;
		return temp;
	}

	// rotate right
	node *rotate_right(node *curr)
	{
		node *temp = curr->left;
		curr->left = temp->right;
		temp->right = curr;
		return temp;
	}

	// balance tree
	node *balance_tree(node *curr)
	{
		if (balance(curr) == 2)
		{
			if (balance(curr->left) == 1)
			{
				curr->left = rotate_left(curr->left);
			}
			curr = rotate_right(curr);
		}
		else if (balance(curr) == -2)
		{
			if (balance(curr->right) == -1)
			{
				curr->right = rotate_right(curr->right);
			}
			curr = rotate_left(curr);
		}
		return curr;
	}

	// print tree
	void print_tree(node *curr)
	{
		if (curr != NULL)
		{
			print_tree(curr->left);
			cout << curr->data << " ";
			print_tree(curr->right);
		}
	}

	//insert with balnce
	void insert(int d)
	{
		node *temp = new node(d);
		if (root == NULL)
		{
			root = temp;
		}
		else
		{
			node *curr = root;
			node *prev = NULL;
			while (curr != NULL)
			{
				prev = curr;
				if (d < curr->data)
				{
					curr = curr->left;
				}
				else
				{
					curr = curr->right;
				}
			}
			if (d < prev->data)
			{
				prev->left = temp;
			}
			else
			{
				prev->right = temp;
			}
			root = balance_tree(root);
		}
	}

	//print tree inorder
	void print_tree_inorder()
	{
		print_tree(root);
	}
};

//

//driver function
int main()
{
	int n;
	avl tree;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int d;
		cin>>d;
		avl tree;
		tree.insert(d);
	}

	tree.print_tree(tree.root);

	return 0;
}