
#include <iostream> 
#include <vector> 
 
using namespace std; 

struct Node
{
	int data; 
	struct Node *left, *right; 
}; 
  
// return height of tree 
int heightoftree(Node* root) 
{

	if (root == NULL) 
		return 0; 

	int left = heightoftree(root->left); 
	int right = heightoftree(root->right); 

	return ((left > right ? left : right) + 1); 
}

void printPerLevelMinimum(Node* root,vector<int>& res, int level) 
{
	if (root != NULL) 
	{ 

		printPerLevelMinimum(root->left, res, level + 1); 

		if (root->data < res[level]) 
			res[level] = root->data; 

		printPerLevelMinimum(root->right,res, level + 1); 
	}
}

void perLevelMinimumUtility(Node* root) 
{
	int n = heightoftree(root), i; 
	vector<int> res(n, INT_MAX); 
	printPerLevelMinimum(root, res, 0); 

	cout << "Every level minimum is"; 
	for (i = 0; i < n; i++) 
	{ 
		cout << "level " << i <<" min is = "<< res[i] << " "; 
	} 
}

Node* newNode(int data) 
{ 
	Node* temp = new Node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 

	return temp; 
} 
  
int main() 
{ 
	Node* root = newNode(7); 
	root->left = newNode(6); 
	root->right = newNode(5); 
	root->left->left = newNode(4); 
	root->left->right = newNode(3); 
	root->right->left = newNode(2); 
	root->right->right = newNode(1); 

	perLevelMinimumUtility(root); 

	return 0; 
} 