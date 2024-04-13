#include<iostream>
#include<queue>
#include<algorithm>
#include<tuple>

using namespace std;

int N, M;
int cnt = 0;
int min_V = 2e9;
int visited[200001];


void find_bro() {
	queue<pair<int, int>> q;
	q.push({ N,0 });
	visited[N] = 0;
	while (!q.empty()) {
		int x, t;
		tie(x, t) = q.front();
		q.pop();
		if (t > min_V) break;
		if (x == M) {
			min_V = min(min_V, t);
			cnt++;
		}

		int arr[3] = { x, -1, 1 };
		for (int i = 0; i < 3; i++) {
			int nx = x + arr[i];
			if (nx < 0 || nx>=200000) continue;
			if (visited[nx] && visited[nx] < t + 1) continue;
			q.push({ nx,t + 1 });
			visited[nx] = t + 1;
		}
	}
}

int main() {
	cin >> N >> M;
	find_bro();
	cout << min_V << '\n' << cnt;
}