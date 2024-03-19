#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<vector<int>> Tree(10);
int K, num;
vector<int> v;

void solution(int start, int end, int d) {
	if (d >= K)
		return;
	if (start == end) {
		Tree[d].push_back(v[start]);
		return;
	}
	int mid = (start + end) / 2;

	if (mid < 0 || mid >= num) {
		return;
	}
	Tree[d].push_back(v[mid]); // 중간 값 트리 내 depth d에 push
	solution(start, mid - 1, d + 1); // 왼쪽 서브 트리
	solution(mid + 1, end, d + 1);//오른쪽 서브 트리. 
	return;
}

int main() {
	cin >> K;

	num = pow(2, K)-1;
	int n;
	for (int i = 0; i < num ;i++) {
		cin >> n;
		v.push_back(n);
	}

	solution(0, num - 1, 0);

	for (int i = 0; i < K; i++) {
		for (int j = 0;j < Tree[i].size();j++) {
			cout << Tree[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}