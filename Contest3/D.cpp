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
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        vector<int> S = a;
        S.erase(unique(S.begin(), S.end()), S.end()); 
        vector<bool> needed(k + 1, false);
        vector<int> candidates;
        for (int x : S) {
            bool valid = true;
            for (int m = x; m <= k; m += x) {
                if (!binary_search(S.begin(), S.end(), m)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                candidates.push_back(x);
            }
        }  
        sort(candidates.begin(), candidates.end());
        vector<bool> covered(S.size(), false);
        vector<int> B;
        reverse(candidates.begin(), candidates.end());
        for (int cand : candidates) {
            bool useful = false;
            for (int i = 0; i < S.size(); i++) {
                if (!covered[i] && S[i] % cand == 0) {
                    useful = true;
                    break;
                }
            }
            if (useful) {
                B.push_back(cand);
                for (int i = 0; i < S.size(); i++) {
                    if (!covered[i] && S[i] % cand == 0) {
                        covered[i] = true;
                    }
                }
            }
        }
        bool all_covered = true;
        for (bool cov : covered) {
            if (!cov) {
                all_covered = false;
                break;
            }
        }
        if (!all_covered) {
            cout << -1 << "\n";
        } else {
            cout << B.size() << "\n";
            sort(B.begin(), B.end());
            for (int b : B) cout << b << " ";
            cout << "\n";
        }
    }
    return 0;
}