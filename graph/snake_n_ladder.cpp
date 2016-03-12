#include<iostream>

using namespace std;
namespace {
#define N 30
#define INF 500
int path[N][N];

void distance() {

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
			}
		}
	}

}
}

int main_snake_ladder() {
	int moves[N];
	for (int i = 0; i < N; i++)
		moves[i] = -1;

	// Ladders
	moves[2] = 21;
	moves[4] = 7;
	moves[10] = 25;
	moves[19] = 28;

	// Snakes
	moves[26] = 0;
	moves[20] = 8;
	moves[16] = 3;
	moves[18] = 6;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) {
				path[i][j] = 0;
			} else {
				path[i][j] = INF;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (moves[i] != -1)
			path[i][moves[i]] = 0; // This connect start and end point of ladder and snake
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < i + 7; j++) {
			if (i < N && j < N)
				path[i][j] = 1;
		}
	}

	/*for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			cout<<path[i][j] <<" ";
		}
		cout<<endl;
	}*/

	distance();
	cout << "move=  " << path[0][N - 1];
	return 0;
}
