#include <iostream>
#include <algorithm>

using namespace std;


int main() {
	int input[8];
	for (int i = 0; i < 8; i++) {
		cin >> input[i];
	}

	int n = 0;

	for (int i = 0; i < 7; i++) {
		if (input[i] > input[i + 1]) {
			n -= 1;
		}
		else if (input[i] < input[i + 1]) {
			n += 1;
		}
	}
	if (n == -7) {
		cout << "descending";
	}
	else if(n==7){
		cout << "ascending";
	}
	else {
		cout << "mixed";
	}
	return 0;

}