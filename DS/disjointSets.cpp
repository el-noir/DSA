#include <iostream>
#include <vector>
using namespace std;

void makeSet(vector<int>& parent, vector<int>& rank, int n) {
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
}

int findParent(vector<int> &parent, int node ){
	if (parent[node] == node) {
		return node;
	}
	return parent[node] =findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector <int> &parent, vector<int> &rank) {
	u = findParent(parent, u);
	v = findParent(parent, v);

	if (rank[u] < rank[v]) {
		parent[u] = v;
	}
	else if(rank[v]<rank[u]) {
		parent[v] = u;
	}
	else {
		parent[u] = v;
		rank[v]++;
	}
}

int main() {
	int n=7;
	vector<int> parent(n);

	vector<int> rank(n);


	makeSet(parent, rank, n);

	unionSet(3, 6, parent, rank);
	unionSet(1, 3, parent, rank);
	unionSet(4, 5, parent, rank);

	for (int i = 0; i < n; i++) {
		cout << "Parent of " << i << ": " << findParent(parent, i) << endl;
	}

	return 0;



	
}