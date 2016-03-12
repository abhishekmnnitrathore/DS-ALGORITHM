/*  check for destination, return when destination is
 * reached.
 */

#include<iostream>

using namespace std;
namespace {
#define E 6
#define V 5

int visit[V] = { 0 };
int adj[V][V] = { 0 };

bool dfs(int s, int d) {
	if(s == d)
		return true;
	for (int i = 0; i < V; i++) {
		if (adj[s][i] == 1 && !visit[i]) {
			visit[i] = 1;
			if(dfs(i, d))
				return true;
		}
	}
	return false;
}
}

int main_path() {
	int V1[] = { 0, 0, 1, 2, 2, 3 };
	int V2[] = { 1, 2, 2, 0, 3, 3 };
	for (int i = 0; i < E; i++) {
		adj[V1[i]][V2[i]] = 1;
	}
	int source =0 , destination= 3;
	visit[source] = 1;
	if(dfs(source, destination))
		cout<<endl<<source << " to " << destination <<" path is there";
	else
		cout<<endl<<source << " to " << destination <<" path is not there";
	return 0;
}
