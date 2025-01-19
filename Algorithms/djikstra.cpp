#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <climits>
using namespace std;

class Graph {
public:
	int V;
	vector<vector<pair<int, int>>> adj;

	Graph(int V) {
		this->V = V;
		adj.resize(V);
	}

	void addEdge(int u, int v, int w) {
		adj[u].push_back(make_pair(v, w));

		adj[v].push_back(make_pair(u, w));
	}

	void djikstra(int source) {
		vector<int> dist(V, INT_MAX);
		vector<bool> visited(V, false);

		dist[source] = 0;

		set<pair<int, int>> minkey;
		minkey.insert({ 0, source });

		while (!minkey.empty()) {
			int u = minkey.begin()->second;
			minkey.erase(minkey.begin());
			visited[u] = true;

			for (const auto& neighbor : adj[u]) {
				int v = neighbor.first;
				int weight = neighbor.second;

				if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
					minkey.erase({ dist[v], v });

					dist[v] = dist[u] + weight;

					minkey.insert({ dist[v], v });
				}
			}
		}

		cout << "Vertex\tDistance from Source\n";
		for (int i = 0; i < V; ++i) {
			cout << i << "\t" << (dist[i] == INT_MAX ? -1 : dist[i]) << "\n";
		}

	}

};
int main() {
	int V = 5; 
	Graph g(V);

	g.addEdge(0, 1, 2);
	g.addEdge(0, 2, 4);
	g.addEdge(1, 2, 1);
	g.addEdge(1, 3, 7);
	g.addEdge(2, 4, 3);
	g.addEdge(3, 4, 2);

	int source = 0;
	cout << "Dijkstra's shortest paths from source " << source << ":\n";
	g.djikstra(source);
}
