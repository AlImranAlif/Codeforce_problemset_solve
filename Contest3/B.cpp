#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        vector<ll> minB(2), maxB(2);
        minB[0] = 0; maxB[0] = 0;
        minB[1] = INF; maxB[1] = -INF;
        for (int i = 1; i <= n; i++) {
            vector<ll> new_minB(2, INF), new_maxB(2, -INF);
            if (minB[0] <= maxB[0]) {
                new_minB[0] = min(new_minB[0], minB[0] - a[i]);
                new_maxB[0] = max(new_maxB[0], maxB[0] - a[i]);
            }
            if (minB[1] <= maxB[1]) {
                new_minB[0] = min(new_minB[0], b[i] - maxB[1]);
                new_maxB[0] = max(new_maxB[0], b[i] - minB[1]);
            }
            if (minB[1] <= maxB[1]) {
                new_minB[1] = min(new_minB[1], minB[1] - a[i]);
                new_maxB[1] = max(new_maxB[1], maxB[1] - a[i]);
            }
            if (minB[0] <= maxB[0]) {
                new_minB[1] = min(new_minB[1], b[i] - maxB[0]);
                new_maxB[1] = max(new_maxB[1], b[i] - minB[0]);
            }
            minB = move(new_minB);
            maxB = move(new_maxB);
        }
        ll ans = max(maxB[0], maxB[1]);
        cout << ans << "\n";
    }
    return 0;
}