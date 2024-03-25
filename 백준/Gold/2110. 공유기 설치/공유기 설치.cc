#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> Router;
int N, C;

int main() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		Router.push_back(n);
	}

	sort(Router.begin(), Router.end());
	int start = 1;
	int end = Router.back()-Router[0];
	int result = 0;
	while (start <= end) {
		int mid = (start + end)/2;
		int n = 1;
		int prev = Router[0];
		for (int i = 1; i < N; i++) {
			if (Router[i] >= prev + mid) {
				n++;
				prev = Router[i];
			}
		}
		if (n < C) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
			result = max(result, mid);
		}
	}
	cout << result;

}