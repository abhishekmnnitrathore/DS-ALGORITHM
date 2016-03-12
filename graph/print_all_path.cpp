#include<iostream>

using namespace std;

namespace {
int N, E, s, d;
int graph[1000][10000];
int visited[10000];
int V1[1000], V2[1000];
int path[10000];
void dfs(int v, int d, int path_index) {
	visited[v] = 1;
	path[path_index] = v;
	path_index++;
	if (v == d) {
		for (int i = 0; i < path_index; i++) {
			cout << path[i] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < N; i++) {
		if (graph[v][i] && !visited[i]) {
			dfs(i, d, path_index);
		}
	}
	visited[v] = 0;
	path_index--;
}

}

int main_all_path() {
	cin >> N >> E >> s >> d;
	for (int i = 0; i < E; i++) {
		cin >> V1[i] >> V2[i];
	}
	for (int i = 0; i < E; i++) {
		graph[V1[i]][V2[i]] = 1;
	}
	dfs(s, d, 0);
	return 0;
}
