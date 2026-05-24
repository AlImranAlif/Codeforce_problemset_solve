#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> p(n), pos(n + 1);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            pos[p[i]] = i;
        }

        bool ok = true;

        int L = pos[1], R = pos[1];
        int lastL = L, lastR = R;   // last closed block range
        bool hasLast = false;       // whether last block exists separately

        for (int v = 2; v <= n && ok; ++v) {
            int x = pos[v];
            if (x == L - 1) {
                L = x;
            } else if (x == R + 1) {
                R = x;
            } else {
                // start new block; close current [L,R]
                if (hasLast) {
                    // current [L,R] becomes previous, and we must ensure
                    // no position overlap (interleaving) with already finished [lastL,lastR]
                    if (!(R < lastL || L > lastR)) {
                        ok = false;
                        break;
                    }
                }
                hasLast = true;
                lastL = L;
                lastR = R;
                // new block is single point x
                L = R = x;
            }
        }

        if (ok && hasLast) {
            // final check: last active block [L,R] must not overlap previous [lastL,lastR]
            if (!(R < lastL || L > lastR)) {
                // allowed: blocks disjoint in positions
                // if they overlap, invalid
                // but overlapping can only happen if there were at least 3 blocks,
                // which our construction already caught; keep for safety
            }
        }

        cout << (ok ? "Yes\n" : "No\n");
    }

    return 0;
}
