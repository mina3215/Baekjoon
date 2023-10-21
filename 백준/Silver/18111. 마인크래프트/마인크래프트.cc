#include<bits/stdc++.h>

using namespace std;

int N, M, B;

int land[500][500];

int main() {
	cin >> N >> M >> B;
	int maxV = -1;
	int minV = 257;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> land[i][j];
			minV = min(land[i][j], minV);
			maxV = max(land[i][j], maxV);
		}
	}

	int ans = -1;
	int ansh = 0;
	for (int h = maxV; h >= minV; h--) {
		int time = 0;
		int Bag = B;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				//if (ans!=-1 && time >= ans) {
					//cout << ans << ' ' << ansh; 
					//return 0;
				//}
				int abso = abs(land[i][j] - h);
				if (land[i][j] < h) {
					Bag -= abso;
					time += abso;
				}
				else{
					Bag += abso;
					time += abso * 2;
				}
			}
		}
		if (Bag >= 0) {
			if (ans == -1 || ans > time) {
				ans = time;
				ansh = h;
			}
		}
	}

	cout << ans << ' ' << ansh;

}