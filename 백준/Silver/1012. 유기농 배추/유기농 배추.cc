#include <bits/stdc++.h>

using namespace std;


int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };


int main() {
	int T, M, N, K;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> M >> N >> K;
		int ans = 0;
		int farm[50][50]={ 0, };
		int visited[50][50] = { 0, };

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			farm[y][x] = 1;
		}
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				if (farm[n][m]&&!visited[n][m]) {
					ans++;
					queue<pair<int, int>> q;
					visited[n][m] = 1;
					q.push({ n, m });
					int y, x;
					while (q.size()){
						tie(y, x) = q.front(); q.pop();
						for (int i = 0; i < 4; i++) {
							int ny = y + dy[i];
							int nx = x + dx[i];
							if (ny < 0 || ny >= N || nx >= M || nx < 0 || visited[ny][nx] || !farm[ny][nx]) continue;
							q.push({ ny,nx });
							visited[ny][nx] = 1;
						}
					}
				}
			}
		}
		cout << ans<<'\n';
	}
}