#include <bits/stdc++.h>

using namespace std;

int N, M;
char land[100][100];
int visited[100][100];

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0,0,-1,1 };

int ans = 100000;

int dfs(int y, int x, int num) {
	visited[y][x] = num;
	if (y == N - 1 && x == M - 1) {
		if (num <= ans) ans = num;
		return 0;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
		if (land[ny][nx]=='1'&&(!visited[ny][nx]||visited[ny][nx]> num + 1)) dfs(ny, nx, num + 1);
	}
	return 0;
}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> land[i][j];
		}
	}

	dfs(0, 0, 1);

	cout << visited[N - 1][M - 1];

}