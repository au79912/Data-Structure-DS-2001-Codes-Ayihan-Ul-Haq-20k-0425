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

	//floyd warshall algorithm
	void floyd_warshall()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				for (int k = 0; k < size; k++)
				{
					if (adj_cost[j][k] > adj_cost[j][i] + adj_cost[i][k])
					{
						adj_cost[j][k] = adj_cost[j][i] + adj_cost[i][k];
					}
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
	g.floyd_warshall();
	for (int i = 0; i < n; i++)
	{
		min_cost += g.adj_cost[0][i];
	}
	cout << min_cost;
	return 0;
}
