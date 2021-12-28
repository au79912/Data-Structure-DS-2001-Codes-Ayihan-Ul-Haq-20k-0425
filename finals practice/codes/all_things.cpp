#include <iostream>

using namespace std;
const int table_size = 20;

// hashing

// class Hash
// {
// public:
// 	int data;
// 	int key;
// 	Hash *next;

// 	Hash()
// 	{
// 		data = 0;
// 		key = 0;
// 		next = NULL;
// 	}
// 	Hash(int key, int data)
// 	{
// 		this->key = key;
// 		this->data = data;
// 		next = NULL;
// 	}
// };

// class hashtable
// {
// 	Hash *table[table_size];

// public:
// 	hashtable()
// 	{
// 		for (int i = 0; i < table_size; i++)
// 		{
// 			table[i] = NULL;
// 		}
// 	}

// 	int hashfunc(int key)
// 	{
// 		return key % table_size;
// 	}

// 	void insert(int key, int data)
// 	{
// 		Hash *newnode = new Hash(key, data);
// 		int index = hashfunc(key);

// 		if (table[index] == NULL)
// 		{
// 			table[index] = newnode;
// 			return;
// 		}

// 		Hash *temp = table[index];
// 		while (temp->next != NULL)
// 		{
// 			temp = temp->next;
// 		}
// 		temp->next = newnode;
// 	}

// 	void search_key(int key)
// 	{
// 		int index = hashfunc(key);

// 		if (table[index] == NULL)
// 		{
// 			cout << "Key not found" << endl;
// 			return;
// 		}

// 		Hash *temp = table[index];
// 		while (temp != NULL)
// 		{
// 			if (temp->key == key)
// 			{
// 				cout << "Data found at index " << index << " is " << temp->data << endl;
// 				return;
// 			}
// 			temp = temp->next;
// 		}
// 		cout << "Key not found" << endl;
// 	}

// 	void search_data(int data)
// 	{
// 		for (int i = 0; i < table_size; i++)
// 		{
// 			if (table[i] == NULL)
// 			{
// 				continue;
// 			}
// 			Hash *temp = table[i];
// 			while (temp != NULL)
// 			{
// 				if (temp->data == data)
// 				{
// 					cout << "Key found at index " << i << " is " << temp->key << endl;
// 					return;
// 				}
// 				temp = temp->next;
// 			}
// 		}
// 		cout << "Data not found" << endl;
// 	}

// 	void remove(int key)
// 	{
// 		int index = hashfunc(key);

// 		if (table[index] == NULL)
// 		{
// 			cout << "Key not found" << endl;
// 			return;
// 		}

// 		Hash *temp = table[index];
// 		Hash *prev = NULL;

// 		while (temp != NULL)
// 		{
// 			if (temp->key == key)
// 			{
// 				if (prev == NULL)
// 				{
// 					table[index] = temp->next;
// 					delete temp;
// 					return;
// 				}
// 				prev->next = temp->next;
// 				delete temp;
// 				return;
// 			}
// 			prev = temp;
// 			temp = temp->next;
// 		}
// 		cout << "Key not found" << endl;
// 	}

// 	void display()
// 	{
// 		for (int i = 0; i < table_size; i++)
// 		{
// 			if (table[i] == NULL)
// 			{
// 				continue;
// 			}
// 			Hash *temp = table[i];
// 			while (temp != NULL)
// 			{
// 				cout << "Key at index " << i << " is " << temp->key << " and data is " << temp->data << endl;
// 				temp = temp->next;
// 			}
// 		}
// 	}
// };

// main(int argc, char const *argv[])
// {
// 	hashtable ht;
// 	int size = 0;

// 	cin >> size;
// 	int *arr = new int[size];

// 	for (int i = 0; i < size; i++)
// 	{
// 		cin >> arr[i];
// 		ht.insert(i, arr[i]);
// 	}

// 	ht.display();

// 	ht.search_key(2);
// 	ht.search_data(5);

// 	ht.remove(2);
// 	ht.display();
// 	return 0;
// }





// BST

// class node
// {
// public:
// 	node *left;
// 	node *right;
// 	int data;

// 	node(int data)
// 	{
// 		this->data = data;
// 		left = NULL;
// 		right = NULL;
// 	}

// 	node()
// 	{
// 		data = 0;
// 		left = NULL;
// 		right = NULL;
// 	}
// };

// class BST
// {
// public:
// 	node *root;
// 	node *temp;

// 	BST()
// 	{
// 		root = NULL;
// 	}

// 	void insert(int data)
// 	{
// 		node *newnode = new node(data);
// 		if (root == NULL)
// 		{
// 			root = newnode;
// 			return;
// 		}

// 		temp = root;
// 		while (temp != NULL)
// 		{
// 			if (data > temp->data)
// 			{
// 				if (temp->right == NULL)
// 				{
// 					temp->right = newnode;
// 					return;
// 				}
// 				temp = temp->right;
// 			}
// 			else if (data < temp->data)
// 			{
// 				if (temp->left == NULL)
// 				{
// 					temp->left = newnode;
// 					return;
// 				}
// 			}

// 			else
// 			{
// 				cout << "Duplicate data" << endl;
// 				return;
// 			}
// 		}
// 	}

// 	node *minvalue(node *root)
// 	{
// 		temp = root;

// 		while (temp->left != NULL)
// 		{
// 			temp = temp->left;
// 		}
// 		return temp;
// 	}

// 	void delete_node(node *del, int data)
// 	{
// 		if (del == NULL)
// 		{
// 			cout << "Node not found" << endl;
// 			return;
// 		}

// 		if (data < del->data)
// 		{
// 			delete_node(del->left, data);
// 		}
// 		else if (data > del->data)
// 		{
// 			delete_node(del->right, data);
// 		}
// 		else
// 		{
// 			if (del->left == NULL && del->right == NULL)
// 			{
// 				delete del;
// 				del = NULL;
// 				return;
// 			}
// 			else if(del->left == NULL)
// 			{
// 				node *temp = del;
// 				del = del->right;
// 				delete temp;
// 				return;
// 			}
// 			else if (del->right == NULL)
// 			{
// 				node *temp = del;
// 				del = del->left;
// 				delete temp;
// 				return;
// 			}
// 			else
// 			{
// 				node *temp = minvalue(del->right);
// 				del->data = temp->data;
// 				delete_node(del->right, temp->data);
// 			}
// 		}
// 	}

// 	void display(node *root)
// 	{
// 		if (root == NULL)
// 		{
// 			return;
// 		}
// 		display(root->left);
// 		cout << root->data << " ";
// 		display(root->right);
// 	}
// };

// int main()
// {
// 	BST tree;
// 	int size = 0;

// 	cin >> size;
// 	int *arr = new int[size];

// 	for (int i = 0; i < size; i++)
// 	{
// 		cin >> arr[i];
// 		tree.insert(arr[i]);
// 	}

// 	tree.display(tree.root);
// 	cout << endl;

// 	tree.delete_node(tree.root, 5);
// 	tree.display(tree.root);

// 	return 0;
// }



