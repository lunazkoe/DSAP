#include <bits/stdc++.h>
using namespace std;

int board[50][50];
int dist[50][50];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int func() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char tmp;
            cin >> tmp;
            board[i][j] = tmp - '0';
            dist[i][j] = 0;
        }
    }

    queue<pair<int, int>> Q;


    int s = N / 2;

    dist[s][s] = 1;
    Q.push({s, s});


    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (dist[nx][ny] > 0) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx, ny});
        }
    }

    int goal = (N - 1) / 2 + 1;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dist[i][j] <= goal) {
                sum += board[i][j];
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
