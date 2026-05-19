#include <iostream>
using namespace std;

int board[100][100];

int func() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    
}

int main(void) {

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "#" << t << " " << func() << '\n';
    }

    return 0;
}