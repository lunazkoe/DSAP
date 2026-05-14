#include <iostream>
#include <string>
using namespace std;

string func(string i) {
    string output = "";
    for (char& c : i) {
        if (c == '3' || c == '6' || c == '9') {
            output += "-";
        }
    }
    if (output == "") return i;
    return output;
}

void print369(int i) {
    int cnt = 0;
    int tmp = i;
    while (tmp > 0) {
        int digit = tmp % 10;
        tmp /= 10;
        if (digit != 0 && (digit == 3 || digit == 6 || digit == 9)) cnt++;
    }

    if (cnt != 0) {
        for (int k = 0; k < cnt; k++) {
            cout << "-";
        }
        cout << ' ';
    } else {
        cout << i << ' ';
    }
}

int main(void) {
    
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        // cout << func(to_string(i)) << " ";
        print369(i);
    }

    return 0;
}
