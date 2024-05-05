#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

/*
* 1초 
* n <= 400
* k <= 50000
*/

int idx[401][401];
int n, k;

// 위상 정렬 
void find_order(vector<vector<int>> & next) {
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	fill(&idx[0][0], &idx[0][0] + 401 * 401,0);
	for (int i = 0; i < k; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		idx[n1][n2] = -1;
		idx[n2][n1] = 1;
	}
	// 중간 지점
	for (int m = 1; m < n + 1; m++) {
		// 이전
		for (int s = 1; s < n + 1;s++) {
			if (idx[s][m]!=-1) continue;
			for (int e = 1; e < n + 1;e++) {
				if (idx[m][e] != -1)continue;
				idx[s][e] = -1;
				idx[e][s] = 1;
			}
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		cout << idx[n1][n2] << '\n';
	}
}