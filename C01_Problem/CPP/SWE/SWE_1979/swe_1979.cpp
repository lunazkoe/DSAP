#include <iostream>
using namespace std;

int N, K;
int board[20][20];
int vis1[20][20];
int vis2[20][20];

int search1(int x, int y, int K) {
    
    int cnt = 1;
    while (true) {
        int nx = x;
        int ny = y + 1;
        if (ny >= N || board[nx][ny] == 0) break;
        if (board[nx][ny] == 1) cnt++;
        vis1[nx][ny] = 1;
        x = nx;
        y = ny;
    }

    if (cnt == K) return 1;
    else return 0;
}

int search2(int x, int y, int K) {

    int cnt = 1;
    while (true) {
        int nx = x + 1;
        int ny = y;
        if (nx >= N || board[nx][ny] == 0) break;
        if (board[nx][ny] == 1) cnt++;
        vis2[nx][ny] = 1;
        x = nx;
        y = ny;
    }

    if (cnt == K) return 1;
    else return 0;
}

int func() {
    cin >> N >> K;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            cin >> board[x][y];
            vis1[x][y] = 0;
            vis2[x][y] = 0;
        }
    }

    int sum = 0;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if (board[x][y] == 1 && !vis1[x][y]) {
                vis1[x][y] = 1;
                sum += search1(x, y, K);
            }

            if (board[x][y] == 1 && !vis2[x][y]) {
                vis2[x][y] = 1;
                sum += search2(x, y, K);
            }
        }
    }

    return sum;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "#" << t << " " << func() << '\n';
    }

    return 0;
}