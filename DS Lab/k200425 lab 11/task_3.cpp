#include <iostream>

using namespace std;

class hashtableentry
{
public:
	int key;
	int value;
	hashtableentry *next;

	hashtableentry(int k, int v)
	{
		key = k;
		value = v;
		next = NULL;
	}
};

class hashmaptable
{
public:
	hashtableentry **table;
	int size;

	hashmaptable(int s)
	{
		size = s;
		table = new hashtableentry*[size];
		for (int i = 0; i < size; i++)
		{
			table[i] = NULL;
		}
	}

	hashmaptable()
	{
		size = 0;
		table = NULL;
	}

	int hash(int key)
	{
		return key % size;
	}

	void insert(int key, int value)
	{
		int hash_key = hash(key);
		hashtableentry *entry = new hashtableentry(key, value);
		entry->next = table[hash_key];
		table[hash_key] = entry;
	}

	int search(int key)
	{
		int hash_key = hash(key);
		hashtableentry *entry = table[hash_key];
		while (entry != NULL)
		{
			if (entry->key == key)
			{
				return entry->value;
			}
			entry = entry->next;
		}
		return -1;
	}
};

class contactbook
{
public:
	hashmaptable *hashtable;
	int size;

	contactbook(int s)
	{
		size = s;
		hashtable = new hashmaptable(size);
	}

	contactbook()
	{
		size = 0;
		hashtable = NULL;
	}

	bool isEmpty()
	{
		return (size == 0);
	}

	int getSize()
	{
		return size;
	}


	void deleteContact(int key)
	{
		int hash_key = hashtable->hash(key);
		hashtableentry *entry = hashtable->table[hash_key];
		hashtableentry *prev = NULL;
		while (entry != NULL)
		{
			if (entry->key == key)
			{
				if (prev == NULL)
				{
					hashtable->table[hash_key] = entry->next;
				}
				else
				{
					prev->next = entry->next;
				}
				delete entry;
				return;
			}
			prev = entry;
			entry = entry->next;
		}
	}

	void insert(int key, int value)
	{
		hashtable->insert(key, value);
	}

	int search(int key)
	{
		return hashtable->search(key);
	}
};

//driver function
int main()
{
	contactbook cb;

	cb.insert(1, 1);
	cb.insert(2, 2);
	cb.insert(3, 3);
	cb.insert(4, 4);
	cb.insert(5, 5);
	cb.insert(6, 6);
	cb.insert(7, 7);
	cb.insert(8, 8);
	cb.insert(9, 9);

	cout << cb.search(3) << endl;
	cout << cb.search(10) << endl;

	cb.deleteContact(5);
	cb.deleteContact(10);

	cout << cb.search(5) << endl;
	cout << cb.search(10) << endl;

	return 0;
}