#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

int N;
int _max = 0;
vector<string> words;
int a[26];

void input() {
	cin >> N;
	fill(a, a + 26, 0);
	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;
		words.push_back(word);
	}
}


int main() {
	input();

	for(int i=0; i<words.size(); i++){
		int v = 1;
		for (int j = words[i].size() - 1; j >= 0; j--) {
			a[words[i][j] - 'A'] += v;
			v *= 10;
		}
	}

	sort(a, a + 26, greater<int>());

	int answer = 0;
	int cnt = 9;
	for (auto i : a) {
		answer += (cnt--) * i;
	}

	cout << answer;

	return 0;
}