#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
	int arr[10];
	fill(arr, arr+10, 0);
	int A, B, C;
	cin >> A >> B >> C;
	string ans = to_string(A*B*C);

	for (char i:ans) {
		int num = i - '0';
		arr[num] += 1;
	}
	/*for (auto i : arr) {
		cout << i << endl;
	}*/
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
}