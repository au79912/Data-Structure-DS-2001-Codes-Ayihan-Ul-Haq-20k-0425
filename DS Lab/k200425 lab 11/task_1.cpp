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
		
		void remove(int key)
		{
			int hash_key = hash(key);
			hashtableentry *entry = table[hash_key];
			hashtableentry *prev = NULL;
			while (entry != NULL)
			{
				if (entry->key == key)
				{
					if (prev == NULL)
					{
						table[hash_key] = entry->next;
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
		void print()
		{
			for (int i = 0; i < size; i++)
			{
				hashtableentry *entry = table[i];
				while (entry != NULL)
				{
					cout << entry->key << " " << entry->value << endl;
					entry = entry->next;
				}
			}
		}
};

//driver function
int main()
{
	hashmaptable ht(10);
	ht.insert(1, 1);
	ht.insert(2, 2);
	ht.insert(3, 3);
	ht.insert(4, 4);
	ht.insert(5, 5);
	ht.insert(6, 6);
	ht.insert(7, 7);
	ht.insert(8, 8);
	ht.insert(9, 9);
	ht.insert(10, 10);
	cout << ht.search(3) << endl;
	cout << ht.search(4) << endl;
	ht.print();
	ht.remove(1);
	ht.print();
	return 0;
}