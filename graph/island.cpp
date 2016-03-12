/*
 */

#include<iostream>

using namespace std;
namespace {
# define M 5
int graph [M][M] = {{1, 1, 0, 0, 0},
                  {0, 1, 0, 0, 1},
                  {1, 0, 0, 1, 1},
                  {0, 0, 0, 0, 0},
                  {1, 0, 1, 0, 1}};

int visited[M][M] = { 0 };
int moveX[] = {-1, -1, -1, 1, 1, 1, 0, 0 };
int moveY[] = {-1 , 0, 1, -1, 0, 1, 1, -1 };
int new_x = 0, new_y = 0;
bool isSafe(int x, int y) {
	if(x>=0 && y>=0 && x<M && y<M && graph[x][y] && !visited[x][y]) {
		return true;
	}
	return false;
}

void island(int x, int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 8; i++) {
		new_x = x + moveX[i];
		new_y = y + moveY[i];
		if (isSafe(new_x, new_y)) {
			island(new_x, new_y);
		}
	}
}

}

int main_island() {
	int count = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && graph[i][j]) {
				count++;
				island(i, j);
			}
		}
	}
	cout<< "count = "<< count;
	return 0;
}
