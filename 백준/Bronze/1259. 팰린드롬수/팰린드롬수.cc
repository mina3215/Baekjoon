#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;


int main() {
	while (true) {
		string s;
		cin >> s;
		if (s == "0")
			break;
		int len = s.length();
		string s1 = s.substr(0, len / 2);
		string s2 = s.substr(len - (len / 2));
		
		reverse(&s2[0], &s2[0] + (s2.length()));
		//reverse(s2.begin(), s2.end());

		if (s1 == s2)
			cout << "yes"<<'\n';
		else
			cout << "no"<<'\n';
	}

}