#include<bits/stdc++.h>

using namespace std;

int N, M;
char board[51][51];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int minV = 2e7;

int BFS(int i, int j) {
	char visited[51][51];
	fill(&visited[0][0], &visited[0][0] + 51*51, '0');
	int ans = 0;
	queue<pair<int, int>> q;
	q.push({ i,j });
	visited[i][j] = board[i][j];
	int y, x;
	while (!q.empty()) {
		tie(y, x) = q.front(); q.pop();
		for (int n = 0; n < 4; n++) {
			int ny = y + dy[n];
			int nx = x + dx[n];
			if (visited[ny][nx] != '0' || ny < i || nx < j || ny > i + 7 || nx > j + 7) { 
				continue;
			}
			if (visited[y][x] == board[ny][nx]) {
				ans+=1;
				visited[ny][nx] = visited[y][x] == 'W' ? 'B' : 'W';
			}
			else {
				visited[ny][nx] = board[ny][nx];
			}
			q.push({ ny,nx });
		}
	}
	ans = min(ans, 64 - ans);
	minV = min(ans, minV);

	return 0;
}



int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			BFS(i, j);
		}
	}

	cout << minV;

}