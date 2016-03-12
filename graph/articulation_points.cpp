/*
 *  Vertex which divide graph in two or more parts.
 *  1. Simple approach:
 *     Remove all vertex one by one and check graph is connected or not.
 *  2. Algorithm used on the basic concept that, if there is an back edge between
       the node in that case removing particular node might no break graph into two part.
       so keep on updating low array which basically will tell which is the point which can make 
       back edge.
 *
 */

#include<iostream>

using namespace std;
#define V 5
#define E 5

void dfs(int v, int graph[V][V], int disc[], int low[], int parent[], int arc[],
		int visited[]) {
	static int time = 0;
	int child = 0;
	visited[v] = 1;
	disc[v] = ++time;
	low[v] = ++time;
	for (int i = 0; i < V; i++) {
		if (graph[v][i]) {
			if (!visited[i]) {
				child++;
				parent[i] = v;
				dfs(i, graph, disc, low, parent, arc, visited);
				low[v] = min(low[v], low[i]);
				if (parent[v] == -1 && child > 1)
					arc[v] = 1;
				if (parent[v] != -1 && disc[v] <= low[i])
					arc[v] = 1;
			} else if (parent[v] != i) {
				low[v] = min(low[v], disc[i]);
			}
		}
	}

}

int mainArticulation() {
	int V1[] = { 1, 0, 2, 0, 3 };
	int V2[] = { 0, 2, 1, 3, 4 };
	int graph[V][V], disc[V], low[V], parent[V], arc[V], visited[V];
	for (int i = 0; i < V; i++) {
		parent[i] = -1;
		disc[i] = 0;
		low[i] = 0;
		arc[i] = 0;
		visited[i] = 0;
	}
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			graph[i][j] = 0;
		}
	}
	for (int i = 0; i < E; i++) {
		graph[V1[i]][V2[i]] = 1;
		graph[V2[i]][V1[i]] = 1;
	}
	for (int i = 0; i < V; i++) {
		if (!visited[i]) {
			dfs(i, graph, disc, low, parent, arc, visited);
		}
	}
	for (int i = 0; i < V; i++) {
		if (arc[i]) {
			cout << i << " ";
		}
	}
	return 0;
}
