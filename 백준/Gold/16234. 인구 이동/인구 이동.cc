#include <bits/stdc++.h>

using namespace std;

int N, L, R;
int nations[50][50];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int visited1[50][50];

int n = 1;

int cnt = 0;
int isOpen = 0;

// 국경선을 열 나라를 찾음 
int find(int pre_y,int pre_x) {
	
	vector<pair<int, int>> v;

	queue<pair<int, int>> q;
	
	q.push({ pre_y,pre_x });
	visited1[pre_y][pre_x] = 1;

	int num = 0; // 몇개 나라의 국경선이 열렸는가?
	int sum = 0;
	
	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front(); q.pop();
		v.push_back({ y,x });
		sum += nations[y][x];
		num++;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (visited1[ny][nx]) continue;
			if (abs(nations[y][x] - nations[ny][nx]) >= L && abs(nations[y][x] - nations[ny][nx]) <= R) {
				visited1[ny][nx] = 1;
				q.push({ ny,nx });
			}
		}
	}

	int avg = sum / num;

	for (pair<int, int> a : v) {
		nations[a.first][a.second] = avg;
	}
	if (num > 1) isOpen = 1;

	return 0;
}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> nations[i][j];
		}
	}

	while (true) {
		fill(&visited1[0][0], &visited1[0][0] + 50 * 50, 0);
		isOpen = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (!visited1[y][x]) {
					find(y, x);
				}
			}
		}
		if (!isOpen) break;
		cnt++;
	}

	cout << cnt;

}