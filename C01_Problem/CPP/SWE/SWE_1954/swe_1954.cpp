#include <iostream>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void func() {
    int N;
    cin >> N;

    int board[11][11] = {0, };

    board[0][0] = 1;
    int curx = 0;
    int cury = 0;

    int dir = 0;
    int cnt = 2;
    while (true) {
        int nx = curx + dx[dir % 4];
        int ny = cury + dy[dir % 4];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[nx][ny] != 0) {
            dir = (dir + 1) % 4;
            nx = curx + dx[dir % 4];
            ny = cury + dy[dir % 4];
        }

        board[nx][ny] = cnt++;
        if (cnt > N * N) break;
        curx = nx;
        cury = ny;
    }

    // for (int i = 2; i <= cnt * cnt; i++) {

    // }

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            cout << board[x][y] << " ";
        }
        cout << '\n';
    }
}

int main(void) {

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cout << "#" << t << " " << '\n';
        func();
    }

    return 0;
}