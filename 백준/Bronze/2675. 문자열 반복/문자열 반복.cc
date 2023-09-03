#include <iostream>
#include<string>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int R;
		string S;
		int n = 0;

		cin >> R;
		//getline(cin, S);
		cin >> S;

		int len = S.length();
		while(n < len) {
			for (int j = 0; j < R; j++) {
				cout << S[n];
			}
			n++;
		}
		cout << '\n';
	}
}