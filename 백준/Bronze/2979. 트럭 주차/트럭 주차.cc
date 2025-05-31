#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int fee[4] = { 0,0,0,0 };

int main() {
	int time[101];
	fill(time, time + 101, 0);
	cin >> fee[1] >> fee[2] >> fee[3];

	for (int i = 0; i < 3; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = a; j < b; j++) {
			time[j]++;
		}
	}
	int sum = 0;
	for (int t : time) {
		sum += (fee[t] * t);
	}
	cout << sum << endl;
	return 0;
}