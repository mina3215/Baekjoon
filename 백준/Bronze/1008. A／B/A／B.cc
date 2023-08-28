#include<iostream>

using namespace std;

int main() {
	double num1, num2;
	double ans;
	cin >> num1 >> num2;
	ans = num1 / num2;
	cout << fixed;
	cout.precision(9);
	cout << num1 / num2;
	return 0;
}