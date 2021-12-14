#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class node
{
	public:
		node *left;
		node *right;
		int data;

		node(int data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		node()
		{
			left = NULL;
			right = NULL;
			// data = NULL;
		}
};

class BST
{
	public:
		node *root;
		node *current;
		node *parent;

		BST()
		{
			root = NULL;
			current = NULL;
			parent = NULL;
		}

		void insert(int data)
		{
			node *newNode = new node(data);
			if(root == NULL)
			{
				root = newNode;
				current = root;
				return;
			}
			else
			{
				current = root;
				while(current != NULL)
				{
					parent = current;
					if(data < current->data)
					{
						current = current->left;
						if(current == NULL)
						{
							parent->left = newNode;
							return;
						}
					}
					else
					{
						current = current->right;
						if(current == NULL)
						{
							parent->right = newNode;
							return;
						}
					}
				}
			}
		}

		//level wise print
		void level_print()
		{
			node *temp = root;
			queue<node*> q;
			q.push(temp);
			while(!q.empty())
			{
				temp = q.front();
				q.pop();
				cout<<temp->data<<" ";
				if(temp->left != NULL)
					q.push(temp->left);
				if(temp->right != NULL)
					q.push(temp->right);
			}
		}

		//print highest and lowest value in every level
		void print_level_wise_max_min()
		{
			node *temp = root;
			queue<node*> q;
			q.push(temp);
			int max = INT_MIN;
			int min = INT_MAX;
			while(!q.empty())
			{
				q.pop();
				if(temp->data > max)
					max = temp->data;
				if(temp->data < min)
					min = temp->data;
				if(temp->left != NULL)
					q.push(temp->left);
				if(temp->right != NULL)
					q.push(temp->right);
				
			}
		}
};

int main(int argc, char const *argv[])
{
	BST bst;
	int n;
	int data;

	cin>>n;
	for(int i = 0; i<n ; i++)
	{
		cin>>data;
		bst.insert(data);
	}

	// bst.level_print();
	cout<<"\n";
	bst.print_level_wise_max_min();
	return 0;
}