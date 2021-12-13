#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//node class for bst
class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

//BST class with level wise traversal
class BST
{
public:
	Node* root;
	BST()
	{
		root = NULL;
	}
	void insert(int data)
	{
		Node* newNode = new Node(data);
		if (root == NULL)
		{
			root = newNode;
		}
		else
		{
			Node* temp = root;
			while (temp != NULL)
			{
				if (data < temp->data)
				{
					if (temp->left == NULL)
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
					if (temp->right == NULL)
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
	void levelOrder()
	{
		if (root == NULL)
		{
			cout << "Tree is empty" << endl;
		}
		else
		{
			queue<Node*> q;
			q.push(root);
			while (!q.empty())
			{
				Node* temp = q.front();
				q.pop();
				cout << temp->data << " ";
				if (temp->left != NULL)
				{
					q.push(temp->left);
				}
				if (temp->right != NULL)
				{
					q.push(temp->right);
				}
			}
		}
	}
	//get highest value in the level
	int getMax(Node* root)
	{
		if (root == NULL)
		{
			return INT_MIN;
		}
		else
		{
			int max = root->data;
			int leftMax = getMax(root->left);
			int rightMax = getMax(root->right);
			if (leftMax > max)
			{
				max = leftMax;
			}
			if (rightMax > max)
			{
				max = rightMax;
			}
			return max;
		}
	}

	//get lowest value in the level
	int getMin(Node* root)
	{
		if (root == NULL)
		{
			return INT_MAX;
		}
		else
		{
			int min = root->data;
			int leftMin = getMin(root->left);
			int rightMin = getMin(root->right);
			if (leftMin < min)
			{
				min = leftMin;
			}
			if (rightMin < min)
			{
				min = rightMin;
			}
			return min;
		}
	}
};

//driver function
int main()
{
	BST bst;
	int arr[10];
	
	for (int i=0;i<10;i++)
	{
		cin>>arr[i];
	}

	for (int i=0;i<10;i++)
	{
		bst.insert(arr[i]);
	}

	return 0;
}