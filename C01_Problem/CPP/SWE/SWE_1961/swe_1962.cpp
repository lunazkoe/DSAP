#include <iostream>
using namespace std;

int board[10][10];
int b1[10][10];
int b2[10][10];
int b3[10][10];

void func() {
    int N;
    cin >> N;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            cin >> board[x][y]; 
        }
    }

    // 90
    for (int y = 0, i = 0; y < N && i < N; y++, i++) {
        for (int x = N - 1, j = 0; x >= 0 && j < N; x--, j++) {
            b1[i][j] = board[x][y];
        }
    }

    // 180
    for (int x = N - 1, i = 0; x >= 0 && i < N; x--, i++) {
        for (int y = N - 1, j = 0; y >= 0 && j < N; y--, j++) {
            b2[i][j] = board[x][y];
        }
    }

    // 270
    for (int y = N - 1, i = 0; y >= 0 && i < N; y--, i++) {
        for (int x = 0, j = 0; x < N && j < N; x++, j++) {
            b3[i][j] = board[x][y];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << b1[i][j];
        }
        cout << " ";
        for (int j = 0; j < N; j++) {
            cout << b2[i][j];
        }
        cout << " ";
        for (int j = 0; j < N; j++) {
            cout << b3[i][j];
        }
        cout << '\n';
    }
}

int main(void) {

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "#" << t << '\n';
        func();
    }

    return 0;
}