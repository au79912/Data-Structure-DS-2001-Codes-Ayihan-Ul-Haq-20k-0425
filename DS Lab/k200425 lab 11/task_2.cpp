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

		int multiplication_hash(int key)
		{
			return floor (size * (key * .5));
		}

		int mid_square_hash(int key)
		{
			return floor (sqrt(key));
		}

		int folding_hash(int value1, int value2)
		{
			return value1 + value2;
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

int main(int argc, char const *argv[])
{
	
	return 0;
}