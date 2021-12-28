#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class graph
{
public:
	bool **adj;
	int V;

	graph(int V)
	{
		this->V = V;
		adj = new bool *[V];
		for (int i = 0; i < V; i++)
		{
			adj[i] = new bool[V];
			for (int j = 0; j < V; j++)
			{
				adj[i][j] = false;
			}
		}
	}

	void add_edge(int v, int w)
	{
		adj[v][w] = true;
		adj[w][v] = true;
	}

	void printGraph()
	{
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				cout << adj[i][j] << " ";
			}
			cout << endl;
		}
	}

	void BFS(int a)
	{
		bool vis[V] = {false};
		queue<int> q;

		q.push(a);
		vis[a] = true;

		while (!q.empty())
		{
			int curr = q.front();
			q.pop();
			cout << curr << " ";

			for (int i = 0; i < V; i++)
			{
				if (adj[curr][i] && !vis[i])
				{
					q.push(i);
					vis[i] = true;
				}
			}
		}
	}

	void DFS(int a)
	{
		bool vis[V] = {false};
		stack<int> s;

		s.push(a);
		vis[a] = true;

		while (!s.empty())
		{
			int curr = s.top();
			s.pop();
			cout << curr << " ";

			for (int i = 0; i < V; i++)
			{
				if (adj[curr][i] && !vis[i])
				{
					s.push(i);
					vis[i] = true;
				}
			}
		}
	}
};

int main(int argc, char const *argv[])
{
	graph g(5);
	g.add_edge(0, 1);
	g.add_edge(1, 3);
	g.add_edge(0, 2);
	g.add_edge(1, 4);
	g.add_edge(3, 4);
	g.add_edge(2, 3);

	g.printGraph();

	cout << "BFS: ";
	g.BFS(0);
	cout << endl;

	cout << "DFS: ";
	g.DFS(0);
	cout << endl;

	return 0;
}