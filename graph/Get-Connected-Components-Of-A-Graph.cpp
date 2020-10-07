#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph
{
	int V;
	vector<pair<int, int>> *l;

public:
	Graph(int V)
	{
		this->V = V;
		l = new vector<pair<int, int>>[V];
	}
	void addEdge(int x, int y, int z)
	{
		l[x].push_back(make_pair(y, z));
		l[y].push_back(make_pair(x, z));
	}
	void printAdjList()
	{
		for (int i = 0; i < V; i++)
		{
			cout << "Vertex " << i << "->";
			for (auto nbr : l[i])
			{
				cout << nbr.first << " " << nbr.second << ",";
			}

			cout << '\n';
		}
	}
	void isconnected(int source, bool visited[], vector<int> &connections);
};
void Graph::isconnected(int source, bool visited[], vector<int> &connections)
{
	connections.push_back(source);
	visited[source] = true;

	for (auto nbr : l[source])
	{
		if (!visited[nbr.first])
			isconnected(nbr.first, visited, connections);
	}
}
int main()
{
	int v;
	cin >> v;
	Graph G(v);
	int e;
	cin >> e;
	int s, d, wt;
	for (int i = 1; i <= e; i++)
	{
		cin >> s >> d >> wt;
		G.addEdge(s, d, wt);
	}
	bool *visited = new bool[v];
	for (int i = 0; i < v; i++)
	{
		visited[i] = false;
	}
	vector<vector<int>> comp;
	for (int i = 0; i < v; i++)
	{
		if (!visited[i])
		{
			vector<int> connections;
			G.isconnected(i, visited, connections);
			comp.push_back(connections);
		}
	}
	vector<vector<int>>::iterator itr;

	cout << "[";
	for (int i = 0; i < comp.size() - 1; i++)
	{
		cout << "[";
		for (int j = 0; j < comp[i].size() - 1; j++)
		{
			cout << comp[i][j] << ", ";
		}
		cout << comp[i][comp[i].size() - 1] << "], ";
	}
	cout << "[";
	for (int j = 0; j < comp[comp.size() - 1].size() - 1; j++)
	{
		cout << comp[comp.size() - 1][j] << ", ";
	}
	cout << comp[comp.size() - 1][comp[comp.size()-1].size() - 1] << "]";
	cout << "]";

	return 0;
}
