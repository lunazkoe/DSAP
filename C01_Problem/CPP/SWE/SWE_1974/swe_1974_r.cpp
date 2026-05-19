#include <iostream>
using namespace std;

int board[9][9];

int func() {
    int row[9][10] = {false};
    int col[9][10] = {false};
    int box[9][10] = {false};

    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {

            int num = board[x][y];

            int b = (x / 3) * 3 + (y / 3);

            if (row[x][num] || col[y][num] || box[b][num]) {
                return 0;
            }

            row[x][num] = true;
            col[y][num] = true;
            box[b][num] = true;
        }
    }

    return 1;
}

int main(void) {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                cin >> board[r][c];
            }
        }
        cout << "#" << t << " " << func() << '\n';
    }

    return 0;
}