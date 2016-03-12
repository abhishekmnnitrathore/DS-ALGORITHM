/*
 * Strongly Connected meaning: if all node can be reached from all the nodes than it
 * is strongly connected.
 *
 * Undirected graph: count how many times dfs got called till all nodes are visited. will
 * give you strongly connected component.
 *
 * Directed: Apply Kosaraju’s algorithm.
 * steps:
 * 1. apply topological sort.
 * 2. do transpose of adjacency matrix.
 * 3. call dfs with top node of stack till stack not empty.
 *
 */

#include<iostream>

using namespace std;

namespace {
int N, E;
int graph[1000][10000];
int V1[1000], V2[1000], visited[1000];
int stack[1000];
int top = -1;

void push(int v) {
	top = top + 1;
	stack[top] = v;
}

int pop() {
	int temp = stack[top];
	top = top - 1;
	return temp;
}

void fillstack(int v) {
	visited[v] = 1;
	for (int i = 0; i < N; i++) {
		if (graph[v][i] && !visited[i]) {
			fillstack(i);
		}
	}
	push(v);
}

void dfs(int v) {
	cout << v << " ";
	visited[v] = 1;
	for (int i = 0; i < N; i++) {
		if (graph[v][i] && !visited[i]) {
			dfs(i);
		}
	}
}
}

int main() {
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		cin >> V1[i] >> V2[i];
	}
	for (int i = 0; i < E; i++) {
		graph[V1[i]][V2[i]] = 1;
	}
	for (int i = 0; i < N; i++) {
		visited[i] = 0;
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			fillstack(i);
		}
	}
	for (int i = 0; i < N; i++) {
		visited[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			graph[i][j] = graph[j][i];
		}
	}
	while (top != -1) {
		int temp = pop();
		if (!visited[temp]) {
			dfs(temp);
			cout << endl;
		}
	}
	return 0;
}
