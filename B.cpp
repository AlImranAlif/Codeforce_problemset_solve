#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        long long first = a[0];
        long long last = a[n-1];
        if(first == -1 && last == -1) {
            first = last = 0;
        } 
        else if(first == -1) {
            first = last; 
        } 
        else if(last == -1) {
            last = first;
        }
        a[0] = first;
        a[n-1] = last;
        for(int i=1; i<n-1; i++) {
            if(a[i] == -1) a[i] = 0;
        }
        long long ans = llabs(last - first);
        cout << ans << "\n";
        for(long long x : a) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
