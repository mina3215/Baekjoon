#include<iostream>
#include<algorithm>

using namespace std;

int N, M; // 칸 갯수와 사과 갯수

int main() {
	cin >> N >> M;
	int T;
	cin >> T;
	int ans = 0;
	pair<int, int> basket = {1,M};
	int apple;

	for (int t = 0; t < T; t++) {
		cin >> apple;
		if (apple >= basket.first && apple <= basket.second)
			continue;
		else if (apple < basket.first) {
			ans += abs(apple - basket.first);
			basket.second -= abs(apple - basket.first);
			basket.first -= abs(apple - basket.first);
		}
		else {
			ans += abs(apple - basket.second);
			basket.first += abs(apple - basket.second);
			basket.second += abs(apple - basket.second);
		}
	}
	cout << ans;
}