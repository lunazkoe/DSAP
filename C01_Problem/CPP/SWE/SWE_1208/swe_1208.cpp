#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BOARD_SIZE = 100;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int T = 1; T <= 10; T++) {

        // 덤프 횟수 입력
        int N;
        cin >> N;
        
        // 각 상자의 높이 입력
        vector<int> V(BOARD_SIZE);
        for (int i = 0; i < BOARD_SIZE; i++) {
            cin >> V[i];
        }

        for (int i = 0; i < N; i++) {
            auto mx_it = max_element(V.begin(), V.end());
            auto mn_it = min_element(V.begin(), V.end());

            if (*mx_it - *mn_it < 1) continue;

            (*mx_it)--;
            (*mn_it)++;
        }

        auto mx_val = *max_element(V.begin(), V.end());
        auto mn_val = *min_element(V.begin(), V.end());

        cout << "#" << T << " " << mx_val - mn_val << '\n';

    }

    return 0;
}