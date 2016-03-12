#include<iostream>
using namespace std;

namespace {
#define V 4
int visited[] = { 0 };

int path(int graph[V][V], int start, int end, int k) {
	if (k == 0 && start == end) {
		return 1;
	}
	if (k < 0)
		return 0;
	int count =0;
	visited[start] = 1;
	for (int i = 0; i < V; i++) {
		if (graph[start][i] == 1 && !visited[i]) {
			count = count+path(graph, i, end, k-1);
		}
	}
	return count;
}

}

int main_path_with_k_edge() {
	int graph[V][V] = { { 0, 1, 1, 1 },
			            { 0, 0, 0, 1 },
			            { 0, 0, 0, 1 },
			            { 0, 0, 0, 0 } };
	int k = 2, start = 0, end = 3;
	cout << path(graph, start, end, k);
}
