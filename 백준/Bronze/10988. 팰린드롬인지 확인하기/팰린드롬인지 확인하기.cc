#include<bits/stdc++.h>
#include <iostream>

using namespace std;
string s;
int main() {
	cin >> s;
	int start = 0, end = s.length() - 1;
	while (start < end) {
		if (s[start] == s[end]) {
			start++;
			end--;
		}
		else {
			break;
		}
	}
	if (start >= end) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	return 0;
}
