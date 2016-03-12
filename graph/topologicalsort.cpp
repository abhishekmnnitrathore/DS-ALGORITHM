/*
 * Topological shorting is only applicable for DAG(Directed Acyclic graph)
 *       5      4
 *      / \    / \
 *     /   \  /   \
 *    >2   >0<     >1
 *     \        />
 *      \      /
 *       \ > 3
 *   Sort: 5 4 2 3 1 0   /  4 5 2 3 1 0
 */

#include<iostream>
using namespace std;

namespace {
#define E 6
#define V 6
int adj[V][V] = { 0 };
int visited[V] = { 0 };
int stack[V];
int top = -1;
void push(int node) {
	top = top + 1;
	stack[top] = node;
}

int pop() {
	int x = stack[top];
	top = top - 1;
	return x;
}
void dfs(int v) {
	visited[v] = 1;
	for (int i = 0; i < V; i++) {
		if (adj[v][i] == 1 && !visited[i]) {
			//visited[i] = 1;
			dfs(i);
		}
	}
	push(v);
}
}
int main_topological_sort() {

	int V1[] = { 5, 5, 4, 4, 2, 3 };
	int V2[] = { 2, 0, 0, 1, 3, 1 };

	for (int i = 0; i < E; i++) {
		adj[V1[i]][V2[i]] = 1;
	}

	for (int i = 0; i < V; i++) {
		if (!visited[i])
			dfs(i);
	}
	for (int i = 0; i < V; i++) {
		cout << pop() << " ";
	}
	return 0;
}
