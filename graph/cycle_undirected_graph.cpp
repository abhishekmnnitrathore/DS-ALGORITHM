/* recStack keeps track of all the nodes
 * and recStack[i] checks for nodes. if recStack[]
 * is true it means there is back edge from present
 * node "v" to current node "i". and finally dfs function
 * return "true".
 * recStack[] = false; This basically removes nodes from stack
 * which are not present in current dfs recursion.
 * example:
 * if dfs start from zero and goes to any node x all the
 * node will be in recursion stack but on coming back from x to y
 * all nodes from x to y will be remove from nodes and again from y
 * onward stack will be filled.
 */

#include<iostream>

using namespace std;
namespace {
#define E 4
#define V 4

bool visit[V] = { 0 };
int adj[V][V] = { 0 };

bool dfs(int v, int parent) {
	visit[v] = true;
	for (int i = 0; i < V; i++) {
		if (adj[v][i]) {
			if (!visit[i] && dfs(i, v)) {
				return true;
			} else if (parent != i) {
				return true;

			}
		}
	}
	return false;
}
}

int main_cycle_undirected1() {
	int answer = false;
	int V1[] = { 0, 0, /*1,*/ 2, 2/*, 3*/ };
	int V2[] = { 1, 2, /*2,*/ 0, 3/*, 3*/ };
	for (int i = 0; i < E; i++) {
		adj[V1[i]][V2[i]] = 1;
		adj[V2[i]][V1[i]] = 1;
	}
	for (int i = 0; i < V; i++) {
		if (!visit[i]) {
			answer = dfs(i, -1);
			if(answer) {
				break;
			}
		}
	}

	if(answer) {
		cout<<"cycle";
	}
	else {
		cout<<"No Cycle";
	}
	cout << endl;

	return 0;
}
