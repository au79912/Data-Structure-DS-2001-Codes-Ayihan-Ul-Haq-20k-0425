#include <iostream>
#include <vector>

using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648
// node class for a bst
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

// bst class
class bst
{
public:
	node *root;
	bst()
	{
		root = NULL;
	}
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
		}
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

	void per_level_min(node *curr, vector<int> &vec, int lvl)
	{
		if (curr != NULL)
		{
			per_level_min(curr->left, vec, lvl + 1);

			if (curr->data < vec[lvl])
				vec[lvl] = curr->data;

			per_level_min(curr->right, vec, lvl + 1);
		}
	}

	void per_level_max(node *curr, vector<int> &vec, int lvl)
	{
		if (curr != NULL)
		{

			per_level_max(curr->left, vec, lvl + 1);

			if (curr->data > vec[lvl])
				vec[lvl] = curr->data;

			per_level_max(curr->right, vec, lvl + 1);
		}
	}

	void utility_func(node *root)
	{
		int n = height(root);
		int i;

		vector<int> res(n, INT_MAX);
		vector<int> res1(n, INT_MIN);

		per_level_min(root, res, 0);
		per_level_max(root, res1, 0);

		for (i = 0; i < n; i++)
		{
			cout << res[i] << " ";
			cout << res1[i];
			cout << endl;
		}
	}
};

int main(int argc, char const *argv[])
{
	bst b;

	int data;
	int count;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		cin >> data;
		b.insert(data);
	}

	b.utility_func(b.root);

	return 0;
}