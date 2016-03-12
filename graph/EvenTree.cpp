#include<iostream>
using namespace std;
#define N 10
#define V 9
int adj[N + 1][N + 1];
void dfs(int index, int visited[]) {
	//cout << index << " ";
	visited[index] = 1;
	for (int i = 0; i < N + 1; i++) {
		if (!visited[i] && adj[index][i]) {
			dfs(i, visited);
		}
	}
}

void visitinitilize(int visited[]) {
	for (int i = 0; i < N + 1; i++) {
		visited[i] = 0;
	}

}
int  countone(int visited[]) {
	int count = 0;
	for (int i = 1; i < N + 1; i++) {
		if (visited[i] == 0) {
			count++;
		}
	}
	return count;
}
int maineventree() {
	int A[V] = { 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int B[V] = { 1, 1, 3, 2, 1, 2, 6, 8, 8 };
	int answer=0;
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < N + 1; j++) {
			adj[i][j] = 0;
		}
	}
	for (int i = 0; i < V; i++) {
		adj[A[i]][B[i]] = 1;
		adj[B[i]][A[i]] = 1;
	}
	int *visited = new int[N + 1];
	visitinitilize(visited);
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			if (adj[i][j] == 1) {
				adj[i][j] = 0;
				adj[j][i] = 0;
				dfs(i, visited);
				cout << endl;
				int first = countone(visited);
				visitinitilize(visited);
				dfs(j, visited);
				cout << endl;
				int second = countone(visited);
				visitinitilize(visited);
				if (first % 2 == 0 && second % 2 == 0) {
					answer++;
				}
				adj[i][j] = 1;
				adj[j][i] = 1;
			}
		}
	}
	cout<<answer/2;
	return 0;
}
