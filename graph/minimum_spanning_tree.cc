/*
 * Greedy Algorithm: At each point choose best, this approach cann't be applied
 * every where, so Dynamic programming is another solution for that.
 * Example:
 * Fractional Knapsack problem (See this) can be solved using Greedy,
 * but 0-1 Knapsack cannot be solved using Greedy
 *
 * Below approach used Greedy Algorithm:
 * 1) Kruskal’s Minimum Spanning Tree (MST)
 * 2) Prim’s Minimum Spanning Tree
 * 3) Dijkstra’s Shortest Path
 * 4) Huffman Coding
 *
 * What is Minimum Spanning Tree?
 * Given a connected and undirected graph, a spanning tree of that graph is a
 * subgraph that is a tree and connects all the vertices together.
 * A single graph can have many different spanning trees.
 * A minimum spanning tree (MST) or minimum weight spanning tree for a weighted,
 * connected and undirected graph is a spanning tree with weight less than or equal
 * to the weight of every other spanning tree. The weight of a spanning tree is the
 * sum of weights given to each edge of the spanning tree.

How many edges does a minimum spanning tree has?
A minimum spanning tree has (V – 1) edges where V is the number of vertices in the given graph.
 */

#include<iostream>

using namespace std;

namespace {

int isCycleUtils(int **adj, int *visited, int parent, int v, int size) {
	visited[v] = 1;
	for (int i = 0; i < size; i++) {
		if (adj[v][i]) {
			if (!visited[i]) {
				if (isCycleUtils(adj, visited, v, i, size))
					return true;
			} else if (i != parent) {
				return true;
			}
		}
	}
	return false;
}

int isCycle(int **adj, int *visited, int size) {
	for (int i = 0; i < size; i++) {
		if (!visited[i]) {
			if (isCycleUtils(adj, visited, -1, i, size))
				return true;
		}
	}
	return false;
}

void sortEdge(int *v1, int *v2, int *w, int E) {
	for (int i = 0; i < E; i++) {
		for (int j = i + 1; j < E; j++) {
			if (w[j] < w[i]) {
				w[i] = w[j] + w[i] - (w[j] = w[i]);
				v1[i] = v1[j] + v1[i] - (v1[j] = v1[i]);
				v2[i] = v2[j] + v2[i] - (v2[j] = v2[i]);
			}
		}
	}
}

void spanningTree(int *v1, int *v2, int *w, int **adj, int *visited, int V,
		int E, int start) {
	int count = 0;
	sortEdge(v1, v2, w, E);
	for (int i = 0; i < E; i++) {
		if (adj[v1[i] - 1][v2[i] - 1] == 0 && adj[v2[i] - 1][v1[i] - 1] == 0) {
			adj[v1[i] - 1][v2[i] - 1] = w[i];
			adj[v2[i] - 1][v1[i] - 1] = w[i];
			count++;
			if (isCycle(adj, visited, V)) {
				count--;
				adj[v1[i] - 1][v2[i] - 1] = 0;
				adj[v2[i] - 1][v1[i] - 1] = 0;
			}
			for (int i = 0; i < V; i++) {
				visited[i] = 0;
			}
		}
	}
}

}

int main_minimum_spanning_tree() {
	int V, E, start, ans =0;
	cin >> V >> E;
	int *v1 = new int[E];
	int *v2 = new int[E];
	int *w = new int[E];
	int *visited = new int[V];
	for (int i = 0; i < V; i++) {
		visited[i] = 0;
	}
	for (int i = 0; i < E; i++) {
		cin >> v1[i] >> v2[i] >> w[i];
	}
	cin >> start;
	int **adj = new int*[V];
	for (int i = 0; i < V; i++) {
		adj[i] = new int[V];
	}
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			adj[i][j] = 0;
		}
	}
	spanningTree(v1, v2, w, adj, visited, V, E, start);
	for(int i=0;i<V;i++) {
		for(int j=0;j<V;j++) {
			ans += adj[i][j];
		}
	}
	for(int i=0;i<V;i++) {
		for(int j=0;j<V;j++) {
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<ans/2;
	return 0;
}
