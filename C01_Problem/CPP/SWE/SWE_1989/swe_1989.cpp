#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int t;

int isPalindrome(string& str) {
    char* first = &str[0];
    char* last = &str[str.size()-1];

    while (first <= last) {
        if (*first != *last) return 0;
        first++;
        last--;
    }
    return 1;
}

int main(void) {
    cin >> t;

    // 직접 구현하기
    for (int i = 1; i <= t; i++) {
        string str;
        cin >> str;
        cout << "#" << i << " " << isPalindrome(str) << '\n';
    }

    // cpp algorithm reverse(begin(), end()) 사용해서 풀기
    // for (int i = 1; i <= t; i++) {
    //     string str;
    //     cin >> str;
    //     string origin = str;
    //     reverse(str.begin(), str.end());
    //     if (origin == str) {
    //         cout << 1 << '\n';
    //     } else {
    //         cout << 0 << '\n';
    //     }
    // }

    return 0;
}