#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        int A = 0, B = 0;
        for (int x : a) A ^= x;
        for (int x : b) B ^= x;
        int C = A ^ B;
        if (C == 0) {
            cout << "Tie\n";
            continue;
        }
        int k = -1;
        for (int bit = 30; bit >= 0; --bit) {
            if ((C >> bit) & 1) {
                k = bit;
                break;
            }
        }
        int last = -1;
        for (int i = n - 1; i >= 0; --i) {
            int di = a[i] ^ b[i];
            if (((di >> k) & 1) == 1) {
                last = i;
                break;
            }
        }
        if (last == -1) {
            cout << "Tie\n";
            continue;
        }
        if ((last % 2) == 0) cout << "Ajisai\n";
        else cout << "Mai\n";
    }
    return 0;
}
