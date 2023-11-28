#include<bits/stdc++.h>

using namespace std;

int T;
int DP[1001];
int times[1001];

void BFS(int W, int N, vector<vector<int>> node) {
	
	queue<int> q;
	q.push(W);
	
	int start = 0;
	
	DP[W] = times[W];
	
	while (!q.empty()) {
		start = q.front();
		q.pop();
		for (int i = 0; i < node[start].size(); i++) {
			if (node[start][i]) {
				if (times[node[start][i]] + DP[start] > DP[node[start][i]]) {
					q.push(node[start][i]);
					DP[node[start][i]] = DP[start] + times[node[start][i]];
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> T;
	for (int t = 0; t < T; t++) {
		fill(DP, DP + 1001, 0);
		int N, K;
		cin >> N >> K; // 건물 개수, 건설 순서 규칙의 총 개수
		vector<vector<int>> node(N + 1);
		for (int i = 1; i <= N; i++) {
			cin >> times[i];
		}
		int start, end;

		for (int i = 0; i < K; i++) {
			cin >> start >> end;
			node[end].push_back(start);
		}

		int W;
		cin >> W;

		BFS(W, N, node);

		sort(DP, DP + N+1,greater<int>());


		cout << DP[0] << '\n';
	}

}