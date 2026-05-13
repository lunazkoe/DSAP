#include <iostream>
#include <stack>
using namespace std;

int t;
int board[102][102];
int vis[102][102];
int dx[] = {0, 0, -1};
int dy[] = {-1, 1, 0};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int T = 0; T < 2; T++) {
        cin >> t;
        stack<pair<int, int>> S;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> board[i][j];
                vis[i][j] = 0;
                if (board[i][j] == 2) {
                    S.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        int answer = -99;
        int nx, ny;
        pair<int, int> cur = S.top(); S.pop();
        while (true) {
            nx = cur.first + dx[0];
            ny = cur.second + dy[0];
            if (!(nx < 0 || nx >= 100 || ny < 0 || ny >= 100) && (board[nx][ny] == 1) && !vis[nx][ny]) {
                cur.first = nx;
                cur.second = ny;
                vis[nx][ny] = 1;
                continue;
            }

            nx = cur.first + dx[1];
            ny = cur.second + dy[1];
            if (!(nx < 0 || nx >= 100 || ny < 0 || ny >= 100) && (board[nx][ny] == 1) && !vis[nx][ny]) {
                cur.first = nx;
                cur.second = ny;
                vis[nx][ny] = 1;
                continue;
            }

            nx = cur.first + dx[2];
            ny = cur.second + dy[2];
            if (nx < 0) {
                answer = ny;
                break;
            }

            if (!(nx < 0 || nx >= 100 || ny < 0 || ny >= 100) && (board[nx][ny] == 1) && !vis[nx][ny]) {
                cur.first = nx;
                cur.second = ny;
                vis[nx][ny] = 1;
                continue;
            }
        }

        cout << "#" << t << " " << answer << '\n';
    }

    return 0;
}