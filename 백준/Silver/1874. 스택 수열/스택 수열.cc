#include<bits/stdc++.h>

using namespace std;

stack<int> s;
vector<char> c;
int N;
int main() {
	cin >> N;
	int cnt = 1;
	int n;
	for (int i = 0; i < N; i++) {
		cin >> n;
		while (cnt <= n) {
			s.push(cnt);
			cnt++;
			c.push_back('+');
		}
		if (s.top() == n) {
			s.pop();
			c.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}

	}
	for (auto i : c) cout << i << '\n';
	return 0;
}


