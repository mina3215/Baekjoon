#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> DP(1002, vector<int>(1002,0));

string s1, s2;

int main() {
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size();j++) {
			if (s1[i] == s2[j])
				DP[i + 1][j + 1] = max(DP[i][j] + 1, DP[i][j + 1]);
			else
				DP[i + 1][j + 1] = max(DP[i][j + 1], DP[i + 1][j]);
		}
	}
	cout << DP[s1.size()][s2.size()];
}