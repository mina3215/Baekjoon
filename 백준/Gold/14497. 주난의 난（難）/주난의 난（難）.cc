#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<queue>

using namespace std;

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
vector<string> board(301);
vector<vector<int>> visited(301,vector<int> (301));
int N, M;
int jx, jy;
int gx, gy;

void BFS(int n) {

	queue<pair<int, int>> q;
	q.push({ jy, jx});

	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visited[ny][nx] == n) continue;

			visited[ny][nx] = n;
			
			if (board[ny][nx] != '0') {
				board[ny][nx] = '0';
				continue;
			}
			q.push({ ny,nx });
		}
	}
}

int main() {
	cin >> N >> M;
	cin >> jy >> jx >> gy >> gx;
	jy--;jx--;gy--;gx--;

	for (int i = 0; i < 301; i++)
		fill(visited[i].begin(), visited[i].end(), 0);

	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	int n = 1;
	while (!visited[gy][gx]) {
		BFS(n++);
	}

	cout << visited[gy][gx];
}