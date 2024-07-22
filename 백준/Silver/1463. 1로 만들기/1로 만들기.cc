#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

vector<int> v(1000001);


int main() {
	int N;
	cin >> N;
	fill(v.begin(), v.end(), 0);
	
	queue<int> q;
	q.push(N);
	
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		if (v[1])
			break;

		if (!v[n / 3] && !(n % 3)) {
			q.push(n / 3);
			v[n / 3] = v[n] + 1;
		}

		if (!v[n / 2] && !(n % 2)) {
			q.push(n / 2);
			v[n / 2] = v[n] + 1;
		}
		if (n - 1 > 0 && !v[n - 1]) {
			q.push(n - 1);
			v[n - 1] = v[n] + 1;
		}
		
	}
	cout << v[1];
}