/*
 * it provides shortest path from source to all the nodes.
 * termology:
 * graph[][]: This provides connection between nodes with their weight, and for non connected
 * nodes assign weight value equal to infinity.
 * visited[]: This array keeps track of vertices whose minimum distance from source is calculated.
 * dist[]: This array keeps the shortest path from source to all the nodes
 *
 * Algo:
 * 1. Start from vertices and check for all connected nodes are source and pick shortest one and assign
 *    true in visited[] array. it means that nodes shortest path is calculated.
 * 2. start from picked node and check for all the connected vertices
 *    shortest path till picked value + weight from picked value to connected node is less than previous
 *    value of next node than update it otherwise leave it as it is.
 * */

#include<iostream>
using namespace std;
#define V 9
#define I 999

namespace {

void dijkstra(int graph[V][V], int source, int visited[V], int dist[V]) {
	int nearest_node = source, min;
	for (int i = 0; i < V; i++) {
		min = 9999;
		for (int j = 0; j < V; j++) {
			if (min > dist[j] && !visited[j]) {
				min = dist[j];
				nearest_node = j;
			}
		}
		visited[nearest_node] = 1;
		for (int j = 0; j < V; j++) {
			if (dist[nearest_node] + graph[nearest_node][j] < dist[j]
					&& !visited[j])
				dist[j] = dist[nearest_node] + graph[nearest_node][j];
		}
	}
}

}

int main_dijsktra() {
	int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
	                   {4, 0, 8, 0, 0, 0, 0, 11, 0},
	                   {0, 8, 0, 7, 0, 4, 0, 0, 2},
	                   {0, 0, 7, 0, 9, 14, 0, 0, 0},
	                   {0, 0, 0, 9, 0, 10, 0, 0, 0},
	                   {0, 0, 4, 0, 10, 0, 2, 0, 0},
	                   {0, 0, 0, 14, 0, 2, 0, 1, 6},
	                   {8, 11, 0, 0, 0, 0, 1, 0, 7},
	                   {0, 0, 2, 0, 0, 0, 6, 7, 0}
	                     };
	int visited[V] = { 0 };
	int dist[V];
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (graph[i][j] == 0)
				graph[i][j] = I;
		}
	}
	for (int j = 0; j < V; j++) {
		dist[j] = graph[0][j];
	}
	visited[0] = 1;
	dijkstra(graph, 0, visited, dist);
	for(int i=1;i<V;i++)
		cout<<dist[i]<<" ";
}
