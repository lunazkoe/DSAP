#include <iostream>
#include <vector>
using namespace std;

int mx_func(int a, int b) {
    if (a > b) return a;
    else return b;
}

int mn_func(int a, int b) {
    if (a > b) return b;
    else return a;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int T = 1; T <= 3; T++) {
        int N;
        cin >> N;
        int sum = 0;
        vector<int> V(N);
        for (int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            V[i] = tmp;
        }

        for (int i = 2; i < N - 2; i++) {
            // 왼쪽 탐색
            int l1 = V[i-1];
            int l2 = V[i-2];
            if (l1 >= V[i] || l2 >= V[i]) continue;
            
        
            // 오른쪽 탐색
            int r1 = V[i+1];
            int r2 = V[i+2];
            if (r1 >= V[i] || r2 >= V[i]) continue;
            
            // 조망권이 확보된 세대
            int l_mx = V[i] - mx_func(l1, l2);
            int r_mx = V[i] - mx_func(r1, r2);

            sum += mn_func(l_mx, r_mx);
        }

        cout << "#" << T << " " << sum << '\n';
    }

    return 0;
}