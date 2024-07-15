#include<iostream>
#include<map>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

// 1. 산술 평균 : N개의 수 합을 N으로 나눈 값
// 2. 중앙값 : 증가하는 순으로 나열해 중앙에 위치하는 값 
// 3. 최빈값 : 가장 많이 나타나는 값 
// 4. 범위 : 최대 최소 차이 

int N;
long long sum = 0;
int _min = 2e9;
int _max = -4000;
vector<int> v;
map<int, int> MAP;

int find_average() {
	int ans = abs(sum / N);
	float mod = sum % N;
	if (abs(mod / N) >=0.5) {
		ans+=1;
	}
	if (sum < 0)
		ans *= -1;
	return ans;
}

int find_mid() {
	sort(v.begin(), v.end());
	return v[N / 2];
}

bool compare(pair<int,int> p1, pair<int,int> p2) {
	if (p1.first != p2.first)
		return p1.first>p2.first;
	return p1.second < p2.second;
}

int find_freq() {
	vector<pair<int, int>> mv;
	for (auto it = MAP.begin(); it != MAP.end();it++) {
		mv.push_back({ it->second,it->first });
	}
	sort(mv.begin(), mv.end(), compare);

	if (mv.size() <= 1 || mv[0].first > mv[1].first)
		return mv[0].second;
	else
		return mv[1].second;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		sum += n;
		v.push_back(n);
		if (!MAP[n])
			MAP[n] = 1;
		else
			MAP[n]++;
		_min = min(n, _min);
		_max = max(n, _max);
	}

	cout << find_average()<<'\n';
	cout << find_mid() << '\n';
	cout << find_freq() << '\n';
	cout << _max - _min;
}