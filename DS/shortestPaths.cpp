//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <list>
//#include <queue>
//#include <algorithm> // For reverse
//
//using namespace std;
//
//class Graph {
//private:
//    unordered_map<int, list<int>> adj; // Use list for undirected graph
//    int vertex;
//
//public:
//    Graph(int vertex) {
//        this->vertex = vertex;
//    }
//
//    void addEdge(int u, int v) {
//        adj[u].push_back(v);
//        adj[v].push_back(u); // Assuming undirected graph
//    }
//
//    void print() {
//        // Print all vertices and their adjacency lists
//        for (int i = 0; i < vertex; i++) {
//            cout << i << " -> ";
//            if (adj.find(i) != adj.end()) {
//                for (auto j : adj[i]) {
//                    cout << j << " ";
//                }
//            }
//            cout << endl;
//        }
//    }
//
//    vector<int> shortestPath(int s, int t) {
//        unordered_map<int, bool> visited;
//        unordered_map<int, int> parent;
//        queue<int> q;
//
//        // Initialize BFS
//        q.push(s);
//        visited[s] = true;
//        parent[s] = -1;
//
//        // Perform BFS
//        while (!q.empty()) {
//            int front = q.front();
//            q.pop();
//
//            for (auto neighbor : adj[front]) {
//                if (!visited[neighbor]) {
//                    visited[neighbor] = true;
//                    parent[neighbor] = front;
//                    q.push(neighbor);
//                }
//            }
//        }
//
//        // Prepare shortest path
//        vector<int> ans;
//        int currentNode = t;
//
//        if (!visited[t]) {
//            cout << "No path exists between " << s << " and " << t << "." << endl;
//            return ans; // Empty vector
//        }
//
//        while (currentNode != -1) {
//            ans.push_back(currentNode);
//            currentNode = parent[currentNode];
//        }
//
//        reverse(ans.begin(), ans.end());
//        return ans;
//    }
//
//
//};
//
//int main() {
//    Graph g(6);
//
//    // Add edges
//    g.addEdge(0, 1);
//    g.addEdge(0, 4);
//    g.addEdge(1, 2);
//    g.addEdge(1, 3);
//    g.addEdge(3, 5);
//    g.addEdge(4, 5);
//
//    // Print adjacency list
//    cout << "Graph adjacency list:" << endl;
//    g.print();
//
//    // Find shortest path
//    int start = 0, target = 5;
//    cout << "\nShortest path from " << start << " to " << target << ":" << endl;
//    vector<int> path = g.shortestPath(start, target);
//
//    if (!path.empty()) {
//        for (int node : path) {
//            cout << node << " ";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}



//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//struct Edge {
//	int to, weight;
//};
//
//void dijkstra(int source, vector<vector<Edge>>&graph) {
//	int n = graph.size();
//
//	vector<int> dist(n, INT_MAX);
//	dist[source] = 0;
//
//	priority_queue<pair<int, int>, vector<pair<int, int>>,greater< >> pq;
//
//	pq.push({ 0, source});
//
//	while (!pq.empty()) {
//		int currDis = pq.top().first;
//		int currVertex = pq.top().second;
//
//		pq.pop();
//
//		if (currDis > dist[currVertex]) continue;
//
//		for (const Edge& edge : graph[currVertex]) {
//			int neighbor = edge.to;
//			int weight = edge.weight;
//
//			if (dist[currVertex] + weight < dist[neighbor]) {
//				dist[neighbor] = dist[currVertex] + weight;
//
//				pq.push({ dist[neighbor], neighbor });
//			}
//		}
//      
//		cout << "Vertex  Distance from Source \n ";
//		for (int i = 0; i < n; i++) {
//			cout << i << "\t" << dist[i] << "\n";
//		}
//	}
//}
//
//
//int main() {
//	
//	int vertices, edges;
//
//	cout << "Enter the number of vertices and edges : ";
//	cin >> vertices >> edges;
//
//	vector<vector<Edge>> graph(vertices);
//
//	cout << "Enter the edges in the format: u v w (0-indexed) \n";
//	for (int i = 0; i < edges; i++) {
//		int u, v, w;
//
//		cin >> u >> v >> w;
//		graph[u].push_back({ v, w });
//		graph[v].push_back({ u, w });
//	}
//
//	int source;
//	cout << "Enter the source vertex : ";
//	cin >> source;
//
//	dijkstra(source, graph);
//
//}


#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Structure to represent a weighted edge
struct Edge {
    int to, weight;
};

// Function to find the vertex with the smallest distance
int findMinVertex(const vector<int>& dist, const vector<bool>& visited) {
    int minVertex = -1, minDist = INT_MAX;
    for (int i = 0; i < dist.size(); ++i) {
        if (!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            minVertex = i;
        }
    }
    return minVertex;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int source, const vector<vector<Edge>>& graph) {
    int n = graph.size(); // Number of vertices
    vector<int> dist(n, INT_MAX); // Distance from source to each vertex
    vector<bool> visited(n, false); // Track visited vertices
    dist[source] = 0;

    for (int i = 0; i < n - 1; ++i) { // Repeat n-1 times for all vertices
        int u = findMinVertex(dist, visited);
        if (u == -1) break; // All reachable vertices processed
        visited[u] = true;

        // Explore neighbors
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;
            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Print shortest distances
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < n; ++i) {
        cout << i << "\t" << (dist[i] == INT_MAX ? -1 : dist[i]) << "\n";
    }
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    if (vertices <= 0) {
        cerr << "Error: Number of vertices must be greater than 0.\n";
        return 1;
    }
    if (edges < 0) {
        cerr << "Error: Number of edges cannot be negative.\n";
        return 1;
    }

    vector<vector<Edge>> graph(vertices);

    cout << "Enter the edges in the format: u v w (0-indexed)\n";
    for (int i = 0; i < edges; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        // Input validation
        if (u < 0 || u >= vertices || v < 0 || v >= vertices) {
            cerr << "Error: Edge vertices (" << u << ", " << v
                << ") are out of range. Valid range is [0, " << vertices - 1 << "].\n";
            return 1;
        }

        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w }); // For undirected graphs; remove for directed
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    // Source validation
    if (source < 0 || source >= vertices) {
        cerr << "Error: Source vertex " << source
            << " is out of range. Valid range is [0, " << vertices - 1 << "].\n";
        return 1;
    }

    dijkstra(source, graph);

    return 0;
}

