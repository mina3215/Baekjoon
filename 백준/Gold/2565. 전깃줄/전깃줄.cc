#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int v[501];

int main() {
	cin >> N;

	int l = 0;

	vector<pair<int, int>> line;
	
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		line.push_back({ a,b });
	}

	sort(line.begin(), line.end());


	for (int i = 0; i < N; i++) {
		auto it = lower_bound(v, v+l, line[i].second);
		if (*it==0) {
			l++;
		}
		*it = line[i].second;
	}
	cout << N - l;
}