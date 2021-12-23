#include <iostream>
#include <vector>

using namespace std;

class graph
{
	public:
	vector<int> *adj;
	vector<int> *adj_cost;
	int size;

	graph(int s)
	{
		size = s;
		adj = new vector<int>[size];
		adj_cost = new vector<int>[size];
	}

	void add_edge(int u, int v, int cost)
	{
		adj[u].push_back(v);
		adj_cost[u].push_back(cost);
	}

	//dijkstra algorithm
	void dijkstra(int src)
	{
		vector<int> key(size, INT_MAX);
		vector<bool> mstSet(size, false);
		key[src] = 0;
		vector<int> parent(size, -1);
		vector<int> min_key(size, INT_MAX);
		vector<int> min_key_index(size, -1);
		for (int i = 0; i < size; i++)
		{
			int min = INT_MAX;
			for (int j = 0; j < size; j++)
			{
				if (mstSet[j] == false && key[j] < min)
				{
					min = key[j];
					min_key_index[i] = j;
				}
			}
			mstSet[min_key_index[i]] = true;
			for (int j = 0; j < adj[min_key_index[i]].size(); j++)
			{
				if (mstSet[adj[min_key_index[i]][j]] == false && adj_cost[min_key_index[i]][j] < key[adj[min_key_index[i]][j]])
				{
					parent[adj[min_key_index[i]][j]] = min_key_index[i];
					key[adj[min_key_index[i]][j]] = adj_cost[min_key_index[i]][j];
				}
			}
		}
	}
};

int main()
{
	int n, m, u, v, cost, min_cost = 0;
	cin >> n >> m;
	graph g(n);
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> cost;
		g.add_edge(u, v, cost);
	}
	g.dijkstra(0);
	for (int i = 0; i < n; i++)
	{
		min_cost += g.adj_cost[0][i];
	}
	cout << min_cost;
	return 0;
}
