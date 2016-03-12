/*
 * Connectivity in Graph:
 *
 * Strongly Connected meaning: if all node can be reached from all the nodes than it
 * is strongly connected.
 *
 * Directed:
 *   1---->2----->3---->
 *   This is not strongly connected graph.
 *
 * For Directed graph:
 * 1. use "Floyd Warshall" (This is used to find minimum distance between
 *    all the nodes is any two nodes have INF distance it means graph is
 *    not connected)
 * 2. Transitive closure: reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
 *    complexity is same only but we uses "&&" in place of "+" and "||" in place of
 *    "min()" this operation will have set bit for all the places for which patch is present.
 * 3. Above both problem have time complexity of o(v3).
 * 4. Apply DFS for each node and check for count same as we did in undirected graph
 *    if for any of the node (visit_count != number of node) than graph is not strongly
 *    connected. complexity(O(V*(V+E))).
 * 5. We can also use "Kosaraju’s algorithm"
 *    Example:
 *    1. Pick any arbitrary vertex and apply dfs and check if all the vertex are visited.
 *    2. Transpose adj matrix and again apply dfs with same node and again check for visit
 *    count
 *    3. if both the condition are satisfied than Directed graph is strongly connected.
 *
 *    "Kosaraju’s algorithm":
 *    This algorithm also tells number of strongly connected components in one directed graph,
 *    if count is one than graph is strongly connected. complexity O(V+E). will do in next program.
 */

#include<iostream>
#include<limits.h>

using namespace std;

namespace flyod {

void floydWarshall() {
#define E 4
#define V 4
#define INF 50
	int dist[V][V] = { 0 };
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (i != j)
				dist[i][j] = INF;
		}
	}

	int V1[] = { 0, 0, 1, 2 };
	int V2[] = { 1, 3, 2, 3 };
	int W[] = { 5, 10, 3, 1 };

	for (int i = 0; i < E; i++) {
		dist[V1[i]][V2[i]] = W[i];
	}

	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			cout << dist[i][j] << "      ";
		}
		cout << endl;
	}

   // check for the dist[][] matrix, if all the value is
   // NON-INF it means graph is connected.
}
} // namespace flyod

int main_strongly_connected_directed() {
	flyod::floydWarshall();
	return 0;
}
