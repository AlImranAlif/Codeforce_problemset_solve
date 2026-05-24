#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool is_palindrome(const string &s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

string flip(const string &s, int l, int r) {
    string res = s;
    for (int i = l; i <= r; i++) {
        res[i] = (s[i] == '0' ? '1' : '0');
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        if (s == t) {
            cout << 0 << endl;
            continue;
        }
        vector<pair<int, int>> operations;
        string current = s;
        int i = 0;
        bool success = true;
        while (i < n) {
            if (current[i] == t[i]) {
                i++;
            } else {
                bool found = false;
                for (int l = 0; l < n; l++) {
                    for (int r = l + 1; r < n; r++) {
                        if (is_palindrome(current, l, r)) {
                            operations.push_back({l + 1, r + 1});
                            current = flip(current, l, r);
                            found = true;
                            i = 0;
                            break;
                        }
                    }
                    if (found) break;
                }
                if (!found) {
                    success = false;
                    break