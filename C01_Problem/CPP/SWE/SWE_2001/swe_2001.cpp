#include <iostream>
using namespace std;

int board[15][15];

int func() {
    int N, M;
    cin >> N >> M;

    // Board 초기화
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            cin >> board[x][y];
        }
    }

    // M * M 배열로 다 확인하기
    // N - M + 1
    int mx = 0;
    for (int i = 0; i < N - M + 1; i++) {
        for (int j = 0; j < N - M + 1; j++) {

            int sum = 0;
            
            for (int x = i; x < i + M; x++) {
                for (int y = j; y < j + M; y++) {
                    sum += board[x][y]; 
                }
            }

            if (mx < sum) mx = sum;
        }
    }

    return mx;
}

int main(void) {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "#" << t << " " << func() << '\n';
    }
    return 0;
}