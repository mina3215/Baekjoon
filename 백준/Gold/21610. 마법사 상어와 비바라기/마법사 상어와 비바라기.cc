#include<bits/stdc++.h>

using namespace std;

//1~8
int dy[] = {0,0,-1,-1,-1,0,1,1,1};
int dx[] = {0,-1,-1,0,1,1,1,0,-1};

int land[50][50];
int rained[50][50];

int N, M;

void findDg(vector<pair<int, int>> v) {
	int dgdy[] = {1,1,-1,-1};
	int dgdx[] = {1,-1,1,-1};

	for (auto i : v) {
		//cout << i.first << i.second << ' ';
		for (int j = 0; j < 4; j++) {
			int dgy = i.first + dgdy[j];
			int dgx = i.second + dgdx[j];
			if (dgy<0 || dgx<0 || dgy>=N || dgx>=N) continue;
			if (land[dgy][dgx] == 0) continue;
			land[i.first][i.second] += 1;
		}
	}
}

void rain(int cnt, int d, int s) {
	vector<pair<int, int>> v;
	//이동할 거리 * 방향
	int ny = dy[d] * s;
	int nx = dx[d] * s;
	// 첫번째 시도는 무조건 우측 아래에서 시작한다.
	if (cnt == 1) {
		v.push_back({ N - 1,  0 });
		v.push_back({ N - 1, 1 });
		v.push_back({ N - 2, 0 });
		v.push_back({ N - 2, 1 });
	}else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (land[i][j] >= 2 && rained[i][j]!=cnt-1) {
					v.push_back({ i,j });
					land[i][j] -= 2;
				}
			}
		}
	}

	for (auto &i : v) {
		i.first += ny;
		i.second += nx;
		while(i.first < 0) i.first += N;
		i.first = i.first%N;
		while(i.second < 0) i.second += N;
		i.second = i.second%N;
		land[i.first][i.second] += 1;
		rained[i.first][i.second] = cnt;
	}

	findDg(v);

}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> land[i][j];
		}
	}
	int d, s;
	fill(&rained[0][0], &rained[0][0] + 50 * 50, 0);
	
	for (int t = 1; t <= M; t++) {
		cin >> d >> s;
		//for (int i = 0; i < N; i++) {
			//for (int j = 0; j < N; j++) {
			//	cout << land[i][j] << ' ';
			//}
		//	cout << '\n';
		//}
		rain(t, d,s);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (land[i][j] >= 2 && rained[i][j] != M) {
				land[i][j] -= 2;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans += land[i][j];
		}
	}
	cout << ans;
}