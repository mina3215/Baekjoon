#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX 1000000

int N;
map<int, vector<int>> m;


int main() {
	for (int i = 1; i <= MAX;i++) {
		int n = i;
		int _n = i;
		while (_n > 0) {
			n += (_n) % 10;
			_n /= 10;
		}
		m[n].push_back(i);
	}
	
	cin >> N;
	if (m.find(N)!=m.end()){
		sort(m[N].begin(), m[N].end());
		cout<< m[N][0];
	}
	else
		cout << 0;


}