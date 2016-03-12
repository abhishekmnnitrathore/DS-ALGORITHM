/*
 * Solution is based on backtracking coloring problem
 * assume we have to color this graph with only 2 color
 * m =2
 */

#include<iostream>
using namespace std;

namespace {
#define E 5
#define V 4
int adj[V][V] = { 0 };
int color[V] = { 0 };
int m = 2; // this is number of color

bool isSafe(int v, int c) {
	for (int i = 0; i < V; i++) {
		if (adj[v][i] && c == color[i])
			return false;
	}
	return true;
}

bool colorgraph(int v) {
	if (v == V)
		return true;
	for (int c = 1; c <= m; c++) {
		if (isSafe(v, c)) {
			color[v] = c;
			if (colorgraph(v + 1))
				return true;
			color[v] = 0;
		}
	}
	return false;
}
}
int main_color() {

	int V1[] = { 0, 0, 0, 2, 2 };
	int V2[] = { 1, 2, 3, 3, 1 };

	for (int i = 0; i < E; i++) {
		adj[V1[i]][V2[i]] = 1;
		adj[V2[i]][V1[i]] = 1;
	}
	if(colorgraph(0))
		cout<<"YES";
	else
		cout<<"NO";

	for (int i = 0; i < V; i++)
		cout << color[i] << "";
	return 0;
}
