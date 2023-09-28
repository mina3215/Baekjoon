#include<bits/stdc++.h>
#include <iostream>

using namespace std;

string f, file;
int star_idx, f_len;

int num;

int main() {
	cin >> num;
	cin >> f;
	f_len = f.length() -1;
	for (int i = 0; i < f_len; i++) if (f[i] == '*') star_idx = i;
	
	for (int i = 0; i < num; i++) {
		cin >> file;
		int file_len = file.length() - 1;
		string result = "DA";
		for (int j = 0; j < star_idx; j++) {
			if (f[j] != file[j]) {
				result = "NE";
				break;
			}
		}

		for (int j = 0; j < f_len - star_idx; j++) {
			if ((f[f_len - j] != file[file_len - j]) ||(file_len-j < star_idx)) {
				result = "NE";
				break;
			}
		}
		cout << result << endl;
	}
	return 0;
}

