#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

int N, M;
int min_V = -1;
int MAP[1001][1001];
int visited[1001][1001][2];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };


void BFS(){
	queue<tuple<int, int, int, int>> q;
	q.push({ 1,1,1,0 });
	while (!q.empty()) {
		int y, x, n, wall;
		tie(y, x, n, wall) = q.front();
		q.pop();
		if (y == N && x == M) {
			min_V = n;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny <= 0 || nx <= 0 || ny > N || nx > M)continue;
			// 벽이고, 이전에 어떤 벽도 깬적 없고, 지금 부딪힌 벽도 깬적 없다. -> 지금 깬다. 
			if (MAP[ny][nx]&&!wall&&!visited[ny][nx][1]){
				q.push({ ny,nx,n + 1,1 });
				visited[ny][nx][1] = 1;
			} // 벽이 아니고, 이전에 들른적 없으면 push
			else if (!MAP[ny][nx] && !visited[ny][nx][wall]) {
				q.push({ ny,nx,n + 1,wall });
				visited[ny][nx][wall] = 1;
			}
		}
	}
	return;
}

int main() {
	cin >> N >> M;
	string s;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		int j = 1;
		for (auto c : s) MAP[i][j++] = int(c)-48;
	}
	BFS();
	cout << min_V;
}