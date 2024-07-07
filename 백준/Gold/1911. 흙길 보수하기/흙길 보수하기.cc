#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>

using namespace std;

int N, L;

vector<pair<int, int>> v;

void input() {
	int s, e;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		v.push_back({ s,e });
	}
	sort(v.begin(), v.end());
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> L;

	int cnt = 0;
	int prev_e = -1;
	
	input();

	for (int i = 0; i < N; i++) {
		int s, e;
		tie(s, e) = v[i];
		if (s <= prev_e)
			s = prev_e + 1;
		if (s >= e)
			continue;
		
		int len = e - s;
		cnt += len / L;
		if (len % L) {
			cnt++;
			prev_e = e + (L - (len % L))-1;
		}
		else
			prev_e = e-1;
	}
	cout << cnt;
}