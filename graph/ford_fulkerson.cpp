#include <iostream>
#include <climits>
#define V 6
using namespace std;

int G[V][V] = { {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}};;
int F[V][V];
bool Visited[V];

int send(int s, int t, int minn) {
	Visited[s] = true;

	if (s == t) {
		return minn;
	}

	for (int i = 0; i < V; i++) {
		if (!Visited[i] && G[s][i] - F[s][i] > 0) {
			if (int sent = send(i, t, min(minn, G[s][i] - F[s][i]))) {
				F[s][i] += sent;
				F[i][s] -= sent;
				return sent;
			}
		}
	}
	return 0;
}

int main_ford_fulkerson() {
	int total = 0;
	while (int sent = send(0, 5, INT_MAX)) {
		total += sent;
		for (int i = 0; i < V; i++)
			Visited[i] = 0;
	}
	cout << "The bandwidth is " << total << "." << endl;
	cout << endl;
}
