#include <iostream>
using namespace std;

int func() {
    int scores[105] = {0, };

    for (int i = 0; i < 1000; i++) {
        int score;
        cin >> score;
        scores[score]++;
    }

    int mxscore = -1;
    int mxcount = -1;
    for (int i = 0; i <= 100; i++) {
        if (scores[i] >= mxcount) {
            mxscore = i;
            mxcount = scores[i];
        }
    }

    return mxscore;
}

int main(void) {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int t;
        cin >> t;

        cout << "#" << t << " " << func() << '\n';
    }

    return 0;
}