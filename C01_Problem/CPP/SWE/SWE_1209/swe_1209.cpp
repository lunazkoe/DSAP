#include <iostream>
using namespace std;

int board[100][100];

int func() {
    int t;
    cin >> t;

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cin >> board[i][j];
        }
    }

    int mx = 0;

    for (int i = 0; i < 100; i++) {
        int sum = 0;
        for (int j = 0; j < 100; j++) {
            sum += board[i][j];
        }
        if (sum >= mx) mx = sum;
    }

    for (int j = 0; j < 100; j++) {
        int sum = 0;
        for (int i = 0; i < 100; i++) {
            sum += board[i][j];
        }
        if (sum >= mx) mx = sum;
    }

    int ax = 0;
    for (int i = 0; i < 100; i++) {
        ax += board[i][i];
    }
    if (ax >= mx) mx = ax;

    int bx = 0;
    for (int i = 99; i >= 0; i--) {
        bx += board[i][i];
    }
    if (bx >= mx) mx = bx;

    cout << "#" << t << " " << mx << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int t = 1; t <= 10; t++) {
        func();
    }

    return 0;
}