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
        int m = 0;
        int last = -1; 
        for (int i = 0; i < n; ++i) {
            if ((a[i] ^ b[i]) == 1) {
                ++m;
                last = i;
            }
        }
        if (m == 0 || (m % 2 == 0)) {
            cout << "Tie\n";
        } else {
            int idx1 = last + 1; 
            if (idx1 % 2 == 1) cout << "Ajisai\n";
            else cout << "Mai\n";
        }
    }
    return 0;
}
