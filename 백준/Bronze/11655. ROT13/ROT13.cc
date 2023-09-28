#include<bits/stdc++.h>
#include <iostream>

using namespace std;

char ROT(char c) {
	int code = 0;
	if ('A' <= c && 'Z' >= c) {
		code = (c - 'A' + 13) % 26;
		c = char('A' + code);
	}
	if ('a' <= c && 'z' >= c) {
		code = (c - 'a' + 13) % 26;
		c = char('a' + code);
	}
	return c;
}


string s;

int main() {
	getline(cin, s);
	for (char c : s) cout << ROT(c);
	return 0;
}

