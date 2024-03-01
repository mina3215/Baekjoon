#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int board[8][8];
int N, M;
int min_cnt = 2e9;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
typedef pair<int, int> pii;

vector<pair<int, pii>> CCTV;

void updateBoard(int dir, int y, int x, int _board[8][8]) {
    while (true) {
        y += dy[dir];
        x += dx[dir];
        if (y < 0 || y >= N || x < 0 || x >= M || _board[y][x] == 6) break;
        if (_board[y][x] <= 0) _board[y][x] = -1;
    }
}

void find_MinNum(int index, int _board[8][8]) {
    if (index == CCTV.size()) {
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (_board[i][j] == 0) ++cnt;
            }
        }
        min_cnt = min(min_cnt, cnt);
        return;
    }

    int type = CCTV[index].first;
    int x = CCTV[index].second.second;
    int y = CCTV[index].second.first;
    int temp_board[8][8];
    
    for (int dir = 0; dir < 4; ++dir) {
        copy(&_board[0][0], &_board[0][0] + 8*8, &temp_board[0][0]);

        if (type == 1) {
            updateBoard(dir, y, x, temp_board);
        } else if (type == 2) {
            updateBoard(dir, y, x, temp_board);
            updateBoard((dir+2)%4, y, x, temp_board);
        } else if (type == 3) {
            updateBoard(dir, y, x, temp_board);
            updateBoard((dir+1)%4, y, x, temp_board);
        } else if (type == 4) {
            updateBoard(dir, y, x, temp_board);
            updateBoard((dir+1)%4, y, x, temp_board);
            updateBoard((dir+2)%4, y, x, temp_board);
        } else if (type == 5) {
            updateBoard(dir, y, x, temp_board);
            updateBoard((dir+1)%4, y, x, temp_board);
            updateBoard((dir+2)%4, y, x, temp_board);
            updateBoard((dir+3)%4, y, x, temp_board);
        }
        find_MinNum(index + 1, temp_board);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] >= 1 && board[i][j] <= 5)
                CCTV.push_back({board[i][j], {i, j}});
        }
    } 
    find_MinNum(0, board);
    cout << min_cnt;
    return 0;
}