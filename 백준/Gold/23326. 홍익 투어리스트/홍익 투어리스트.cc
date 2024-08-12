#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

vector<int> univ(500000);
set<int> location;
int N, Q;
int dh = 0;

void transfer(int n) {
	if (location.find(n) != location.end()) {
		location.erase(n);
	}
	else {
		location.insert(n);
	}
}

void move(int n) {
	dh = (dh + n) % N;
}

int find() {
	if (location.empty())
		return -1;
	auto ans = location.lower_bound(dh);
	if (ans != location.end()) {
		return *ans - dh;
	}
	return N - dh + *location.begin();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> univ[i];
		if (univ[i])
			location.insert(i);
	}

	for (int q = 0; q < Q; q++) {
		int query, num;
		cin >> query;
		switch (query) {
			case 1: {
				cin >> num;
				transfer(num - 1);
				break;
				}
			case 2: {
				cin >> num;
				move(num);
				break;
			}
			case 3: {
				int ans = find();
				cout << ans <<'\n';
				break;
			}
		}
	}

}