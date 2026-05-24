#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string r;
        cin >> r;
        int n = r.size();
        for (char c : r) {
            assert(c == 's' || c == 'u');
        }
        int ans = 0;
        for (int i = 0; i < n; ) {
            if (r[i] == 'u') {
                int j = i;
                while (j < n && r[j] == 'u') j++;
                int len = j - i;
                bool leftS = (i > 0 && r[i - 1] == 's');
                bool rightS = (j < n && r[j] == 's');
                int keep = 0;
                if (leftS && rightS) {
                    keep = 1;
                } else if (leftS || rightS) {
                    keep = len / 2;
                } else {
                    keep = (len - 1) / 2;
                }
                ans += (len - keep);
                i = j;
            } else {
                i++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
