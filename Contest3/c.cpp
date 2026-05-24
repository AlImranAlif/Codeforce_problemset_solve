
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        unordered_set<int> S_set(a.begin(), a.end());
        vector<int> S_list(S_set.begin(), S_set.end());
        sort(S_list.begin(), S_list.end());
        unordered_map<int, bool> covered;
        for (int num : S_list) covered[num] = false;
        vector<int> B;
        for (int x : S_list) {
            if (covered[x]) continue;
            long long cnt = k / x;  
            if (cnt > n) continue;  
            bool valid = true;
            for (int m = x; m <= k; m += x) {
                if (S_set.find(m) == S_set.end()) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                B.push_back(x);
                for (int m = x; m <= k; m += x) {
                    auto it = S_set.find(m);
                    if (it != S_set.end()) {
                        covered[m] = true;
                    }
                }
            }
        }
        bool ok = true;
        for (int num : S_list) {
            if (!covered[num]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "-1\n";
        } else {
            cout << B.size() << '\n';
            for (int b : B) cout << b << ' ';
            cout << '\n';
        }
    }
    return 0;
}
