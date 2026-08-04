#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(2 * n);
        map<int, int> freq;
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        int A = 0;
        vector<int> B;
        for (auto &p : freq) {
            if (p.second % 2 == 1) {
                A++;
            } else {
                B.push_back(p.second);
            }
        }
        vector<int> V;
        for (int f : B) {
            V.push_back(f - 1);
        }
        sort(V.begin(), V.end());
        int m = V.size();
        vector<int> prefix(m + 1, 0);
        for (int i = 0; i < m; i++) {
            prefix[i + 1] = prefix[i] + V[i];
        }
        int k_max = 0;
        for (int k = 1; k <= m; k++) {
            int L_min = prefix[k];
            if (L_min > 2 * n - k) {
                continue;
            }
            if (L_min < n) {
                k_max = k;
            } else {
                if (L_min <= 2 * n - k - 1) {
                    k_max = k;
                } else if ((n % 2) == (k % 2)) {
                    k_max = k;
                }
            }
        }
        cout << A + 2 * k_max << "\n";
    }
    return 0;
}