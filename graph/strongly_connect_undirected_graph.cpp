/*
 * Connectivity in Graph:
 *
 * Strongly Connected meaning: if all node can be reached from all the nodes than it
 * is strongly connected.
 *
 * Undirected: if graph is not forest than it is always strongly connected. (Do dfs/bfs and check
 * that all nodes are visited or not for counting number of component apply dfs till all
 * nodes are visited and number of time dfs called ).
 *
 */

#include<iostream>

using namespace std;
namespace {
#define E 4
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

int main_undirected_strongly_connected() {
	int count = 0;
	int V1[] = { 1, 0, 2, 4 };
	int V2[] = { 0, 2, 1, 0 }; // Not connected
	/*
	 *int V1[] = { 1, 0, 2, 0, 3, 4 };
	 *int V2[] = { 0, 2, 1, 3, 4, 0 }; //Connected
	 *
	 **/

	for (int i = 0; i < E; i++) {
		adj[V1[i]][V2[i]] = 1;
		adj[V2[i]][V1[i]] = 1;
	}
	visit[0] = 1;
	dfs(0);
	for(int i=0;i<V;i++) {
		if(visit[i] == 1)
		count++;
	}
	if(count == V)
		cout<<" Connected";
	else
		cout<< "Not Connected";
	return 0;
}
