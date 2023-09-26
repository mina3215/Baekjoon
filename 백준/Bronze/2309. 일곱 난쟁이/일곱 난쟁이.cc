#include <bits/stdc++.h>

using namespace std;


// 키의 합이 100 이다  -> 조합으로 풀 수 있다. 
// 키의 합이 100 이다 -> 모두 9명의 난쟁이 키를 더한 후 두 명의 조합을 찾아서 뺐을 때 
// 100이 되는 난쟁이를 찾자.
// 오름차순으로 출력한다 -> sort 필요

int num = 9;
vector <int> v(9);
vector <int> find(1);

void printV(vector <int> v) {
	int sum = 0;
	for (int a : v) sum += a;
	if (sum == 100) {
		for (int a : v) {
			cout << a <<endl;
		}
		exit(0);
		
	}
}

void Combi(int start, vector<int> b) {
	if (b.size() == 7) {
		printV(b);
		return;
	}
	for (int i = start + 1; i < 9; i++) {
		b.push_back(v.at(i));
		Combi(i, b);
		b.pop_back();
	}
	return;
}

int main() {
	for (int i = 0; i < num; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	vector <int> b;
	Combi(-1, b);

	return 0;
}