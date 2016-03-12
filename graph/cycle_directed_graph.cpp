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
 *
 */

#include<iostream>

using namespace std;
namespace {
#define E 4
#define V 4

bool visit[V] = { 0 };
int adj[V][V] = { 0 };
bool recStack[V] = { 0 };

bool dfs(int v) {
	visit[v] = true;
	recStack[v] = true;
	for (int i = 0; i < V; i++) {
		if (adj[v][i]) {
			if (!visit[i] && dfs(i)) {
				return true;
			} else if (recStack[i]) {
				return true;

			}
		}
	}
	recStack[v] = false;
	return false;
}
}

int main_cycle_directed() {
	int answer = false;
	int V1[] = { 0, 0, /*1,*/ 2, 2/*, 3*/ };
	int V2[] = { 1, 2, /*2,*/ 0, 3/*, 3*/ };
	for (int i = 0; i < E; i++) {
		adj[V1[i]][V2[i]] = 1;
	}
	for (int i = 0; i < V; i++) {
		if (!visit[i]) {
			answer = dfs(i);
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
	/*for (int i = 0; i < V; i++) {
		cout << visit[i];
	}*/
	cout << endl;
	for (int i = 0; i < V; i++) {
		cout << recStack[i];
	}

	return 0;
}
