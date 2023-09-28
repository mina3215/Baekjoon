#include<bits/stdc++.h>
#include <iostream>

using namespace std;
int num;
int alphabets[26];
int main() {
	bool result = true;
	cin >> num;
	for (int i = 0; i < num; i++) {
		string s;
		cin >> s;
		alphabets[s[0] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (alphabets[i] >= 5) {
			cout << char('a' + i);
			result = false;
		}
	}
	if (result) {
		cout << "PREDAJA";
	}

	return 0;
}
