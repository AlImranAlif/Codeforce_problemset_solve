#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll max_subarray_sum(const vector<ll> &a) {
    ll n = a.size();
    ll ans = a[0];
    ll cur = a[0];
    for (ll i = 1; i < n; i++) {
        cur = max(a[i], cur + a[i]);
        ans = max(ans, cur);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        if (k % 2 == 0) {
            cout << max_subarray_sum(a) << "\n";
        } else {
            ll M = max_subarray_sum(a);
            vector<ll> left(n), right(n);
            left[0] = a[0];
            for (int i = 1; i < n; i++) {
                left[i] = max(a[i], left[i-1] + a[i]);
            }
            right[n-1] = a[n-1];
            for (int i = n-2; i >= 0; i--) {
                right[i] = max(a[i], right[i+1] + a[i]);
            }   
            ll ans = M;
            for (int i = 0; i < n; i++) {
                ll H = left[i] + right[i] - a[i];
                ans = max(ans, H + b[i]);
            }
            cout << ans << "\n";
        }
    }
    return 0;
}