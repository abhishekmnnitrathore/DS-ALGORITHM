/*  DFS can be used for both directed and undirected graphs
 * Application: for undirected graphs this can be used for checking
 * whether graph is strongly(If we can traverse from any one node to
 * any another node) connected or not. This approach does not work
 * for directed graph.
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

int main_dfs() {
	int V1[] = { 1, 0, 2, 0, 3, 4 };
	int V2[] = { 0, 2, 1, 3, 4, 0 };
	for (int i = 0; i < E; i++) {
		adj[V1[i]][V2[i]] = 1;
		//adj[V2[i]][V1[i]] = 1;
	}
	/*for(int i=0; i<V;i++) {
	 for(int j=0; j<V; j++) {
	 cout<<adj[i][j]<<" ";
	 }
	 cout<<endl;
	 }*/
	visit[0] = 1;
	dfs(0);
	return 0;
}
