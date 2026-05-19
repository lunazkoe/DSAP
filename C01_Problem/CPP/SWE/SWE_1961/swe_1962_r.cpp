#include <iostream>
using namespace std;

int board[10][10];
int tmp[10][10];

void rotate90(int N) {
    for (int y = 0, i = 0; y < N && i < N; y++, i++) {
        for (int x = N - 1, j = 0; x >= 0 && j < N; x--, j++) {
            tmp[i][j] = board[x][y];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = tmp[i][j];
        }
    }
}

void func() {   
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            cin >> board[i][j];

    int b1[10][10], b2[10][10], b3[10][10];

    rotate90(N);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) b1[i][j] = board[i][j];

    rotate90(N);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) b2[i][j] = board[i][j];

    rotate90(N);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) b3[i][j] = board[i][j];

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