/*
 * 1. Sort all the edges in non-decreasing order of their weight.
 * 2. Pick the smallest edge. Check if it forms a cycle with the spanning tree
 *    formed so far. If cycle is not formed, include this edge. Else, discard it.
 * 3. Repeat step#2 until there are (V-1) edges in the spanning tree.
 */

#include<iostream>

using namespace std;
namespace {
#define E 6
#define V 5

int visit[V] = { 0 };
int adj[V][V] = { 0 };

void dfs(int v) {
	cout << v << " ";
	for (int i = 0; i < V; i++) {
		if (adj[v][i] == 1 && !visit[i]) {
			visit[i] = 1;
			dfs(i);
		}
	}
}
}

int main_kruskal() {
	int V1[] = { 1, 0, 2, 0, 3, 4 };
	int V2[] = { 0, 2, 1, 3, 4, 0 };
	for (int i = 0; i < E; i++) {
		adj[V1[i]][V2[i]] = 1;
	}
	visit[0] = 1;
	dfs(0);
	return 0;
}
