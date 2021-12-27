#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class node
{
public:
	int data;
	node *next;

	node()
	{
		data = 0;
		next = NULL;
	}

	node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

class graph
{
public:
	node *head;
	node *temp;

	graph()
	{
		head = NULL;
	}

	void insert(int data)
	{
		node *newnode = new node(data);

		if (head == NULL)
		{
			head = newnode;
			return;
		}

		temp = head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}

	void display()
	{
		temp = head;

		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void sort()
	{
		node *prev = NULL;
		node *curr = head;
		node *next = NULL;

		while (curr != NULL)
		{
			next = curr->next;

			if (prev == NULL)
			{
				prev = curr;
				curr = next;
				continue;
			}

			if (curr->data < prev->data)
			{
				if (prev == head)
				{
					head = curr;
				}
				else
				{
					prev->next = curr->next;
				}

				curr->next = head;
				head = curr;
			}
			else
			{
				prev = curr;
			}

			curr = next;
		}
	}
};

void sort_arr(graph arr[])
{
	for (int i = 0; i < 5; i++)
	{
		arr[i].sort();
	}
}

void add_edge(int a, int b, graph arr[])
{
	arr[a].insert(b);
	arr[b].insert(a);
}

void display_list(graph arr[])
{
	for (int i = 0; i < 5; i++)
	{
		cout<<i<<" | ";
		arr[i].display();
		cout << endl;
	}
}

void BFS(int a, graph arr[])
{
	bool vis[5]={false};
	queue<int> q;

	q.push(a);
	vis[a]=true;

	while(!q.empty())
	{
		int f = q.front();
		q.pop();
		cout<<f<<" ";

		node *temp = new node();
		temp = arr[f].head;

		while(temp !=NULL)
		{
			if (vis[temp->data]==false)
			{
				vis[temp->data]=true;
				q.push(temp->data);
			}
			temp = temp->next;
		}
	}
}

int main(int argc, char const *argv[])
{
	graph g[5];//5 verticies

	add_edge(0,1, g);
	add_edge(1,3,g);
	add_edge(0,2,g);
	add_edge(1,4,g);
	add_edge(3,4,g);
	add_edge(2,3,g);

	sort_arr(g);
	display_list(g);

	BFS(0,g);

	return 0;
}