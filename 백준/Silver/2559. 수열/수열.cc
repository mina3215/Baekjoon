#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	//vector<int> nums;
	int nums[100000];	

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (i == 0)nums[i] = n;
		else nums[i] = nums[i-1] + n;
	}

	int max = nums[K - 1];

	for (int i = K; i < N; i++) {
		if (max <= (nums[i] - nums[i - K])) {
			max = nums[i] - nums[i-K];
		}
	}

	cout << max;

	return 0;
}