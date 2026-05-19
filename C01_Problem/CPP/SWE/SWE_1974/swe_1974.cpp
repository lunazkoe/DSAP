#include <iostream>
using namespace std;

int board[9][9];
int arr[10];

int func() {
    // Phase 1
    for (int i = 0; i < 9; i++) {
        
        for (int j = 1; j < 10; j++) {
            arr[j] = 1;
        }
        
        for (int j = 0; j < 9; j++) {
          if (arr[board[i][j]] == 0) return 0;
            arr[board[i][j]]--;
        }            
    }

    // Phase 2
    for (int i = 0; i < 9; i++) {

        for (int j = 1; j < 10; j++) {
            arr[j] = 1;
        }

        for (int j = 0; j < 9; j++) {
          if (arr[board[j][i]] == 0) return 0;
            arr[board[j][i]]--;
        }
    }

    // Phase 3
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            for (int k = 1; k < 10; k++) {
                arr[k] = 1;
            }

            for (int x = i; x < i + 3; x++) {
                for (int y = j; y < j + 3; y++) {
                    if (arr[board[x][y]] == 0) return 0;
                    arr[board[x][y]]--;
                }
            }
        }
    }

    return 1;
}

int main(void) {

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> board[i][j];
            }
        }
        
        cout << "#" << i << " " << func() << '\n';
    }

    return 0;
}