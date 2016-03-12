/*
 * Hamiltonian Cycle: Traverse each node once only
 *to complete cycle in graph.
 *
 * check for that row in the adj matrix
 * in which no new path available to traverse
 * so return false once we got row in which we have visited
 * Previously and no new patch is there.
 */

#include<iostream>

using namespace std;
namespace {
#define E /*6*/ 7
#define V 5

int index = 0;
int visit[V] = { 0 };
int adj[V][V] = { 0 };
int path[V + 1];

bool dfs(int v) {
	path[index++] = v;
	for (int i = 0; i < V; i++) {
		if (adj[v][i] == 1 && !visit[i]) {
			visit[i] = 1;
			if (dfs(i))
				return true;
			else
				return false;
		}
	}
	return false;
}
}

int main_hamilton() {
	int V1[] = { 0, 0, 1, 1, 1, 2 , 3};
	int V2[] = { 1, 3, 2, 3, 4, 4 , 4 };
	int start, ans = 0;
	for (int i = 0; i < E; i++) {
		adj[V1[i]][V2[i]] = 1;
		adj[V2[i]][V1[i]] = 1;
	}
	start = 1;
	visit[start] = 1;
	for (int i = 0; i <= V; i++) {
		path[i] = -1;
	}
	dfs(start);
	path[V] = start;
	for (int i = 0; i <= V; i++) {
		if (path[i] == -1) {
			ans = 1;
		}
	}
	if (ans == 0) {
		for (int i = 0; i <= V; i++) {
			cout << " " << path[i];
		}
	} else {
		cout << "doesn't exist";
	}
return 0;
}
