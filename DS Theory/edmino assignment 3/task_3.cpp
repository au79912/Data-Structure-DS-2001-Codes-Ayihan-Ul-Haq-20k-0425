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

		//return highest value in the level
		int max_level(node *root)
		{
			node *temp = root;
			queue<node*> q;
			q.push(temp);
			int max = 0;
			while(!q.empty())
			{
				temp = q.front();
				q.pop();
				if(temp->data > max)
					max = temp->data;
				if(temp->left != NULL)
					q.push(temp->left);
				if(temp->right != NULL)
					q.push(temp->right);
			}
			return max;
		}
		
		//return lowest value in the level
		int min_level(node *root)
		{
			node *temp = root;
			queue<node*> q;
			q.push(temp);
			int min = 0;
			while(!q.empty())
			{
				temp = q.front();
				q.pop();
				if(temp->data < min)
					min = temp->data;
				if(temp->left != NULL)
					q.push(temp->left);
				if(temp->right != NULL)
					q.push(temp->right);
			}
			return min;
		}

		//call min_level() and max_level() for each level
		void level_print_min_max()
		{
			node *temp = root;
			queue<node*> q;
			q.push(temp);
			while(!q.empty())
			{
				temp = q.front();
				q.pop();
				cout<<min_level(temp)<<" "<<max_level(temp)<<" ";
				if(temp->left != NULL)
					q.push(temp->left);
				if(temp->right != NULL)
					q.push(temp->right);
			}
		}

		//honestly I don't know what this is for
		
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
	bst.level_print_min_max();
	return 0;
}