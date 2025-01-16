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

		adj[v].push_back(make_pair(v, w));
	}

	vector<int> prims(Graph& graph, int startV) {
		vector<int> parent(V, -1);
		vector<int> key(V, INT_MAX);
		vector<bool>inMST(V, false);

		key[startV] = 0;

		set<pair<int, int>> minkey;
		minkey.insert({ 0, startV });

		while (!minkey.empty()) {
			int u = minkey.begin()->second;
			minkey.erase(minkey.begin());
			inMST[u] = true;

			for (const pair<int, int>& neighbors : adj[u]) {
				int v = neighbors.first;
				int weight = neighbors.second;

				if (!inMST[v] && weight < key[v]) {
					minkey.erase({ key[v], v });
					key[v] = weight;
					parent[v] = u;

					minkey.insert({ key[v], v });
				}
			}

		}
		return parent;
	}

};

int main() {
	Graph g(5);

	g.addEdge(0, 1, 2);
	g.addEdge(0, 3, 6);
	g.addEdge(1, 2, 3);
	g.addEdge(1, 3, 8);
	g.addEdge(1, 4, 5);
	g.addEdge(2, 4, 7);
	g.addEdge(3, 4, 9);

	vector<int> mst = g.prims(g, 0);

	cout << "Edges in the Minimum Spanning Tree (MST):\n";
	for (int i = 1; i < mst.size(); ++i) {
		cout << "Vertex " << i << " is connected to vertex " << mst[i] << " with weight ";
		for (const auto& neighbor : g.adj[i]) {
			if (neighbor.first == mst[i]) {
				cout << neighbor.second << endl;
				break;
			}
		}
	}
}


//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <set>
//#include <climits> // For INT_MAX
//using namespace std;
//
//class Graph {
//public:
//    int V;
//    vector<vector<pair<int, int>>> adj;
//
//    Graph(int V) {
//        this->V = V;
//        adj.resize(V);
//    }
//
//    void addEdge(int u, int v, int w) {
//        adj[u].push_back(make_pair(v, w));
//        adj[v].push_back(make_pair(u, w));  // Corrected from adj[v].push_back(make_pair(v, w));
//    }
//
//    vector<int> prims(Graph& graph, int startV) {
//        vector<int> parent(V, -1);
//        vector<int> key(V, INT_MAX);
//        vector<bool> inMST(V, false);
//
//        key[startV] = 0;
//
//        set<pair<int, int>> minkey;
//        minkey.insert({ 0, startV });
//
//        while (!minkey.empty()) {
//            int u = minkey.begin()->second;
//            minkey.erase(minkey.begin());
//            inMST[u] = true;
//
//            for (const pair<int, int>& neighbors : adj[u]) {
//                int v = neighbors.first;
//                int weight = neighbors.second;
//
//                if (!inMST[v] && weight < key[v]) {
//                    minkey.erase({ key[v], v });
//                    key[v] = weight;
//                    parent[v] = u;
//
//                    minkey.insert({ key[v], v });
//                }
//            }
//        }
//        return parent;
//    }
//};
//
//int main() {
//    // Create a graph with 5 vertices
//    Graph g(5);
//
//    // Add edges to the graph (u, v, weight)
//    g.addEdge(0, 1, 2);
//    g.addEdge(0, 3, 6);
//    g.addEdge(1, 2, 3);
//    g.addEdge(1, 3, 8);
//    g.addEdge(1, 4, 5);
//    g.addEdge(2, 4, 7);
//    g.addEdge(3, 4, 9);
//
//    // Run Prim's algorithm starting from vertex 0
//    vector<int> mst = g.prims(g, 0);
//
//    // Print the parent array to show the MST
//    cout << "Edges in the Minimum Spanning Tree (MST):\n";
//    for (int i = 1; i < mst.size(); ++i) {
//        cout << "Vertex " << i << " is connected to vertex " << mst[i] << " with weight ";
//        for (const auto& neighbor : g.adj[i]) {
//            if (neighbor.first == mst[i]) {
//                cout << neighbor.second << endl;
//                break;
//            }
//        }
//    }
//
//    return 0;
//}
